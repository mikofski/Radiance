/* RCSid $Id: otspecial.h,v 2.8 2018/01/09 05:01:15 greg Exp $ */
/*
 * Special type flags for objects used in rendering.
 * Depends on definitions in otypes.h
 */
#ifndef _RAD_OTSPECIAL_H_
#define _RAD_OTSPECIAL_H_
#ifdef __cplusplus
extern "C" {
#endif

		/* flag for nominally transparent materials */
#define  T_TRANSP	T_SP1

		/* flag for completely opaque materials */
#define  T_OPAQUE       T_SP2

#define  istransp(t)	(ofun[t].flags & T_TRANSP)

#define  isopaque(t)    (ofun[t].flags & T_OPAQUE)

		/* test if we have a BSDF proxy surface */
#define isBSDFproxy(m)	((m)->otype == MAT_BSDF && (m)->oargs.nsargs && \
				strcmp((m)->oargs.sarg[0], "0"))

#ifdef __cplusplus
}
#endif
#endif /* _RAD_OTSPECIAL_H_ */

