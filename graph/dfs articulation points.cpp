// O(V+E)
#include "bits/stdc++.h"
using namespace std;

int n, timer; // n = number of nodes
vector<int> graph[100005], low, tin; // graph = adjacency list of graph
vector<bool> visited;

set<int> st;

void dfs(int v, int p=-1)
{
    visited[v]=true;
    tin[v]=low[v]=timer++;

    int children=0;

    for(int to : graph[v])
    {
        if(to==p)continue;
        if(visited[to])low[v]=min(low[v],tin[to]);  // checking for back-edge
        else
        {
            dfs(to,v);
            low[v]=min(low[v],low[to]);
            if(low[to]>=tin[v] && p!=-1)st.insert(v);//IS_CUTPOINT(v);
            children++;
        }
    }

    if(p==-1 && children>1)st.insert(v);//IS_CUTPOINT(v);
}

void findCutpoints()
{
    timer=0;

    visited.assign(n,false);
    tin.assign(n,-1);
    low.assign(n,-1);
    st.clear();

    for(int i=0; i<n; i++)
    {
        if(!visited[i])dfs(i);
    }

    for(auto k : st)cout<<k<<" ";
    cout<<endl;
}

int main()
{
    cin>>n;
    int e;
    cin>>e;

    for(int i=1; i<=e; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    findCutpoints();

    return 0;
}
/*

3----2----1
|    |    |
|    |    |
6----5----4

6
7
1 2
1 4
2 3
2 5
3 6
4 5
5 6

*/
