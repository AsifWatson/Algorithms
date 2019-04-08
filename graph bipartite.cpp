#include "bits/stdc++.h"
#define MAX 2000005
using namespace std;

vector<int> graph[MAX];
int visited[MAX];
int color[MAX];

void addEdge(int v,int w)
{
    graph[v].push_back(w);
    graph[w].push_back(v);
}

void bfs(int src)
{
	memset(color,0,sizeof(color));
	memset(visited,0,sizeof(visited));

	color[src]=1;
	visited[src]=1;

	queue<int> q;
	q.push(src);

	while(!q.empty())
	{
		int u=q.front();
		q.pop();

		for(int i=0;i<graph[u].size();i++)
		{
            int v=graph[u][i];
            if(!visited[v])
            {
                if(color[u]==1)color[v]=0;
                if(color[u]==0)color[v]=1;
                visited[v]=1;
                q.push(v);
            }
		}
	}
}

bool bipartite(int src)
{
    memset(visited,0,sizeof(visited));

    visited[src]=1;

    queue<int> q;
    q.push(src);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            int v=graph[u][i];
            if(color[v]==color[u])return false;
            if(visited[v]==0){visited[v]=1;q.push(v);}
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
	for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        addEdge(a,b);
    }

	bfs(1);

    if(bipartite(1))cout<<"Bipartite"<<endl;
    else cout<<"Not Bipartite"<<endl;

	return 0;
}
