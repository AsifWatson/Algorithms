// O(V+E)
#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100000];
int visited[100000]={0};
int level[100000];

void addEdge(int v, int w)
{
    graph[v].push_back(w);
    graph[w].push_back(v);
}

void bfs(int s,int n)
{
    for(int i=0;i<n;i++)visited[i]=0;

    queue<int>q;
    q.push(s);
    visited[s]=1;
    level[s]=0;

    while(!q.empty())
    {
        int u=q.front();

        for(int i=0;i<graph[u].size();i++)
        {
            if(!visited[graph[u][i]])
            {
                int v=graph[u][i];
                level[v]=level[u]+1;
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
}

int main()
{
    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,2);
    addEdge(2,0);
    addEdge(2,3);
    addEdge(3,4);

    bfs(2, 4);
    return 0;
}
