#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/MYglut.h>
#include "ellipse.h"

void init2D(float r, float g, float b)
{
	glClearColor(r,g,b,0.0);  
	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// glColor3f(1.0, 0.0, 0.0);

	//draw two points
	// glBegin(GL_POINTS);
	// for(int i = 0; i < 10; i++)s
	// {
	// 	glVertex2i(10+5*i,110gcc);
	// }
	// glEnd();

	// //draw a line
	// glBegin(GL_LINES);
	// 	glVertex2i(10,10);
	// 	glVertex2i(100,100);
	// glEnd();
	drawellipse(90,45,100,50);

	glFlush();
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (1000, 1000);
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Testing");
	init2D(0,0,0);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}