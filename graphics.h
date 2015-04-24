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

inline uint32_t pixel_color(uint8_t r, uint8_t g, uint8_t b, struct fb_var_screeninfo *vinfo)
{
	return (r<<vinfo->red.offset) | (g<<vinfo->green.offset) | (b<<vinfo->blue.offset);
}

void get_screen_info()
{
	int fb_fd = open("/dev/fb0",O_RDWR);

	//Get variable screen information
	ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);
	vinfo.grayscale=0;
	vinfo.bits_per_pixel=32;
	ioctl(fb_fd, FBIOPUT_VSCREENINFO, &vinfo);
	ioctl(fb_fd, FBIOGET_VSCREENINFO, &vinfo);

	ioctl(fb_fd, FBIOGET_FSCREENINFO, &finfo);

	long screensize = vinfo.yres_virtual * finfo.line_length;

	fbp= mmap(0, screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fb_fd, (off_t)0);
}

inline long loc(int x, int y)
{
	return (x+vinfo.xoffset) * (vinfo.bits_per_pixel/8) + (y+vinfo.yoffset) * finfo.line_length;
}

inline void set_pixel(int x,int y, uint8_t r, uint8_t g , uint8_t b)
{
	*((uint32_t*)(fbp + loc(x,y))) = pixel_color(r,g,b, &vinfo);
}

void draw_rectangle(long x1, long y1, long x2 , long y2)
{
	long tmp;
	if(x1>x2){
		tmp=x1;
		x1=x2;
		x2=tmp;
	}
	if(y1>y2){
		tmp=y1;
		y1=y2;
		y2=tmp;
	}
	tmp=y1;
	for(;x1<x2;x1++)
		for(y1=tmp;y1<y2;y1++)
			setpixel(x1,y1,cr,cg,cb);
}

void drawLine(int x1,int y1,int x2,int y2){
	int dx=abs(x2-x1),sx=x1<x2?1:-1;
	int dy=abs(y2-y1),sy=y1<y2?1:-1;
	int err=(dx>dy?dx:-dy)/2,e2;
	while(!(x1==x2&&y1==y2)){
		e2 = err;
		if(e2>-dx){
			err-=dy;
			x1+=sx;
		}
		if(e2<dy){
			err+=dx;
			y1+=sy;
		}
		setpixel(x1,y1,cr,cg,cb);
	}
}
