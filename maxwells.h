#ifndef MAXWELLS
#define MAXWELLS

inline int lorentz(int q, struct vector v, struct vector E, struct vector B)
{
	struct vector F;
	F = cross(v,B);
	F = v_add(F,E);
	F = v_scalar_mul(q,F);
	return F;
}

#endif
