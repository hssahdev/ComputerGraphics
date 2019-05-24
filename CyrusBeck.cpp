#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <GLUT/glut.h>
#include <bits/stdc++.h>
#include <math.h>

const int MAX_X = 250;
const int MAX_Y = 250;

using namespace std;

float vertices[][2]={{-90,90},{-23,190},{140,-200},{-42,-150},{-100,-80}};
float line[][2] = {{-200,-50},{150,-90}};
int n = 5;

float* getNormal(int x1, int y1, int x2, int y2){
  int i = x2-x1;
  int j =y2-y1;
  float *normal = new float[2];
  normal[0] = -j;
  normal[1]=i;

  return normal;
}

void cyrusBeck(float line[][2], float vertices[][2] , int n){
  float lineV[]={line[1][0]-line[0][0], line[1][1]-line[0][1]};
  float t_exit = 1;
  float t_entry = 0;
  vector<float> list_of_t_entry;
  vector<float> list_of_t_exit;

  for(int i=0;i<n;i++){

      float pointX = vertices[i][0];
      float pointY = vertices[i][1];
      float *normal = getNormal(vertices[i][0],vertices[i][1],vertices[(i+1)%n][0],vertices[(i+1)%n][1]);
      float t = -((line[0][0]-pointX)*normal[0] + (line[0][1]-pointY)*normal[1])/(lineV[0]*normal[0] + lineV[1]*normal[1]);
      cout<<"T for "<<i<<": "<<t<<endl;
      if(t>=0 && t<=1){
        float chk = lineV[0]*normal[0] + lineV[1]*normal[1];
        cout<<"Check for "<<i<<": "<<chk<<endl;
        if (chk<0){
            t_entry=max(t_entry,t);
            // list_of_t_entry.push_back(t);
        }else{
          t_exit=min(t_exit,t);
          // list_of_t_exit.push_back(t);
        }
      }
  }

  // sort(list_of_t_exit.begin(), list_of_t_exit.end());
  // sort(list_of_t_entry.begin(), list_of_t_entry.end());
  // for(int i = 0; i<list_of_t_exit.size() ; i++){
  //   float t_exit = list_of_t_exit.at(i);
  //   float t_entry = list_of_t_entry.at(i);
  //
  //   float ptx_entry = line[0][0]+t_entry*lineV[0];
  //   float pty_entry = line[0][1]+t_entry*lineV[1];
  //
  //   float ptx_exit = line[0][0]+t_exit*lineV[0];
  //   float pty_exit = line[0][1]+t_exit*lineV[1];
  //
  //   glColor3f(0,1,0);
  //   glLineWidth(5);
  //   glBegin(GL_LINES);
  //     glVertex2f(ptx_entry/MAX_X,pty_entry/MAX_Y);
  //     glVertex2f(ptx_exit/MAX_X,pty_exit/MAX_Y);
  //   glEnd();
  //
  // }
  float ptx_entry = line[0][0]+t_entry*lineV[0];
  float pty_entry = line[0][1]+t_entry*lineV[1];

  float ptx_exit = line[0][0]+t_exit*lineV[0];
  float pty_exit = line[0][1]+t_exit*lineV[1];

  cout<<ptx_entry<<" "<<pty_entry<<endl;
  cout<<ptx_exit<<" "<<pty_exit<<endl;

  glColor3f(0,1,0);
  glLineWidth(5);
  glBegin(GL_LINES);
    glVertex2f(ptx_entry/MAX_X,pty_entry/MAX_Y);
    glVertex2f(ptx_exit/MAX_X,pty_exit/MAX_Y);
  glEnd();
}

void display() {

  glColor3f(1,0,0);
  glBegin(GL_LINES);
    // glVertex2f(1,0);
    // glVertex2f(-1,0);
    // glVertex2f(0,1);
    // glVertex2f(0,-1);
    glVertex2f(line[0][0]/MAX_X,line[0][1]/MAX_Y);
    glVertex2f(line[1][0]/MAX_X,line[1][1]/MAX_Y);
  glEnd();

  glColor3f(1,1,1);
  glBegin(GL_LINE_LOOP);
    for (int i = 0; i < n; i++) {
      glVertex2f(vertices[i][0]/MAX_X,vertices[i][1]/MAX_Y);
    }
  glEnd();

  cyrusBeck(line,vertices,n);
  glFlush();

}

int main(int argc, char  **argv) {
  glutInit(&argc,argv);
  glutInitWindowSize(MAX_X*2,MAX_Y*2);
  glutInitWindowPosition(50,50);
  glutCreateWindow("Window");
  glutDisplayFunc(display);
  glutMainLoop();
  // cyrusBeck();
  return 0;
}
