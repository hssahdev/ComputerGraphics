#include "graphics.h"
#include <iostream>

using namespace std;

float points[][3] = {
				{20,20,20},
				{60,20,20},
				{40,20,60},
				{40,40,40}
				};

int torch[] = {20,30,40}; 

int n =4;

float normalV(int arr[3][3]){
	float v1[] = {arr[0][0]-arr[1][0] , arr[0][1]-arr[1][1], arr[0][2]-arr[1][2]};
	float v2[] = {arr[2][0]-arr[1][0] , arr[2][1]-arr[1][1], arr[2][2]-arr[1][2]};



} 

void display(){

	// glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// glLineWidth(5.0);
	gluLookAt()

	glBegin(GL_LINES);

	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			glVertex3f((points[i][0]/100),(points[i][1]/100),(points[i][2]/100));
			glVertex3f((points[j][0]/100),(points[j][1]/100),(points[j][2]/100));
			cout<<(points[i][0]/100)<<endl;
		}
	}
	glEnd();

	glutSwapBuffers();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);            // Initialize GLUT
   	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("SDF");
	glMatrixMode(GL_MODELVIEW);
  	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  	// glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	// gluOrtho2D(0, 80, 0, 80); 

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(1.0, 1.0, 1.0);

	glEnable(GL_DEPTH_TEST);       // Create window with the given title
   	glutDisplayFunc(display); 
   	// glutReshapeFunc(reshape);                   // Our own OpenGL initialization
   	glutMainLoop(); 

}	