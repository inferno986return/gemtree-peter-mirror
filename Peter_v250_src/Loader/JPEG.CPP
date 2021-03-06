
#include "Main.h"

/***************************************************************************\
*																			*
*							Obsluha JPEG souboru							*
*																			*
\***************************************************************************/

#ifndef _MINI

namespace JPEG
{

// v�stupn� buffer
BYTE* m_OutBuf = NULL;
BYTE* m_OutEnd = NULL;
BYTE* m_Dst = NULL;

int m_Size = 0;	// ��ta� zbyl�ch dat

// p��znak chyby operace
BOOL m_Error = FALSE;

#define JPEG_INTERNALS
#define JPEG_CJPEG_DJPEG
#define JPEG_INTERNAL_OPTIONS
#define NO_GETENV
#undef JMESSAGE

struct _iobuf { HANDLE handle; };
typedef struct _iobuf FILE;
typedef short INT16;

#define XMD_H
#undef FAR
#define INLINE __inline
#define FAST_FLOAT  double
#define JDCT_DEFAULT  JDCT_FLOAT
#define JDCT_FASTEST  JDCT_FLOAT
#define DEFAULT_MAX_MEM		1000000000L

// na�ten� bloku dat
inline DWORD JFREAD(FILE* file,void* buf,int sizeofbuf)
{
	if (sizeofbuf > m_Size) sizeofbuf = m_Size;
	FileReadBlok((BYTE*)buf, sizeofbuf);
	return sizeofbuf;
}

// z�pis bloku dat
inline DWORD JFWRITE(FILE* file,void* buf,int sizeofbuf)
{
	int n = m_OutEnd - m_Dst;
	if (sizeofbuf < n) n = sizeofbuf;
	MemCopy(m_Dst, buf, n);
	m_Dst += n;
	return n;
}

// z�pis 1 bajtu
inline int putc(int c, FILE* file)
{
	if (m_Dst < m_OutEnd)
	{
		*m_Dst = (BYTE)c;
		m_Dst++;
		return 1;
	}
	return 0;
}
	
inline BOOL fseek(FILE file,DWORD ofst,int orig) { return 0; }
inline BOOL fclose(FILE file) { return 0; }
inline FILE* tmpfile() { return NULL; }
inline int fflush(FILE* file) { return 0; }
inline int ferror(FILE* file) { return 0; }

#pragma warning ( disable: 4127)				// hl�en� - konstantn� podm�nka
#pragma warning ( disable: 4244)				// hl�en� - konverze int na WORD

#include "..\\JPEG\\jconfig.h"
#include "..\\JPEG\\jmorecfg.h"
#include "..\\JPEG\\jinclude.h"
#include "..\\JPEG\\jpeglib.h"
//#include "..\\JPEG\\jpegint.h"
#include "..\\JPEG\\jversion.h"
#include "..\\JPEG\\jerror.h"
//#include "JPEG\\jmemsys.h"
#include "..\\JPEG\\cdjpeg.h"
#include "..\\JPEG\\jdhuff.h"
#include "..\\JPEG\\jdct.h"

#include "..\\JPEG\\jdapimin.c"
#include "..\\JPEG\\jdinput.c"
#include "jdmarker.c"
#include "..\\JPEG\\jmemmgr.c"
#include "..\\JPEG\\jcomapi.c"
#include "..\\JPEG\\jutils.c"
#include "..\\JPEG\\jmemansi.c"
#include "..\\JPEG\\jerror.c"
#include "..\\JPEG\\jdatasrc.c"
#include "..\\JPEG\\wrbmp.c"
#include "..\\JPEG\\jdmaster.c"
#include "..\\JPEG\\jdmainct.c"
#include "..\\JPEG\\jdcoefct.c"
#include "..\\JPEG\\jdhuff.c"
#include "..\\JPEG\\jdphuff.c"
#include "..\\JPEG\\jddctmgr.c"
#include "..\\JPEG\\jdpostct.c"
#include "..\\JPEG\\jdsample.c"
#undef FIX
#include "..\\JPEG\\jdcolor.c"
#undef FIX
#include "..\\JPEG\\jdmerge.c"
#include "..\\JPEG\\jquant1.c"
#include "..\\JPEG\\jquant2.c"
#undef FIX
#include "..\\JPEG\\jidctflt.c"
#undef FIX
#undef CONST_BITS
#undef DEQUANTIZE
#include "..\\JPEG\\jidctfst.c"
#undef FIX
#undef DESCALE
#undef CONST_BITS
#undef DEQUANTIZE
#undef FIX_1_847759065
#undef MULTIPLY
#include "..\\JPEG\\jidctint.c"
#undef FIX
#include "..\\JPEG\\jidctred.c"
#include "..\\JPEG\\jdapistd.c"

#pragma warning ( default: 4244)				// hl�en� - konverze int na WORD
#pragma warning ( default: 4127)				// hl�en� - konstantn� podm�nka

/////////////////////////////////////////////////////////////////////////////
// dekomprese dat JPEG (vrac� TRUE=operace OK)

static const char * const cdjpeg_message_table[] = {
  NULL
};

BOOL Decomp(CBuf* outbuf)
{
	m_Error = FALSE;

// p��prava zbyl� velikosti souboru
	m_Size = 	::GetFileSize(FileReadHandle, NULL) - FileReadOff;
	if (m_Size < 0) m_Size = 0;

// lok�ln� prom�nn�
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;
	djpeg_dest_ptr dest_mgr = NULL;
	JDIMENSION num_scanlines;

// p��prava v�stupn�ho bufferu pro z�hlav� obr�zku
#define INIT_BUF_SIZE 1024

	MemFree(m_OutBuf);
	m_OutBuf = (BYTE*)MemGet(INIT_BUF_SIZE);
	if (m_OutBuf == NULL) return FALSE;
	m_OutEnd = m_OutBuf + INIT_BUF_SIZE;
	m_Dst = m_OutBuf;

// vytvo�en� objektu dekomprese
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);
	if (m_Error) { MemFree(m_OutBuf); m_OutBuf = NULL; return FALSE; }

	jerr.addon_message_table = cdjpeg_message_table;
	jerr.first_addon_message = 0;
	jerr.last_addon_message = 0;

// nastaven� parametr� dekomprese
	cinfo.err->trace_level = 0;
	cinfo.dct_method = JDCT_FLOAT;
	cinfo.dither_mode = JDITHER_NONE;

// inicializace zdroje dat
	jpeg_stdio_src(&cinfo, NULL);
	if (m_Error) { MemFree(m_OutBuf); m_OutBuf = NULL; return FALSE; }

// na�ten� z�hlav� obr�zku
	jpeg_read_header(&cinfo, TRUE);
	if (m_Error) { MemFree(m_OutBuf); m_OutBuf = NULL; return FALSE; }

// nastaven� nov� velikosti v�stupn�ho bufferu
	int s = m_Dst - m_OutBuf;
	int n = INIT_BUF_SIZE + cinfo.image_width*cinfo.image_height*4;
	BYTE* bf = (BYTE*)MemSize(m_OutBuf, n);
	if (bf == NULL) { MemFree(m_OutBuf); m_OutBuf = NULL; return FALSE; }
	m_OutBuf = bf;
	m_OutEnd = m_OutBuf + n;
	m_Dst = m_OutBuf + s;

// z�pis z�hlav� obr�zku
	dest_mgr = jinit_write_bmp(&cinfo, FALSE);
	dest_mgr->output_file = NULL;

// zah�jen� dekomprese
	jpeg_start_decompress(&cinfo);
	if (m_Error) { MemFree(m_OutBuf); m_OutBuf = NULL; return FALSE; }

// zah�jen� v�stupu
	(*dest_mgr->start_output) (&cinfo, dest_mgr);

// dekomprese dat obr�zku
	while (cinfo.output_scanline < cinfo.output_height) 
	{
		num_scanlines = jpeg_read_scanlines(&cinfo, dest_mgr->buffer,
						dest_mgr->buffer_height);
		if (m_Error) { MemFree(m_OutBuf); m_OutBuf = NULL; return FALSE; }

		(*dest_mgr->put_pixel_rows) (&cinfo, dest_mgr, num_scanlines);
		if (m_Error) { MemFree(m_OutBuf); m_OutBuf = NULL; return FALSE; }
	}

// ukon�en� v�stupu
	(*dest_mgr->finish_output) (&cinfo, dest_mgr);
	if (m_Error) { MemFree(m_OutBuf); m_OutBuf = NULL; return FALSE; }

// ukon�en� dekomprese
	(void) jpeg_finish_decompress(&cinfo);
	if (m_Error) { MemFree(m_OutBuf); m_OutBuf = NULL; return FALSE; }

// zru�en� objektu dekomprese
	jpeg_destroy_decompress(&cinfo);
	if (m_Error) { MemFree(m_OutBuf); m_OutBuf = NULL; return FALSE; }

// nastaven� v�stupn�ho bufferu
	outbuf->AdrSize(m_OutBuf, m_Dst - m_OutBuf);
	m_OutBuf = NULL;

	return TRUE;
}



}

#endif // _MINI
