#include <stdio.h>
#include "particle.h"
#include "physics.h"
#include "newton.h"
#include "vector.h"

#define N_IONS 3

struct particle ions[N_IONS];

void init_physics()
{
	int i;
	for(i=0;i<N_IONS;i++){
		ions[i].l.x=800+(i*25);
		ions[i].l.y=150;
		ions[i].mass=1000;
		ions[i].velocity=(struct vector){0,0,0};
	}
}

void dump_state()
{
	int i;
	for(i=0;i<N_IONS;i++){
		printf("ions[%i]: \n",i);
		printf(" .x: %f \n",ions[i].l.x);
		printf(" .y: %f \n",ions[i].l.y);
		printf(" .z: %f \n",ions[i].l.z);
	}
}

void velocity(struct particle * p)
{
	struct vector v,fv = {0,0,0};
	int i;
	for(i=0;i<N_IONS;i++){
		v = gravitation(ions[i],*p);
		fv = add(v,fv);
	}
	/* because f/m=a */
	fv.x/=p->mass;
	fv.y/=p->mass;
	fv.z/=p->mass;
	p->velocity = add(p->velocity,fv);
}

void apply_vel(struct particle * p)
{
	p->l = add(p->l,p->velocity);
}

void tick()
{
	int i;
	for(i=0;i<N_IONS;i++)
		velocity(&ions[i]);
	for(i=0;i<N_IONS;i++)
		apply_vel(&ions[i]);
}
