#include "bits/stdc++.h"
using namespace std;

const int MAX=(int)2e5+5;

int par[MAX];
bool cycle=false;

void init()
{
    for(int i=0;i<MAX;i++)par[i]=i;
}

int findd(int r)
{
    if(par[r]==r)return r;
    else return par[r]=findd(par[r]);
}

void unionn(int a,int b)
{
    int u=findd(a);
    int v=findd(b);
    if(u!=v) par[u]=v;
    else cycle=true;
}

int main()
{
    int v,e;
    cin>>v>>e;
    init();
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        unionn(a,b);
    }
    if(cycle) cout<<"cycle found"<<endl;
    else cout<<"no cycle here"<<endl;
    return 0;
}

