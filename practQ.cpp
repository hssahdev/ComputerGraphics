#include<iostream>
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <cmath>

using namespace std;
float r = 2;

void display(){
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float b = 1;
	// glRotatef(r,1-transX,1-transY,0);
	// glRotatef(b,1,0,0);

  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex3f(1,1,0.5);
  glVertex3f(-1,-1,0.5);
  glEnd();

  glPushMatrix();
  glRotatef(r,0,0,1);
  glColor3f(1,0,0);
	glBegin(GL_POLYGON);
  glVertex3f(0.6,0.6,0.6);
  glVertex3f(-0.6,0.6,0.6);
  glVertex3f(-0.6,-0.6,0.6);
  glVertex3f(0.6,-0.6,0.6);
  glEnd();

  glColor3f(0,0,0);
  glBegin(GL_POLYGON);
  glVertex3f(0.3,0.3,0.5);
  glVertex3f(-0.3,0.3,0.5);
  glVertex3f(-0.3,-0.3,0.5);
  glVertex3f(0.3,-0.3,0.5);
  glEnd();

  glPopMatrix();

  glFlush();

  r+=2;
  glutPostRedisplay();
}
  int main(int argc, char **argv)
  {

  	// displayPoints(points);

  	glutInit(&argc,argv);
  	glutInitWindowSize(700,700);
  	glutInitWindowPosition(50,50);
  	glutCreateWindow("Rotation");
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  	glEnable(GL_DEPTH_TEST);
  	glutDisplayFunc(display);
  	// glutSpecialFunc(keys);
  	glutMainLoop();
  	return 0;
}
