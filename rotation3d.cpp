#include<iostream>
#define GL_SILENCE_DEPRECATION
#include <GLUT/glut.h>
#include <cmath>

using namespace std;

float PI = 3.14159;

float** points;

float transX = 0.0;
float transY = 0.0;

void displayPoints(float **a){
	for(int i=0; i<4;i++){
		cout<<"Point "<<i+1<<": ";
		for(int j=0;j<4;j++){
			cout<<a[i][j]<<", ";
		}
		cout<<endl;
	}
	cout<<endl;
}

float* matrixMultiSingle(float X[4][4], float Y[4]){
	float *ans = new float[4];

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			ans[i] += (X[i][j]*Y[j]);
		}
	}

	return ans;
}

float *transformX(float theta, float p[4]){

	theta = theta*PI/(180);
	float co = cos(theta);
	float si = sin(theta);
	cout<<co<<" "<<si<<endl;
	float R[4][4] = {
					{1,0,0,0},
					{0,co,-si,0},
					{0,si,co,0},
					{0,0,0,1}
				};
	// displayPoints(R);


	float* temp = matrixMultiSingle(R,p);
	for(int i=0;i<4;i++){
		cout<<temp[i]<<" ";
	}
	cout<<endl;

	return temp;
}

float *transformY(float theta, float p[4]){
	theta = theta*PI/(180);
	float co = cos(theta);
	float si = sin(theta);
	float R[4][4] = {
					{co,0,si,0},
					{0,1,0,0},
					{-si,0,co,0},
					{0,0,0,1}
				};
	// displayPoints(R);

	return matrixMultiSingle(R,p);
}

float *transformZ(float theta, float p[4]){

	theta = theta*PI/(180);
	float co = cos(theta);
	float si = sin(theta);
	float R[4][4] = {
					{co,-si,0,0},
					{si,co,0,0},
					{0,0,1,0},
					{0,0,0,1}
				};

	return matrixMultiSingle(R,p);
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
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	float r = 2;
	float b = 1;
	// glRotatef(r,1-transX,1-transY,0);
	// glRotatef(b,1,0,0);
	drawCube(points);
	glFlush();
	// r+=2;
	// b+=1;
	// glutPostRedisplay();
}

void keys(int key, int x, int y){
	float roation = 10;
	switch(key){
		case GLUT_KEY_UP:
			for(int i=0;i<8;i++){
				points[i] = transformX(roation,points[i]);
			}
			displayPoints(points);
		break;
		case GLUT_KEY_DOWN:
			for(int i=0;i<8;i++){
				points[i] = transformX(-roation,points[i]);
			}
			displayPoints(points);
		break;
		case GLUT_KEY_RIGHT:
			for(int i=0;i<8;i++){
				points[i] = transformY(-roation,points[i]);
			}
		displayPoints(points);
		break;
		case GLUT_KEY_LEFT:
			for(int i=0;i<8;i++){
				points[i] = transformY(roation,points[i]);
			}
		displayPoints(points);
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char **argv)
{
	float a=0.2;
	float temp[8][4] = {
			{a+transX,a+transY,a,1},
			{a+transX,-a+transY,a,1},
			{-a+transX,-a+transY,a,1},
			{-a+transX,a+transY,a,1},
			{-a+transX,a+transY,-a,1},
			{-a+transX,-a+transY,-a,1},
			{a+transX,-a+transY,-a,1},
			{a+transX,a+transY,-a,1}
		};
	points = new float*[8];
	for(int i=0;i<8;i++){
		points[i] = new float[4];
		points[i][0] = temp[i][0];
		points[i][1] = temp[i][1];
		points[i][2] = temp[i][2];
		points[i][3] = 1;
	}

	// displayPoints(points);

	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Rotation");
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutSpecialFunc(keys);
	glutMainLoop();
	return 0;
}