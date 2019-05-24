#include "graphics.h"
#include <iostream>
#include <unistd.h>


using namespace std;

float* clipline(float x1, float y1, float x2 , float y2);
int getCode(int x,int y);
void startClipping(float x1, float y1, float x2, float y2);

const int  LEFT = 1;	
const int  BOTTOM = 2;	
const int  RIGHT = 4;	
const int  TOP = 8;

int X_min,Y_min,X_max,Y_max;

int lineX[2], lineY[2];

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
		glVertex2i(X_min, Y_min);
		glVertex2i(X_min, Y_max);
		glVertex2i(X_max, Y_max);
		glVertex2i(X_max, Y_min);
    glEnd();

	// glColor3f(0.0, 1.0, 0.0);

	line(lineX[0],lineY[0],lineX[1],lineY[1]);
	startClipping(lineX[0],lineY[0],lineX[1],lineY[1]);

	lineX[0]++;
	lineY[0]++;
	lineX[1]--;
	lineY[1]--;

	usleep(300);

	glFlush();
	glutPostRedisplay();
}

void startClipping(float x1, float y1, float x2, float y2){
	
	bool done = false;

	while(!done){

		int code1 = getCode(x1,y1);
		int code2 = getCode(x2,y2);
		// putpixel(250,250);
		if( (code1&code2)==0 && (code1|code2)==0){
			done=true;
		}
		else if((code2&code1)==0 && (code1|code2)!=0){
			float *arr = clipline(x1,y1,x2,y2);
			x1 = (int)arr[0];
			y1 = (int)arr[1];
			x2 = (int)arr[2];
			y2 = (int)arr[3]; 

			
			// cout<<x1<<","<<y1<<"\n";
			// cout<<x2<<","<<y2<<"\n";
		}
		else if ((code1&code2)!=0){
			done=true;
			return;
		}
	}

	line(x1,y1,x2,y2,1,0,0);


}


int getCode(int x,int y){

	int code = 0;

	if(x<X_min)
		code = code | LEFT;
	else if(x>X_max)
		code = code | RIGHT;

	if(y<Y_min)
		code = code | BOTTOM;
	else if(y>Y_max)
		code = code | TOP;
	
	return code;

}

float* clipline(float x1, float y1, float x2 , float y2){
	float array[4];

	int p1 = getCode(x1,y1);
	int p2 = getCode(x2,y2);

	float m = (y2-y1)/(x2-x1);

	array[0]=x1;
	array[1]=y1;
	array[2]=x2;
	array[3]=y2; 

	if(p1&LEFT){
			array[0] = (float)X_min;
			array[1] = y2 + m*((float)X_min-x2); 
		}
		else if(p1&RIGHT){
			array[0] = (float)X_max;
			array[1] = y2 + m*((float)X_max-x2);
		}else if(p1&BOTTOM){
			array[1] = Y_min;
			array[0] = x2 + (1/m)*((float)Y_min-y2);
		}else if(p1&TOP){
			array[1] = (float)Y_max;
			array[0] = x2 + (1/m)*((float)Y_max-y2);
		}


		if(p2&LEFT){
			array[2] = (float)X_min;
			array[3] = y1 + m*((float)X_min-x1); 
			}
		else if(p2&RIGHT){
			array[2] = (float)X_max;
			array[3] = y1 + m*((float)X_max-x1);
		}else if(p2&BOTTOM){
			array[3] = (float)Y_min;
			array[2] = x1 + (1/m)*((float)Y_min-y1);
		}else if(p2&TOP){
			array[3] = (float)Y_max;
			array[2] = x1 + (1/m)*((float)Y_max-y1);
		}

	return array;
}

int main(int argc,char **argv)
{
	cout<<"Enter Xmin & Xmax: \n";
	cin>>X_min>>X_max;
	cout<<"Enter Ymin & Ymax: \n";
	cin>>Y_min>>Y_max;

	// X_max = 600;
	// X_min = 200;
	// Y_min = 300;
	// Y_max = 500;

	cout<<"Enter line coordinates: x y\n";
	cin>>lineX[0]>>lineY[0];
	cin>>lineX[1]>>lineY[1];
	// lineX[0]=500;
	// lineY[0]=679;
	// lineX[1]=453;
	// lineY[1]=274;

	glutInit(&argc,argv);
	initializeWindow(800,800,"hr");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}