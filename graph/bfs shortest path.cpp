/// O(V+E)

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[8];

void add_edge(int src, int dest)
{
	graph[src].push_back(dest);
	graph[dest].push_back(src);
}

bool BFS(int src, int dest, int v,int pred[], int dist[])
{
	list<int> lst;
	bool visited[v];

	for(int i=0;i<v;i++)
    {
		visited[i]=false;
		dist[i]=INT_MAX;
		pred[i]=-1;
	}

	visited[src]=true;
	dist[src]=0;
	lst.push_back(src);

	while(!lst.empty())
    {
		int u=lst.front();
		lst.pop_front();
		for(int i=0;i<graph[u].size();i++)
		{
			if(!visited[graph[u][i]])
			{
				visited[graph[u][i]]=true;
				dist[graph[u][i]]=dist[u]+1;
				pred[graph[u][i]]=u;

				lst.push_back(graph[u][i]);

				if(graph[u][i]==dest)
				return true;
			}
		}
	}
	return false;
}

void printShortestDistance(int s,int dest, int v)
{
	int pred[v],dist[v];

	if(BFS(s,dest,v,pred,dist)==false)
	{
		cout<<"Given source and destination are not connected"<<endl;;
		return;
	}

	vector<int> path;
	int crawl=dest;
	path.push_back(crawl);

	while(pred[crawl]!=-1)
    {
		path.push_back(pred[crawl]);
		crawl=pred[crawl];
	}

	cout<<"Shortest path length is : "<<dist[dest]<<endl;

	cout<<"Path is:"<<endl;
	for(int i=path.size()-1;i>=0;i--)cout<<path[i]<<" ";
}

int main()
{
	int v=8;
	add_edge(0,1);
	add_edge(0,3);
	add_edge(1,2);
	add_edge(3,4);
	add_edge(3,7);
	add_edge(4,5);
	add_edge(4,6);
	add_edge(4,7);
	add_edge(5,6);
	add_edge(6,7);
	int source=0,dest=7;
	printShortestDistance(source,dest,v);
	return 0;
}
