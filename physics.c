#include <stdio.h>

#include "maxwells.h"
#include "graphics.h"
#include "calculus.h"
#include "particle.h"
#include "physics.h"
#include "newton.h"
#include "vector.h"

#define N_IONS 2

struct particle ions[N_IONS];

void init_physics()
{
	int i;
	for(i=0;i<N_IONS;i++){
		ions[i].l.x=0;
		ions[i].l.y=(i*25);
		ions[i].l.z=0;
		ions[i].mass=1000000;
		ions[i].charge=100;
		ions[i].velocity=(struct vector){(i*.000001),0,0};
	}
}

void dump_state()
{
	int i;
	printf("--- IONS ---\n");
	for(i=0;i<N_IONS;i++){
		printf("[%i]\n",i);
		v_print("location",ions[i].l);
		v_print("velocity",ions[i].velocity);
	}
	printf("-----------\n");
}

void draw_state()
{
	/*clear the screen*/
	cr=0;cb=0;cg=0;
	draw_rectangle(0,0,1366,768);

	int i;
	cg=0x99; 
	for(i=0;i<N_IONS;i++){
		cr=0x99 - ions[i].charge;
		cb=0x99 + ions[i].charge;

		box((int)ions[i].l.x,(int)ions[i].l.y);
	}
}

void velocity(struct particle * p)
{
	struct vector v,fv = {0,0,0};
	int i;
	for(i=0;i<N_IONS;i++){
		v = gravitation(ions[i],*p);
		v_print("gravitation",v);
		fv = v_add(v,fv);
		v = coulombs(ions[i],*p);
		v_print("coulombs",v);
		fv = v_add(v,fv);
		v = biotsavart(ions[i],*p);
		v_print("biotsavart",v);
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

/*TODO we need acceleration, as this isn't exactly accurate*/
void tick()
{
	int i;
	for(i=0;i<N_IONS;i++)
		velocity(&ions[i]);
	for(i=0;i<N_IONS;i++)
		apply_vel(&ions[i]);
}
