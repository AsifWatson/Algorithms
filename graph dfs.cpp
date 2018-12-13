#include <bits/stdc++.h>
using namespace std;

vector<int> adj[128];
bool seen[128];
int n, e;

void dfs(int u)
{
    seen[u]=true;
    printf("%d ",u);
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(!seen[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    scanf("%d %d",&n,&e);
    for(int i=0;i<e;i++)
    {
       int u, v;
       cin >>u>>v;
       adj[u].push_back(v);
       adj[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!seen[i])
        {
            dfs(i);
        }
    }
    return 0;
}
