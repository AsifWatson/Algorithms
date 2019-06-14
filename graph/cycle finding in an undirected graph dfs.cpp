#include "bits/stdc++.h"
using namespace std;

const int MAX=(int)2e5+5;

vector<int> graph[MAX];
bool visited[MAX],cycle=false;

void addEdge(int a,int b)
{
    graph[a].push_back(b);
    graph[b].push_back(a);
}

void dfs(int u,int p)
{
    if(visited[u]==true) {cycle=true;return;}
    visited[u]=true;
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(v!=p)
        {
            dfs(v,u);
        }
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=1;i<=e;i++)
    {
        int a,b;
        cin>>a>>b;
        addEdge(a,b);
    }
    dfs(1,0);
    if(cycle) cout<<"cycle found"<<endl;
    else cout<<"no cycle here"<<endl;
    return 0;
}
