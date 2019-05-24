#include<iostream>

using namespace std;

float tetra [4][3][3] = {
	{{1,1,1},{8,9,3},{5,3,8}},
	{{8,9,3},{5,3,8},{7,-3,2}},
	{{1,1,1},{5,3,8},{7,-3,2}},
	{{1,1,1},{8,9,3},{7,-3,2}}
};

float tetraMod [4][3][2] = {
	{{1,1},{8,9},{5,3}},
	{{8,9},{5,3},{7,-3}},
	{{1,1},{5,3},{7,-3}},
	{{1,1},{8,9},{7,-3}}
};

char str[][5] = {"BG","ACB","ACD","BCD","ADB"}; 

float Xmax = 8; 
float Xmin = 1; 

float Ymax = 9; 
float Ymin = -3;

float Zmax = 8; 
float Zmin = 1; 

float planeEqn[5][4] = {
	{0,0,0,0},
	{16,5,-76,55}, //ACB
	{52,-41,-18,7}, //ACD
	{66,-8,30,-546}, //BCD
	{30,38,-28,-40} //ADB
	};

float linefunc(float a[2],float b[2], float point[2]){
	return point[1]-a[1] - ((a[1]-b[1])/(a[0]-b[0])) * (point[0]-a[0]);
}

bool inTriangle(float a[2], float b[2], float c[2] , float point[2]){
	if ((linefunc(a,b,c)*linefunc(a,b,point)>=0) && (linefunc(a,c,b)*linefunc(a,c,point)>=0) && (linefunc(c,b,a)*linefunc(c,b,point)>=0))
		return true;
	else return false;
}

float getZ(int index, float x, float y){
	return -((planeEqn[index][0]*x) + (planeEqn[index][1]*y) + planeEqn[index][3])/planeEqn[index][2];
}

int main(int argc, char const *argv[])
{
	for(int i=Xmin;i<=Xmax;i++){
		for(int j=Ymin;j<Ymax;j++){
			cout<<"Point "<<i<<","<<j<<": \n";
			int ansIndex = 0;
			float currentZ = 100;
			float point[2] = {i,j};
			for(int k=1;k<=4;k++){
				float z = getZ(k,i,j);
				bool chk = inTriangle(tetraMod[k][0],tetraMod[k][1],tetraMod[k][2],point);
				if(z<currentZ && chk){
					ansIndex = k;
					currentZ = z;
				}
				cout<<"\t\t"<<str[k]<<": "<<z<<" "<<chk; 
				cout<<endl;
			}
			// if(ansIndex==0)
			// 	cout<<"Ans: "<<str[4];
			// else
			cout<<"\t\t\t\t\t"<<str[ansIndex];
			cout<<endl;
			cout<<endl;
		}
	}
		
	return 0;
}