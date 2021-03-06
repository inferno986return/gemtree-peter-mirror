
/***************************************************************************\
*																			*
*							3D rozhran� - OpenGL 2.0						*
*																			*
\***************************************************************************/

// --------------------- vypnuto pro MINI verzi --------------------
#ifndef _MINI

/////////////////////////////////////////////////////////////////////////////
// inicializace rozhran� OpenGL 2.0 (vrac� TRUE=rozhran� je vytvo�eno)

inline bool D3GL2InitD3() { return false; }
inline void D3GL2TermD3() { }

/////////////////////////////////////////////////////////////////////////////
// zah�jen� funkce za��zen� (vrac� TRUE=inicializace OK)
// typ za��zen�: 1=HAL,2=TnLHal,3=REF,4=RGB,5=MMX,6=Ramp,7=Null

inline bool D3GL2Start(int type) { return false; }
inline void D3GL2Stop() { D3GL0Stop(); }

#endif // _MINI
// --------------------- konec vypnut� pro MINI verzi -------------------
