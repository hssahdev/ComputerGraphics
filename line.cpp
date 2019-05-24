#include "graphics.h"

int x1,y1,x2,y2;

x1= 56;
x2 = 200;
y1= 456;
y2 = 67;

void disp(){
	
	
	float dx = x2-x1;
	float dy = y2-y1;
	float m = dy/dx;

	// putpixel(x1,y1);
	float temp_y = y1;
	float temp_x = x1;

	if(dy>dx){

		while(temp_y!=y2){
			putpixel(int(temp_x),int(temp_y));
			temp_y++;
			temp_x = temp_x + 1/m;
		}
	}
	else{
		while(temp_x!=x2){
			putpixel(int(temp_x),int(temp_y));
			temp_x++;
			temp_y = temp_y + m;
		}
	}

	glFlush();
}

int main(int argc, char **argv)
{
	/* code */
	glutInit(&argc,argv);
	initializeWindow(500,500,"line");
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}