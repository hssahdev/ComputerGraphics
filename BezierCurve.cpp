#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <GLUT/glut.h>
#include <math.h>

const int MAX_X = 250 ;
const int MAX_Y = 250;

using namespace std;

void bezier (int x[4], int y[4])
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
    glVertex2f(xt/250,yt/250);
  glEnd();
    }

    // glColor3f(0,1,0);
    // glPointSize(3);
    // for (i=0; i<4; i++){
    //   glBegin(GL_POINTS);
    //   glVertex2f((float)x[i]/250,(float)y[i]/250);
    //   glEnd();
    // }
	// putpixel (x[i], y[i], YELLOW);

    //getch();
    //closegraph();
    return;
}

void display() {
  glBegin(GL_LINES);
  glVertex2f(0,0.2);
  glVertex2f(0,0.35);
  glVertex2f(0,0.3);
  glVertex2f(-0.1,0.3);
  glVertex2f(0.1,0.35);
  glVertex2f(-0.1,0.35);
  glEnd();


  int y[]={75,60,60,75};
  int x[]={-25,-20,-17,-12};
  bezier(x,y);
  x[0] = 0; y[0] = 88;
  x[3] = -10; y[3]=105;
  x[1] = -40; y[1]=120;
  x[2] = -15; y[2]=90;
bezier(x,y);
  glFlush();
}

int main(int argc, char  **argv) {
  glutInit(&argc,argv);
  glutInitWindowSize(MAX_X*2,MAX_Y*2);
  glutInitWindowPosition(50,50);
  glutCreateWindow("Window");
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}
