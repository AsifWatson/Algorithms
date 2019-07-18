#include <bits/stdc++.h>
using namespace std;

int diameter[10001];

int bfs(int init,vector<int>graph[],int n)
{
    int visited[n+1];
    memset(visited,0,sizeof(visited));
    memset(diameter,0,sizeof(diameter));

	queue<int> q;
	q.push(init);
    visited[init]=1;

	while(!q.empty())
    {
		int u=q.front();
		q.pop();
		for(int i=0;i<graph[u].size();i++)
		{
			if(!visited[graph[u][i]])
			{
				visited[graph[u][i]]=1;
				diameter[graph[u][i]]+=diameter[u]+1;
				q.push(graph[u][i]);
			}
		}
	}

	return int(max_element(diameter+1,diameter+n+1)-diameter);
}

int findDiameter(vector<int>graph[],int n)
{
	int init=bfs(1,graph,n);
	int val=bfs(init,graph,n);
	return diameter[val];
}

int main()
{
	int n=6;

	vector<int>graph[n+1];

	graph[1].push_back(2);
	graph[1].push_back(3);
	graph[1].push_back(6);
	graph[2].push_back(4);
	graph[2].push_back(1);
	graph[2].push_back(5);
	graph[3].push_back(1);
	graph[4].push_back(2);
	graph[5].push_back(2);
	graph[6].push_back(1);

	printf("Diameter of n-ary tree is %d\n",findDiameter(graph,n));

	return 0;
}
