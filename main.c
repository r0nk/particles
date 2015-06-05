#include <stdio.h>
#include <readline/readline.h>

#include "physics.h"
#include "vector.h"


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

