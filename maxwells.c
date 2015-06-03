#include <math.h>
#include <stdio.h>

#include "vector.h"
#include "maxwells.h"

const double ke = 8.987551E-9; /* Coulomb's constant */
const double e0 = 8.854187E-12;/* permittivity of free space */
const double u0 = 1.256637E-6; /* permeability of free space */

/* F = q(E + (v X B)) */
struct vector lorentz(int q, struct vector v, struct vector E, struct vector B)
{
	struct vector F;
	F = v_add(E,v_cross(v,B));
	F = v_scalar_mul(q,F);
	return F;
}

struct vector coulombs(struct particle a, struct particle b)
{
	struct vector E = {0,0,0};
	double q = a.charge*b.charge;
	struct vector u = v_displacement(a.l,b.l);
	struct vector r = v_sub(b.l,a.l);

	if(r.x)
		E.x = ke * (q / (r.x*r.x)) * u.x;
	if(r.y)
		E.y = ke * (q / (r.y*r.y)) * u.y;
	if(r.z)
		E.z = ke * (q / (r.z*r.z)) * u.z;

	return E;
}

struct vector biotsavart(struct particle p1, struct particle p2)
{
	struct vector B;
	struct vector r;
	double q;
	struct vector u = v_displacement(p1.l,p2.l);
	r = v_sub(p2.l,p1.l);
	r.x*=r.x;
	r.y*=r.y;
	r.z*=r.z;
	if(r.x)
		r.x = u.x/r.x;
	if(r.y)
		r.y = u.y/r.y;
	if(r.z)
		r.z = u.z/r.z;

	q = p1.charge + p2.charge;
	q*=u0/(4*M_PI);

	B.x = q*p2.velocity.x;
	B.y = q*p2.velocity.y;
	B.z = q*p2.velocity.z;

	B = v_cross(r,B);

	return B;
}
