#include <linux/fb.h>
#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include "graphics.h"
#include "physics.h"

int main()
{
	int y=0;
	init_graphics();
	init_physics();
	while(1){
		tick(y++);
		usleep(20000);
	}

	return 0;
}
