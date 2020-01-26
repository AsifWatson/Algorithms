#include "bits/stdc++.h"
using namespace std;

int parent[105];

int Find(int r)
{
    if(parent[r]==r)return r;
    return parent[r]=Find(parent[r]);
}

void initPar(int n)
{
    for(int i=0 ; i<n ; i++)parent[i]=i;
}

struct data
{
    int u,v;
    double w;
    bool operator < (const data &p) const
    {
        return w < p.w;
    }
};

double kruskal(int n, vector<data> graph, int mstValue=0)
{
    sort(graph.begin(),graph.end());
    initPar(n);

    for(int i=0; i<graph.size(); i++)
    {
        int uPr=Find(graph[i].u);
        int vPr=Find(graph[i].v);

        if(uPr!=vPr)
        {
            parent[uPr]=vPr;
            mstValue+=graph[i].w;
            //output.push_back(graph[i]);  // if needed to show the tree.
        }
    }
    return mstValue;
}

int main()
{
    int n;
    cin>>n;

    vector<data> graph;

    for(int i=0; i<n; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        data input;
        input.u=u;
        input.v=v;
        input.w=w;
        graph.push_back(input);
    }

    cout<<fixed<<setprecision(2)<<kruskal(n,graph)<<endl;

    return 0;
}
