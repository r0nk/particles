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

double f(double x)
{
	return sqrt(1-(x*x));	
}

int main()
{
	printf(" pi = %.55f\n",2*intergral(-1,1,f));
	printf("rpi = 3.141592653589793238462643383279502884197169399375105\n");
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
