#include <stdio.h>

#include "maxwells.h"
#include "graphics.h"
#include "calculus.h"
#include "particle.h"
#include "physics.h"
#include "newton.h"
#include "vector.h"

struct particle ions[N_IONS];

void init_physics()
{
	int i;
	for(i=0;i<N_IONS;i++){
		ions[i].l.x=0;
		ions[i].l.y=(i*5);
		ions[i].l.z=0;
		ions[i].mass=1;
		ions[i].charge=-500;
		ions[i].velocity=(struct vector){i*0.03,0,0};
	}
	ions[0].mass=100000000;
	ions[0].charge=10000*N_IONS;
}

void dump_state()
{
	int i;
	printf("--- IONS ---\n");
	for(i=0;i<N_IONS;i++){
		printf("[%i]\n",i);
		v_print("location",ions[i].l);
		v_printe("velocity",ions[i].velocity);
	}
	printf("-----------\n");
}


void velocity(struct particle * p)
{
	struct vector v,fv = {0,0,0};
	int i;
	for(i=0;i<N_IONS;i++){
		v = gravitation(ions[i],*p);
		fv = v_add(v,fv);
		v = coulombs(ions[i],*p);
		fv = v_add(v,fv);
		v = biotsavart(ions[i],*p);
		fv = v_add(v,fv);
	}
	/* because f/m=a */
	fv.x/=p->mass;
	fv.y/=p->mass;
	fv.z/=p->mass;
	p->velocity = v_add(p->velocity,fv);
}

void apply_vel(struct particle * p)
{
	p->l = v_add(p->l,p->velocity);
}

/*TODO we need acceleration, this isn't exactly accurate*/
void tick()
{
	int i;
	for(i=0;i<N_IONS;i++)
		velocity(&ions[i]);
	for(i=0;i<N_IONS;i++)
		apply_vel(&ions[i]);
}
