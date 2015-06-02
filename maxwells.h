#ifndef MAXWELLS
#define MAXWELLS
#include "vector.h"
#include "particle.h"

const double ke = 8.987551E-9; /* Coulomb's constant */
const double e0 = 8.854187E-12;/* permittivity of free space */
const double u0 = 1.256637E-6; /* permeability of free space */

struct vector lorentz(int q, struct vector v, struct vector E, struct vector B);
struct vector coulombs(struct particle p1, struct particle p2);
struct vector biotsavart(struct particle p1, struct particle p2);

#endif
