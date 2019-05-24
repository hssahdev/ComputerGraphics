#include<iostream>
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <cmath>

using namespace std;

const int X_MAX = 400;
const int Y_MAX = 300;

float PI = 3.14159;


float pointX(float x)
{return x/12;}
float pointY(float y)
{return y/9;}

void bezier (float x[4], float y[4])
{

    int i;
    double t;
    glColor3f(1,1,1);
    glPointSize(1);
    for (t = 0.0; t < 1.0; t += 0.0005)
    {
	double xt = pow (1-t, 3) * x[0] + 3 * t * pow (1-t, 2) * x[1] +
		    3 * pow (t, 2) * (1-t) * x[2] + pow (t, 3) * x[3];

	double yt = pow (1-t, 3) * y[0] + 3 * t * pow (1-t, 2) * y[1] +
		    3 * pow (t, 2) * (1-t) * y[2] + pow (t, 3) * y[3];

	// putpixel (xt, yt, WHITE);
  glBegin(GL_POINTS);
    glVertex3f(pointX(xt),pointY(yt),0);
  glEnd();
    }

    return;
}

float t=2;

void display(){
  float x[4],y[4];
  glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glColor3f(1,1,1);

  glRotatef(t,1,0,0);

  glBegin(GL_LINES);
  glVertex3f(pointX(-4.9),pointY(1),0);
  glVertex3f(pointX(-5.1),pointY(-1),0);
  glEnd();

//H
  x[0]= -4.9; y[0] = 1;
  x[3] = -5.2; y[3] = 0.5;
  x[1] = -3.5;y[1]=2.3;
  x[2] = -5; y[2]=0;
  bezier(x,y);

  x[0]=-5.1; y[0] = -1;
  x[3] = -3.7; y[3] = 1.3;
  x[1] = -6;y[1]=-3;
  x[2] = -4; y[2]=1.1;
  bezier(x,y);

    x[0] = -3.7; y[0] = 1.3;
    x[3] = -3.6; y[3] = -0.5;
    x[1] = -5.2;y[1]=-1;
    x[2] = -4.6; y[2]=-2;
    bezier(x,y);

    //a
    x[0] = -3.6; y[0] = -0.6;
    x[3] = -3.3; y[3] = 0.1;
    x[1] = -3.65;y[1]=0;
    x[2] = -3.65; y[2]=0;
    bezier(x,y);

    x[0] = -3.6; y[0] = -0.6;
    x[3] = -3.3; y[3] = 0.1;
    x[2] = -2.8;y[2]=0;
    x[1] = -2.6; y[1]=-1.5;
    bezier(x,y);

    x[0] = -2.9; y[0] = -0.5;
    x[3] = -2.1; y[3] = -0.1;
    x[1] = -2.5;y[1]=-1.5;
    x[2] = -2.3; y[2]=-1;
    bezier(x,y);

//r
    x[0] = -2.1; y[0] = -0.1;
    x[3] = -2.1; y[3] = -0.1;
    x[1] = -2.6;y[1]=-0.1;
    x[2] = -1.9; y[2]=0.5;
    bezier(x,y);

    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(pointX(-2.1),pointY(-0.1),0);
    glVertex3f(pointX(-1.6),pointY(0.1),0);
    glEnd();

    x[0] = -1.6; y[0] = 0.1;
    x[3] = -0.8; y[3] = 0;
    x[1] = -2.7;y[1]=-1.5;
    x[2] = -1.3; y[2]=-1;
    bezier(x,y);

    x[0] = -0.8; y[0] = 0;
    x[3] = -1; y[3] = -0.3;
    x[1] = -0.5;y[1]=0.4;
    x[2] = -1.3; y[2]=0;
    bezier(x,y);

    x[0] = -1; y[0] = -0.3;
    x[3] = -1; y[3] = -1;
    x[1] = -0.6;y[1]=-0.6;
    x[2] = -0.5; y[2]=-0.8;
    bezier(x,y);

//h
    x[0] = -1; y[0] = -1;
    x[3] = 0.5; y[3] = 1;
    x[1] = 0;y[1]=-0.4;
    x[2] = 0.7; y[2]=0.5;
    bezier(x,y);

    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(pointX(0.5),pointY(1),0);
    glVertex3f(pointX(-0.4),pointY(-1),0);
    glEnd();

    x[0] = -0.4; y[0] = -1;
    x[3] = 0.5; y[3] = -1;
    x[1] = 0.5;y[1]=1;
    x[2] = 0.9; y[2]=0;
    bezier(x,y);

    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(pointX(-5.5),pointY(-1.5),0);
    glVertex3f(pointX(1),pointY(-1.5),0);
    glEnd();



  glFlush();

  glutPostRedisplay();
}

int main(int argc, char  **argv) {
  /* code */
  glutInit(&argc,argv);
	glutInitWindowSize(800,600);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Signature");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutMainLoop();

  cout<<pointX(-4.9);
  return 0;
}
