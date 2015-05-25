#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <readline/readline.h>
#include <math.h>
#include "physics.h"
#include "calculus.h"
#include "vector.h"

int main()
{
	struct vector a,b;
	double c;
	a.x = 1;a.y = 2;a.z = 3;
	b.x = 4;b.y = -5;b.z = 6;
	c = v_dot(a,b);
	printf("c: %f \n",c);
	return 0;
}

/*
 *int main()
 *{
 *	init_physics();
 *	while(1){
 *		tick();
 *		dump_state();
 *		readline("~");
 *	}
 *	return 0;
 *}
*/
