#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100];
int visited[100]={0};
int level[100];

void addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void bfs(int s, int n)
{
    for(int i=0; i<n; i++)
        visited[i] = 0;

    queue<int>Q;
    Q.push(s);
    visited[s] = 1;
    level[s] = 0;

    while(!Q.empty())
    {
        int u = Q.front();
        for(int i=0; i<adj[u].size(); i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v = adj[u][i];
                level[v] = level[u]+1;
                visited[v] = 1;
                Q.push(v);
            }
        }
        Q.pop();
    }
}

int main()
{
    bfs(1,5);
    return 0;
}
