#ifndef MAXWELLS
#define MAXWELLS

const double e = 8.854187E-12;/* permittivity of free space */
const double u = 1.256637E-6; /* permeability of free space */

/* F = q(E + (v X B)) */
inline int lorentz(int q, struct vector v, struct vector E, struct vector B)
{
	struct vector F; /*force*/
	F = v_add(E,cross(v,B));
	F = v_scalar_mul(q,F);
	return F;
}

#endif
