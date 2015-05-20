#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <readline/readline.h>
#include "physics.h"

int main()
{
	init_physics();
	while(1){
		tick();
		dump_state();
		readline("~");
	}
	return 0;
}
