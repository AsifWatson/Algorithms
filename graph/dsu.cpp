#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int par[MAX];

void makeset(int n)
{
    par[n]=n;
}

int findd(int r)
{
    if(par[r]==r)
        return r;
    else
    {
        par[r]=findd(par[r]);
        return par[r];
    }
}

void unionn(int a,int b)
{
    int u=findd(a);
    int v=findd(b);
    if(u==v)
    {
        printf("They are already friends\n");
    }
    else
        par[u]=v;
}
