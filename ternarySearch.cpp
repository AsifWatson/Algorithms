#include<bits/stdc++.h>
using namespace std;


struct point
{
    double x,y;
};

double dist(point p1,point p2)
{
    return sqrt(((p1.x-p2.x)*(p1.x-p2.x))+((p1.y-p2.y)*(p1.y-p2.y)));
}

point p[4];

double ternarySearch()
{
    double left,right;
    int num=64;

    while(num--)
    {
        point fa,la;
        fa.x=(2*p[1].x + p[2].x)/3.0;
        fa.y=(2*p[1].y + p[2].y)/3.0;
        
        la.x=(p[1].x + 2*p[2].x)/3.0;
        la.y=(p[1].y + 2*p[2].y)/3.0;
        
        left=dist(fa,p[3]);
        right=dist(la,p[3]);

        if(left>right){p[1]=fa;}
        else{p[2]=la;}
    }

    return abs(left+right)/2;
}

int main()
{
    ternarySearch();
}
