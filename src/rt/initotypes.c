/* Copyright (c) 1990 Regents of the University of California */

#ifndef lint
static char SCCSid[] = "$SunId$ LBL";
#endif

/*
 * Initialize ofun[] list for renderers
 */

#include  "standard.h"

#include  "otypes.h"

#include  "otspecial.h"

extern int  o_sphere();
extern int  o_face();
extern int  o_cone();
extern int  o_instance();
extern int  m_light();
extern int  m_normal();
extern int  m_dielectric();
extern int  m_glass();
extern int  m_clip();
extern int  m_mirror();
extern int  m_direct();
extern int  m_brdf();
extern int  t_func(), t_data();
extern int  p_cfunc(), p_bfunc();
extern int  p_pdata(), p_cdata(), p_bdata();
extern int  mx_func(), mx_data();
extern int  text();

FUN  ofun[NUMOTYPE] = INIT_OTYPE;


initotypes()			/* initialize ofun array */
{
	ofun[OBJ_SPHERE].funp =
	ofun[OBJ_BUBBLE].funp = o_sphere;
	ofun[OBJ_FACE].funp = o_face;
	ofun[OBJ_CONE].funp =
	ofun[OBJ_CUP].funp =
	ofun[OBJ_CYLINDER].funp =
	ofun[OBJ_TUBE].funp =
	ofun[OBJ_RING].funp = o_cone;
	ofun[OBJ_INSTANCE].funp = o_instance;
	ofun[MAT_LIGHT].funp =
	ofun[MAT_ILLUM].funp =
	ofun[MAT_GLOW].funp =
	ofun[MAT_SPOT].funp = m_light;
	ofun[MAT_PLASTIC].funp =
	ofun[MAT_METAL].funp =
	ofun[MAT_TRANS].funp = m_normal;
	ofun[MAT_TRANS].flags |= T_IRR_IGN;
	ofun[MAT_DIELECTRIC].funp =
	ofun[MAT_INTERFACE].funp = m_dielectric;
	ofun[MAT_DIELECTRIC].flags |= T_IRR_IGN;
	ofun[MAT_INTERFACE].flags |= T_IRR_IGN;
	ofun[MAT_GLASS].funp = m_glass;
	ofun[MAT_GLASS].flags |= T_IRR_IGN;
	ofun[MAT_MIRROR].funp = m_mirror;
	ofun[MAT_DIRECT1].funp =
	ofun[MAT_DIRECT2].funp = m_direct;
	ofun[MAT_CLIP].funp = m_clip;
	ofun[MAT_PFUNC].funp =
	ofun[MAT_MFUNC].funp =
	ofun[MAT_PDATA].funp =
	ofun[MAT_MDATA].funp = 
	ofun[MAT_TFUNC].funp =
	ofun[MAT_BRTDF].funp = 
	ofun[MAT_TDATA].funp = m_brdf;
	ofun[TEX_FUNC].funp = t_func;
	ofun[TEX_DATA].funp = t_data;
	ofun[PAT_CFUNC].funp = p_cfunc;
	ofun[PAT_BFUNC].funp = p_bfunc;
	ofun[PAT_CPICT].funp = p_pdata;
	ofun[PAT_CDATA].funp = p_cdata;
	ofun[PAT_BDATA].funp = p_bdata;
	ofun[PAT_CTEXT].funp =
	ofun[PAT_BTEXT].funp =
	ofun[MIX_TEXT].funp = text;
	ofun[MIX_FUNC].funp = mx_func;
	ofun[MIX_DATA].funp = mx_data;
}


o_default()			/* default action is error */
{
	error(INTERNAL, "unexpected object call");
}
