
/***************************************************************************\
*																			*
*							3D rozhran� - OpenGL 1.1						*
*																			*
\***************************************************************************/

// --------------------- vypnuto pro MINI verzi --------------------
#ifndef _MINI

/////////////////////////////////////////////////////////////////////////////
// definice funkc� OpenGL 1.1

typedef	WINGDIAPI void (APIENTRY *GLARRAYELEMENT) (GLint index);
typedef WINGDIAPI void (APIENTRY *GLBINDTEXTURE) (GLenum target, GLuint texture);
typedef WINGDIAPI void (APIENTRY *GLCOLORPOINTER) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef WINGDIAPI void (APIENTRY *GLDELETETEXTURES) (GLsizei n, GLuint* textures);
typedef	WINGDIAPI void (APIENTRY *GLDISABLECLIENTSTATE) (GLenum array);
typedef	WINGDIAPI void (APIENTRY *GLDRAWARRAYS) (GLenum mode, GLint first, GLsizei count);
typedef	WINGDIAPI void (APIENTRY *GLDRAWELEMENTS) (GLenum mode, GLsizei count, GLenum type, const GLvoid* indices);
typedef	WINGDIAPI void (APIENTRY *GLENABLECLIENTSTATE) (GLenum array);
typedef WINGDIAPI void (APIENTRY *GLGENTEXTURES) (GLsizei n, GLuint* textures);
typedef WINGDIAPI void (APIENTRY *GLINDEXPOINTER) (GLenum type, GLsizei stride, const GLvoid *pointer);
typedef WINGDIAPI void (APIENTRY *GLNORMALPOINTER) (GLenum type, GLsizei stride, const GLvoid *pointer);
typedef WINGDIAPI void (APIENTRY *GLTEXCOORDPOINTER) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);
typedef WINGDIAPI void (APIENTRY *GLVERTEXPOINTER) (GLint size, GLenum type, GLsizei stride, const GLvoid *pointer);

/////////////////////////////////////////////////////////////////////////////
// funkce OpenGL 1.1

extern	GLARRAYELEMENT		pglArrayElement;
extern	GLBINDTEXTURE		pglBindTexture;
extern	GLCOLORPOINTER		pglColorPointer;
extern	GLDELETETEXTURES	pglDeleteTextures;
extern	GLDISABLECLIENTSTATE pglDisableClientState;
extern	GLDRAWARRAYS		pglDrawArrays;
extern	GLDRAWELEMENTS		pglDrawElements;
extern	GLENABLECLIENTSTATE	pglEnableClientState;
extern	GLGENTEXTURES		pglGenTextures;
extern	GLINDEXPOINTER		pglIndexPointer;
extern	GLNORMALPOINTER		pglNormalPointer;
extern	GLTEXCOORDPOINTER	pglTexCoordPointer;
extern	GLVERTEXPOINTER		pglVertexPointer;

/////////////////////////////////////////////////////////////////////////////
// inicializace rozhran� OpenGL 1.1 (vrac� TRUE=rozhran� je vytvo�eno)

bool D3GL1InitD3();
void D3GL1TermD3();

inline void D3GL1SizeView() { D3GL0SizeView(); }
inline void D3GL1MoveView() { D3GL0MoveView(); }

/////////////////////////////////////////////////////////////////////////////
// zah�jen� funkce za��zen� (vrac� TRUE=inicializace OK)
// typ za��zen�: 1=HAL,2=TnLHal,3=REF,4=RGB,5=MMX,6=Ramp,7=Null

bool D3GL1Start(int type);

/////////////////////////////////////////////////////////////////////////////
// vyrenderov�n� jednoho objektu

void D3GL1Render(D3DFITEM* item);

/////////////////////////////////////////////////////////////////////////////
// resetov�n� polo�ky textury p�ed ukon�en�m ovlada�e

void D3GL1TextureRes(D3DTITEM* item);

/////////////////////////////////////////////////////////////////////////////
// nastaven� a zapnut� textury

void D3GL1TextureSet(D3DTITEM* item, int stage);


#endif // _MINI
// --------------------- konec vypnut� pro MINI verzi -------------------
