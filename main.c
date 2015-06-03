#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <readline/readline.h>
#include <math.h>

#include "graphics.h"
#include "physics.h"
#include "calculus.h"
#include "vector.h"

int main()
{
	init_physics();
//	init_graphics();
	dump_state();
	while(1){
		tick();
		dump_state();
		readline("~");
	}
	return 0;
}

