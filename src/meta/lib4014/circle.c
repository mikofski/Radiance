#ifndef lint
static const char	RCSid[] = "$Id: circle.c,v 1.2 2003/11/15 02:13:37 schorsch Exp $";
#endif

#include "local4014.h"
#include "lib4014.h"

extern void
circle(
	int x,
	int y,
	int r
)
{
	arc(x,y,x+r,y,x+r,y);
}
