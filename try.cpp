#include <iostream>
#include <stdlib.h>

#ifdef _APPLE_
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GLUT/glut.h>
#endif

#include <cmath>
using namespace std;

void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer
 
   // glLoadIdentity();
   // glPointSize(10.0);
   // glBegin(GL_POINTS);
   //  glVertex2f(5,5);
   //  glVertex2f(-5,-5);
   // glEnd();
   
   // glBegin(GL_TRIANGLES);
   //    glVertex2f(0.0,5.0);
   //    glVertex2f(4.0,-3.0);
   //    glVertex2f(-4.0,-3.0);
   // glEnd(); 
   // // Draw a Red 1x1 Square centered at origin
   glBegin(GL_POLYGON);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 1.0f, 0.0f); // Red
      glVertex2f(0.0f, 0.0f);    // x, y
      glVertex2f( 5.0f, 0.0f);
      glVertex2f( 5.0f,  5.0f);
      glVertex2f(0.0f,  5.0f);
      glVertex2f(0.8f,  5.0f);
   glEnd();

   // // Draw Line
   // glLineWidth(10.0); 
   // glColor3f(1.0, 0.0, 0.0);
   // glBegin(GL_LINES);
   // glVertex2f(0.0f, 0.0f);
   // glVertex2f(0,10.0);
   // glEnd();


   // Circle
   // float x,y;
   // float radius = 3.0f;
   // glBegin(GL_LINES);
   // glColor3f(1.0f,0.0f,0.0f);
   // float PI = 3.14159f;
     
   //  x = (float)radius * cos(359 * PI/180.0f);
   //  y = (float)radius * sin(359 * PI/180.0f);
   //  for(int j = 0; j < 360; j++)
   //  {
   //      glVertex2f(x,y);
   //      x = (float)radius * cos(j * PI/180.0f);
   //      y = (float)radius * sin(j * PI/180.0f);
   //      glVertex2f(x,y);
   //  }
   glEnd();

 
   glFlush();  // Render now
}
void reshape(int w,int h){
  glViewport(0,0,(GLsizei)w,(GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-160,160,-160,160);
  glMatrixMode(GL_MODELVIEW);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   
   glutReshapeFunc(reshape); 
   glutMainLoop();           // Enter the infinitely event-processing loop
   return 0;
}