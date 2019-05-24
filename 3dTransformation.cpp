#include <iostream>
#include<cmath>
// #include"graphics.h"

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

	theta = theta*2*PI/(180);
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
	theta = theta*2*PI/(180);
	float R[4][4] = {
					{cos(theta),0,sin(theta),0},
					{0,1,0,0},
					{-sin(theta),0,cos(theta),0},
					{0,0,0,1}
				};

	return matrixMultiSingle(R,points);
}

float *transformZ(float theta, float points[4]){

	theta = theta*2*PI/(180);
	float R[4][4] = {
					{cos(theta),-sin(theta),0,0},
					{sin(theta),cos(theta),0,0},
					{0,0,1,0},
					{0,0,0,1}
				};

	return matrixMultiSingle(R,points);
}

int main(int argc, char const **argv){
// 	glutInit(&argc,argv);
// 	initializeWindow(600,600,"Window");
// 	glutDisplayFunc(display);
// 	glutMainLoop();
	float T[4][4] = {
					{1,0,0,-2},
					{0,1,0,-3},
					{0,0,1,-5},
					{0,0,0,1}
				};
	float b[4] = {2,3,5,1};

	

	float *j = transformX(45,b);
	for (int i = 0; i < 4; ++i)
	{
		cout<<j[i]<<endl;
	}

}