#include<iostream>
#define GL_SILENCE_DEPRECATION
#include<GLUT/glut.h>
#include "graphics.h"
#include <unistd.h>
#include "circle.h"


using namespace std;

float r = 0.872;
bool rev = false;
int a =0;
int b=0;

void display(){
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// circle(0,0,50);

	glLineWidth(4.0);
	//base
	glColor3f(1,0,0);
	glBegin(GL_LINES);
		glVertex2i(-250,-50);
		glVertex2i(250,-50);
	glEnd();	

	//seesaw
	glColor3f(1,1,0);
	glBegin(GL_LINES);
		glVertex2i(0,-50);
		glVertex2i(0,0);
	glEnd();

	glPushMatrix();
	glRotatef(-r, 0, 0, 1);
	glBegin(GL_LINES);
		glVertex2i(-125,-50);
		glVertex2i(125,50);
	glEnd();
	
	glColor3f(0,1,0);
	glPointSize(5.0);
	circle(-125+a,-30+b,20);
	glPopMatrix();

	
	glFlush();

	if (!rev){
		r+=0.872;
		a+=5;
		b+=2;
		if(r>43.6){
			rev = true;
		}
		
	}
	else{
		a-=5;
		b-=2;
		r-=0.872;
		if(r<0)
		rev = false;
	}
	glutPostRedisplay();

}

void special(int key, int x, int y){

	if(key==GLUT_KEY_RIGHT){
		r+=0.872;
		a+=5;
		b+=2;
		if(r>43.6){
			rev = true;
		}
	}else if(key==GLUT_KEY_LEFT){
		a-=5;
		b-=2;
		r-=0.872;
		if(r<0)
		rev = false;
	}

	// if (!rev){
	// 	r+=0.872;
	// 	a+=5;
	// 	b+=2;
	// 	if(r>43.6){
	// 		rev = true;
	// 	}
		
	// }
	// else{
	// 	a-=5;
	// 	b-=2;
	// 	r-=0.872;
	// 	if(r<0)
	// 	rev = false;
	// }
	glutPostRedisplay();

}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Seesaw");
	gluOrtho2D(-250,250,-250,250);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutSpecialFunc(special);
	glutMainLoop();
	return 0;
}