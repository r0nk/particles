#include <linux/fb.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include "graphics.h"

int main()
{
	int x,y;
	get_screen_info();

	draw_line(1000,100,900,200);
	draw_line(1000,100,1100,200);

	draw_line(900,200,800,300);
	draw_line(900,200,900,300);
	draw_line(900,200,1000,300);
	draw_line(1100,200,1000,300);
	draw_line(1100,200,1100,300);
	draw_line(1100,200,1200,300);

	draw_line(800,300,800,400);
	draw_line(800,300,900,400);
	draw_line(900,300,800,400);
	draw_line(900,300,1100,400);
	draw_line(1000,300,900,400);
	draw_line(1000,300,1100,400);
	draw_line(1100,300,900,400);
	draw_line(1100,300,1200,400);
	draw_line(1200,300,1100,400);
	draw_line(1200,300,1200,400);

	draw_line(800,400,1000,500);
	draw_line(900,400,1000,500);
	draw_line(1100,400,1000,500);
	draw_line(1200,400,1000,500);

	box(1000,100);

	box(900,200);
	box(1100,200);

	box(800,300);
	box(900,300);
	box(1000,300);
	box(1100,300);
	box(1200,300);

	box(800,400);
	box(900,400);
	box(1100,400);
	box(1200,400);

	box(1000,500);

	return 0;
}
