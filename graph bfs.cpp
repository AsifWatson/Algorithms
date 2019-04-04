#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

vector<int> graph[100];
int visited[100]={0};
int level[100];


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
        for(int i=0; i<graph[u].size(); i++)
        {
            if(visited[graph[u][i]]==0)
            {
                int v = graph[u][i];
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
    IOS
    return 0;
}
