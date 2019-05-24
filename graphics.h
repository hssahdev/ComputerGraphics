#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

void putpixel(int x, int y, float r=1, float g=1, float b=1) {
	glBegin(GL_POINTS);
	glColor3f(r,g,b);
	glVertex2i(x, y);
	glEnd();
}

// void myInit(int len,int bred) {
// glClear(GL_COLOR_BUFFER_BIT);
// glClearColor(0.0, 0.0, 0.0, 1.0);
// glMatrixMode(GL_PROJECTION);
// gluOrtho2D(0, len, 0, bred);
// }

void initializeWindow(int len, int bred, char str[]){
	// glutInit(&argc, argv);
	// glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(len, bred);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(str);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, len, 0, bred);


	// myInit(len,bred);
}

void line(int x1, int y1,int x2, int y2, float r=1, float g=1, float b=1){
	glBegin(GL_LINES);
		glColor3f(r,g,b);
		glVertex2i(x1,y1);
		glVertex2i(x2,y2);
	glEnd();
}

void reshape(int w,int h){
  glViewport(0,0,(GLsizei)w,(GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-160,160,-160,160);
  glMatrixMode(GL_MODELVIEW);
  }