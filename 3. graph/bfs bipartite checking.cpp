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

bool bipartite(int src)
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
            if(color[u]==1)
            {
                if(color[v]==1)return false;
                else color[v]=2;
            }
            if(color[u]==2)
            {
                if(color[v]==2)return false;
                else color[v]=1;
            }
            if(!visited[v]){visited[v]=1;q.push(v);}
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

    if(bipartite(1))cout<<"Bipartite"<<endl;
    else cout<<"Not Bipartite"<<endl;

	return 0;
}
