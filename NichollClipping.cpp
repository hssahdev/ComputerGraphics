#include "graphics.h"
#include "circle.h"
#include <iostream>

using namespace std;

int arr[4][2] = {{200,300},{400,700},{600,100},{200,300}};



float* line(int x , int y){

	float ans[3];
	for(int i=0;i<3;i++){
		ans[i] = x*(arr[i+1][1]-arr[i][1]) - y*(arr[i+1][0]-arr[i][0]) + arr[i][1]*(arr[i+1][0]-arr[i][0]) - arr[i][0] * (arr[i+1][1]-arr[i][1]); 
	}

	return ans;
}

void clipInsideOut(int x, int y, int x_in, int y_in){
	float cross_product[3];

	float vec_line[2] = {(x-x_in),(y-y_in)};

	for (int i=0;i<3;i++){
		cross_product[i] = ((float)arr[i][1]-(float)y_in)*vec_line[1] + ((float)arr[i][0]-(float)x_in)*vec_line[0];
		cout<<cross_product[i]<<"\n";
		// circle(arr[i][0],arr[i][1],20);
	}
	

}


bool checkIfInside(int x, int y){
	 float *a = line(x,y);
	 if(a[0]>0 && a[1]>0 && a[2]>0)
	 	return true;

	 return false;
	}

void startClipping(int x1, int y1, int x2, int y2){

	if(checkIfInside(x1,y1) && checkIfInside(x2,y2)){
		line(x1,y1,x2,y2);
	}
	else if(checkIfInside(x1,y1) && !checkIfInside(x2,y2)){
		clipInsideOut(x2,y2,x1,y1);
		// circle(400,400,60);

	}
	else if(!checkIfInside(x1,y1) && checkIfInside(x2,y2)){
		clipInsideOut(x1,y1,x2,y2);
		// circle(400,400,60);

	}
	else{
		circle(100,100,34);
	}
}


void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
		glVertex2i(200, 300);
		glVertex2i(400, 700);
		glVertex2i(600,100);
    glEnd();

    line(700,700,400,400);

    startClipping(700,700,400,400);


	glFlush();
}

int main(int argc,char **argv)
{
	// float *a = line(100,100,arr);
	// for(int i=0;i<3;i++){
	// 	cout<<a[i]<<"\n";
	// }
	glutInit(&argc,argv);
	initializeWindow(800,800,"hr");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	// cout<<checkIfInside(400,400);
	// cout<<checkIfInside(100,100);

	return 0;
}