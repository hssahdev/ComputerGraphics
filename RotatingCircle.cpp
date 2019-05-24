#include "graphics.h"
#include<math.h>
#include "ellipse.h"
#include "circle.h"
#include <unistd.h>

#define PI 3.18

float i=0;
void display(){

	glClear(GL_COLOR_BUFFER_BIT);
	int radius = 40;
	int a = 150;
	int b =100;
	
		glBegin(GL_POINTS);
			circle(250+(a+radius)*cos(PI/180 * i), 250+(b+radius)*sin(PI/180 * i),radius);
			drawellipse(150,100,250,250);
		glEnd(); 
        glFlush();
		i+=0.1;
		usleep(300);
		glutPostRedisplay();
}

void ell(){
	drawellipse(150,100,250,250);
}

int main(int argc, char **argv)
{
	/* code */
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutCreateWindow("Circle");
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}