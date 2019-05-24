#include <GLUT/MYglut.h>
#include <stdio.h>
#include "circle.h"
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>



void myInit() {
glClear(GL_COLOR_BUFFER_BIT);
glClearColor(0.0, 0.0, 0.0, 1.0);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0, 700, 0, 700);
}

// void draw_pixel(int x, int y) {
// glBegin(GL_POINTS);
// glColor3f(1,1,1);
// glVertex2i(x, y);
// glEnd();
// }

void myDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	circle(350,350,230);
	glFlush();
}

int main(int argc, char **argv) {

glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(700, 700);
glutInitWindowPosition(100, 100);
glutCreateWindow("Circle");
myInit();
glutDisplayFunc(myDisplay);
glutMainLoop();
return 0;
}
