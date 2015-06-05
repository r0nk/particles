#include <stdio.h>

#include "graphics.h"
#include "physics.h"
#include "calculus.h"
#include "vector.h"

int graphics = 1;

int main()
{
	init_physics();
	init_graphics();
	dump_state();
	while(1){
		tick();
//		dump_state();
		draw();
	}
	deinit_graphics();
	return 0;
}

