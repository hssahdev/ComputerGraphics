#include "graphics.h"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> P1;
pair<int, int> P2;
pair<int, int> *arr;
int n;

pair<int, int> operator+(const pair<int, int> p1, const pair<int, int> p2)
{
    pair<int, int> ans = make_pair(p1.first + p2.first, p1.second + p2.second);
    return ans;
}

pair<int, int> operator-(const pair<int, int> p1, const pair<int, int> p2)
{
    pair<int, int> ans = make_pair(p1.first - p2.first, p1.second - p2.second);
    return ans;
}

pair<int, int> operator*(double t, const pair<int, int> p)
{
    pair<int, int> ans = make_pair((int)(t * p.first), (int)(t * p.second));
    return ans;
}

pair<int, int> getNormal(pair<int, int> edge)
{
    pair<int, int> normal = make_pair( abs(edge.first), abs(edge.second));
    int x = edge.first;
    int y = edge.second;
    if(x > 0 && y > 0)
    {
        normal.first = -normal.first;
        normal.second = normal.second;
    }
    else if(x < 0 && y > 0)
    {
        normal.first = -normal.first;
        normal.second = -normal.second;
    }
    else if(x < 0 && y < 0)
    {
        normal.first = normal.first;
        normal.second = -normal.second;
    }
    else
    {
        normal.first = normal.first;
        normal.second = normal.second;
    }

    return normal;
}

double dotP(pair<int, int> p1, pair<int, int> p2)
{
    return 1.0 * (p1.first * p2.first + p1.second * p2.second);
}

double generateT(pair<int, int> vector, pair<int, int> P)
{
    pair<int, int> normal = getNormal(vector);
    double denom = (-1.0) * dotP(normal, P2 - P1);
    if (denom == 0.0)
    {
        return INT16_MAX;
    }
    double num = dotP(normal, P1 - P);
    return num / denom;
}

void linecustom(pair<int, int> p1, pair<int, int> p2)
{
    line(p1.first, p1.second, p2.first, p2.second);
}

void display(){

    pair<int, int> vectors[n];
    for (int i = 0; i < n; i++)
    {
        vectors[i] = arr[(i + 1) % n] - arr[i];
        linecustom(arr[(i + 1) % n], arr[i]);
    }

    cout << "Enter coordinates of line : ";
    cin >> P1.first >> P1.second >> P2.first >> P2.second;

    // linecustom(P1, P2);
    // delay(3000);

    double t1 = INT16_MAX;
    double t2 = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        double t = generateT(vectors[i], arr[i]);
        cout<<"t : "<<t<<endl;
        if (t >= 0 && t <= 1)
        {
            if (t1 == INT16_MAX)
            {
                t1 = t;                
            }
            else if (t2 == INT16_MAX)
                t2 = t;
        }
    }

    if (t1 < t2)
    {
        cout<<"jdbvjdbvjv\n";
        linecustom(P1 + t1 * (P2 - P1), P1 + t2 * (P2 - P1));
    }
    else
    {
        linecustom(P1, P2);
    }

    glFlush();
}

int main(int argc, char **argv)
{

    glutInit(&argc,argv);
    initializeWindow(500,500,"clipping");
    
    cout << "Enter number of points : ";
    cin >> n;

    arr = new pair<int, int>[n];
    cout << "Enter the points\n";
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = make_pair(x, y);
    }
    
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}