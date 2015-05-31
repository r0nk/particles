#ifndef MAXWELLS
#define MAXWELLS
#include "vector.h"

const double ke = 8.987551E-9; /* Coulomb's constant */
const double e0 = 8.854187E-12;/* permittivity of free space */
const double u0 = 1.256637E-6; /* permeability of free space */

/* F = q(E + (v X B)) */
struct vector lorentz(int q, struct vector v, struct vector E, struct vector B)
{
	struct vector F; /* force */
	F = v_add(E,v_cross(v,B));
	F = v_scalar_mul(q,F);
	return F;
}

struct vector coulombs(struct particle p1, struct particle p2)
{
	struct vector F; 
	F.x = ke*((p1.charge+p2.charge)/(r(p1.x,p2.x)*r(p1.x,p2.x));
	F.y = ke*((p1.charge+p2.charge)/(r(p1.y,p2.y)*r(p1.y,p2.y));
	F.z = ke*((p1.charge+p2.charge)/(r(p1.z,p2.z)*r(p1.z,p2.z));
	return F;
}

/* TODO this one is a bit tricky, as it requires attention to current. */
/* we will just have to use the velocity in order to calculate */
struct vector biotsavart(struct particle p1, struct particle p2)
{
	struct vector v;
	return v;
}

#endif
