#include "ion.h"
#include "graphics.h"
#include "physics.h"
#include "vector.h"

#define N_IONS 2

struct ion ions[N_IONS];

void init_physics()
{
	int i;
	for(i=0;i<N_IONS;i++){
		ions[i].x=800+(i*25);
		ions[i].y=0;
		ions[i].charge=0;
	}
}

void tick()
{
	int i;
	for(i=0;i<N_IONS;i++){
		box(ions[i].x,ions[i].y++);
	}
}
