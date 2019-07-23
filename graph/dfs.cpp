/// O(V+E)
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100010];
bool visited[100010];
int nodes,edges;

void dfs(int u)
{
    visited[u]=true;
    printf("%d ",u);
    for(int i=0;i<graph[u].size();i++)
    {
        int v=graph[u][i];
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

void dfs(int u,int p)///without visited flag;
{
    for(int i=0;i<graph[u].size();i++)
    {
        v=graph[u][i];
        if(v!=p)
        {
            dfs(v,u);
        }
    }
}

int main()
{
    scanf("%d %d",&nodes,&edges);
    for(int i=0;i<edges;i++)
    {
       int u,v;
       cin>>u>>v;
       graph[u].push_back(v);
       graph[v].push_back(u);
    }
    for(int i=1;i<=nodes;i++)
    {
        if(!visited[i])dfs(i);
    }
    dfs(1,0);/// mainly for a tree;
    return 0;
}
