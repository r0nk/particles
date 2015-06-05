#include <GLFW/glfw3.h>
#include <stdio.h>

#include "physics.h"
#include "graphics.h"

GLFWwindow * window;
int window_width,window_height;

void err_callback(int err, const char * description)
{
	printf("err: %i , \"%s\"",err,description);
}

int init_graphics(){
	glfwSetErrorCallback(err_callback);
	if(!glfwInit())
		return -1;
	window = glfwCreateWindow(500, 500, "particles", NULL, NULL);
	if(!window)
		return -1;
	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &window_width, &window_height);
	glViewport(0,0,window_width,window_height);
	return 0;
}

void deinit_graphics(){
	glfwTerminate();
}

void draw_polygons(){
	int i;
	float f = 50.0f;
	for(i=0;i<N_IONS;i++){
		glColor3f(-ions[i].charge,1.0f,1.0f);
		glVertex3f(ions[i].l.x/f, ions[i].l.y/f, ions[i].l.z/f);
		glVertex3f((ions[i].l.x+1)/f, ions[i].l.y/f, ions[i].l.z/f);
		glVertex3f(ions[i].l.x/f, (ions[i].l.y+1)/f, ions[i].l.z/f);
		glVertex3f(ions[i].l.x/f, ions[i].l.y/f, (ions[i].l.z+1)/f);
	}
}

void draw(){
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	float ratio= window_width / (float) window_height;
	glOrtho(-ratio,ratio,-1.f,1.f,1.f,-1.f);
	glMatrixMode(GL_MODELVIEW);

	glBegin(GL_QUADS);
	draw_polygons();
	glEnd();

	glfwSwapBuffers(window);
	glfwPollEvents();
}
