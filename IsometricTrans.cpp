#include<iostream>
#include "graphics.h"
#include <cmath>

using namespace std;

#define PI 3.14


float** matrixMulti(float X[4][4], float Y[4][4]){
	float** ans = new float* [4];

	for(int i=0;i<4;i++){
		ans[i] = new float[4];
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				ans[i][j] += X[j][k]*Y[k][j];
			}
		}
	}

	return ans;
}

float* matrixMultiSingle(float X[4][4], float Y[4]){
	float *ans = new float[4];

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			ans[i] += X[i][j]*Y[j];
		}
	}

	return ans;
}

float *transformX(float theta, float points[4]){

	theta = theta*PI/(180);
	float R[4][4] = {
					{1,0,0,0},
					{0,cos(theta),-sin(theta),0},
					{0,sin(theta),cos(theta),0},
					{0,0,0,1}
				};

	float* k = matrixMultiSingle(R,points);
	return k;
}

float *transformY(float theta, float points[4]){
	theta = theta*PI/(180);
	float R[4][4] = {
					{cos(theta),0,sin(theta),0},
					{0,1,0,0},
					{-sin(theta),0,cos(theta),0},
					{0,0,0,1}
				};

	return matrixMultiSingle(R,points);
}

float *transformZ(float theta, float points[4]){

	theta = theta*PI/(180);
	float R[4][4] = {
					{cos(theta),-sin(theta),0,0},
					{sin(theta),cos(theta),0,0},
					{0,0,1,0},
					{0,0,0,1}
				};

	return matrixMultiSingle(R,points);
}

void drawCube(float **points){
	int i,j,k,l;
	i=0;j=1;k=2;l=3;
	glColor3f(1.0,1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f(points[i][0],points[i][1],points[i][2]);
		glVertex3f(points[j][0],points[j][1],points[j][2]);
		glVertex3f(points[k][0],points[k][1],points[k][2]);
		glVertex3f(points[l][0],points[l][1],points[l][2]);
	glEnd();

	i=4;j=5;k=6;l=7;
	glColor3f(1.0,0.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3f(points[i][0],points[i][1],points[i][2]);
		glVertex3f(points[j][0],points[j][1],points[j][2]);
		glVertex3f(points[k][0],points[k][1],points[k][2]);
		glVertex3f(points[l][0],points[l][1],points[l][2]);
	glEnd();

	i=0;j=1;k=6;l=7;
	glColor3f(0.0,1.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3f(points[i][0],points[i][1],points[i][2]);
		glVertex3f(points[j][0],points[j][1],points[j][2]);
		glVertex3f(points[k][0],points[k][1],points[k][2]);
		glVertex3f(points[l][0],points[l][1],points[l][2]);
	glEnd();

	i=2;j=3;k=4;l=5;
	glColor3f(0.0,0.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f(points[i][0],points[i][1],points[i][2]);
		glVertex3f(points[j][0],points[j][1],points[j][2]);
		glVertex3f(points[k][0],points[k][1],points[k][2]);
		glVertex3f(points[l][0],points[l][1],points[l][2]);
	glEnd();

	i=1;j=2;k=5;l=6;
	glColor3f(1.0,1.0, 0.0);
	glBegin(GL_POLYGON);
		glVertex3f(points[i][0],points[i][1],points[i][2]);
		glVertex3f(points[j][0],points[j][1],points[j][2]);
		glVertex3f(points[k][0],points[k][1],points[k][2]);
		glVertex3f(points[l][0],points[l][1],points[l][2]);
	glEnd();

	i=0;j=3;k=4;l=7;
	glColor3f(0.0,1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f(points[i][0],points[i][1],points[i][2]);
		glVertex3f(points[j][0],points[j][1],points[j][2]);
		glVertex3f(points[k][0],points[k][1],points[k][2]);
		glVertex3f(points[l][0],points[l][1],points[l][2]);
	glEnd();
}

void display(){

	glClearColor(0.0, 0.0, 0.0, 1.0);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	float a=0.2;
	float point[8][4] = {
		{a,a,a,1},
		{a,-a,a,1},
		{-a,-a,a,1},
		{-a,a,a,1},
		{-a,a,-a,1},
		{-a,-a,-a,1},
		{a,-a,-a,1},
		{a,a,-a,1}
	};

	float **ans = new float*[8];
	for(int i=0;i<8;i++){
		float* y_transformed = transformY(45,point[i]);
		ans[i] = transformX(35.264,y_transformed);
		// cout<<ans[i][1]<<endl;
	}

	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();

	drawCube(ans);
	delete ans;
	glutSwapBuffers();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);            // Initialize GLUT
   	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Cube");
	glMatrixMode(GL_MODELVIEW);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// gluOrtho2D(-250, 250, -250, 250); 
	glEnable(GL_DEPTH_TEST);       // Create window with the given title
   	glutDisplayFunc(display);                    // Our own OpenGL initialization
   	glutMainLoop(); 

}