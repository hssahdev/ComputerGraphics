#define GL_SILENCE_DEPRECATION
#include "graphics.h"
#include<iostream>
#include<bits/stdc++.h>
#include<unistd.h>

using namespace std;



int vertices[][2] = {{200,24},{134,23},{25,356},{356,345},{400,301},{264,230}};
int n = 6;
int minY;
int maxY;

struct edge
{
	int ymin;
	int ymax;
	float x_of_ymin;
	float inverse_slope;
	bool taken;
};

int** sortVertices(){
	int **sorted = new int*[n];

	for(int i=0;i<n;i++)
		sorted[i]=new int[2];

	for(int i =0;i<n;i++){
		sorted[i][0] = vertices[i][0];
		sorted[i][1] = vertices[i][1];
	}

	for(int i =0;i<n;i++){
		for(int j=i;j<n;j++){
			if(sorted[i][1]>sorted[j][1]){
				int* temp = sorted[j];
				sorted[j] = sorted[i];
				sorted[i] = temp;
			}
		}
	}

	return (int**)sorted;
}

edge getEdge(int x1, int y1, int x2, int y2){
	edge ed;
	if(y2>y1)
		{	ed.ymax=y2;
			ed.x_of_ymin=x1;
			ed.ymin=y1;
			}
	else
		{	ed.ymax=y1;
			ed.x_of_ymin=x2;
			ed.ymin=y2;
			}
	ed.inverse_slope = (float)(x2-x1)/(float)(y2-y1);
	return ed;

}

void printEdge(edge e){
		cout << "\t Ymax: " << e.ymax<<endl;
        cout << "\t X_of_Ymin: " << e.x_of_ymin<<endl;
        cout << "\t inverse_slope: " << e.inverse_slope<<endl;
        cout<<"\n";
}

void showlist(list <edge> g)
{
    list <edge> :: iterator it;
    for(it = g.begin(); it != g.end(); ++it) {
        printEdge(*it);
    }
    cout << '\n';
}

list<edge>* globalEdgeTable(){

	int** sortedV = sortVertices();
	minY = sortedV[0][1];
	maxY = sortedV[n-1][1];
	list<edge> *edgetable = new list<edge>[sortedV[n-1][1]-sortedV[0][1]+1];

	int ind = 0;

	for(int i=0;i<maxY-minY;i++){
		if(sortedV[ind][1]==(i+minY)){
			for(int j=0;j<n;j++){
				if(vertices[j][1]==(i+minY)){

					if(vertices[j][1]<vertices[(j+1)%n][1])
						edgetable[i].push_back(getEdge(vertices[j][0],vertices[j][1],vertices[(j+1)%n][0],vertices[(j+1)%n][1]));
					if(j-1<0 && vertices[j][1]<vertices[n-1][1]){
						edgetable[i].push_back(getEdge(vertices[j][0],vertices[j][1],vertices[n-1][0],vertices[n-1][1]));
					}
					else if(vertices[j][1]<vertices[(j-1)%n][1])
						edgetable[i].push_back(getEdge(vertices[j][0],vertices[j][1],vertices[(j-1)%n][0],vertices[(j-1)%n][1]));
				}
			}
			ind++;
			if(ind==n)
				break;
		}
	}

	return edgetable;
}
void removeEdge(int a,list<edge> *aet){
	for (list <edge> :: iterator i = aet->begin(); i != aet->end(); ++i)
	{
		const edge t = *i;
		if(t.ymax == a+minY){

			// cout<<"Removed :"<<t.ymax<<endl;
			aet->erase(i);
		}
	}
}


void mergeList(list <edge>* source, list <edge> *dest){
	for (list <edge> :: iterator i = source->begin(); i != source->end(); i++)
	{
		dest->push_back(*i);
	}
}

void colorFill(int r,int g, int b){

	list<edge> *edgeTable = globalEdgeTable();
	list<edge> aet;

	for(int i=0;i<maxY-minY;i++){
		if(!edgeTable[i].empty()){
			// cout<<i<<"\n";
			removeEdge(i,&aet);
			mergeList(&edgeTable[i],&aet);
			// showlist(edgeTable[i]);
		}
	// cout<<"Adsf";
		glColor3f(r,g,b);
		glBegin(GL_LINES);
		for (list <edge> :: iterator j = aet.begin(); j != aet.end(); j++)
		{
			// printEdge(*j);
			glVertex2i((int)j->x_of_ymin,i+minY);
			j->x_of_ymin +=j->inverse_slope;

		}
		glEnd();
	}
}

void display(){

   	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
		glColor3f(0,0,1);
		for(int i=0;i<n;i++)
			glVertex2i(vertices[i][0],vertices[i][1]);
	glEnd();

	colorFill(0,1,0);
	glFlush();
}

int main(int argc, char **argv)
{
	/* code */
	glutInit(&argc,argv);
	initializeWindow(500,500,"Filling");
	glutDisplayFunc(display);
	glutMainLoop();

	// colorFill(0,0,1);


	return 0;
}
