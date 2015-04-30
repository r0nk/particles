#ifndef WARD_GRAPHICS
#define WARD_GRAPHICS

#include <linux/fb.h>
#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>

struct fb_fix_screeninfo finfo;
struct fb_var_screeninfo vinfo;

uint8_t *fbp;

uint8_t cr,cg,cb;

uint32_t pixel_color(uint8_t r, uint8_t g, uint8_t b, struct fb_var_screeninfo *vinfo);
void init_graphics();
long loc(int x, int y);
void set_pixel(int x,int y, uint8_t r, uint8_t g , uint8_t b);
void draw_rectangle(long x1, long y1, long x2 , long y2);
void draw_line(int x1,int y1,int x2,int y2);
void box(unsigned int x,unsigned int y);

#endif
