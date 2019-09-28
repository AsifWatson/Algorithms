// O(V+E)

#include "bits/stdc++.h"
#define mx 20010

using namespace std;

vector<int> graph[mx], cost[mx];
const int infinity = 2000000000;
int n,e;

struct data
{
    int node, weight;
    bool operator < (const data& p) const
    {
        return weight > p.weight;
    }
};

int dijkstra(int source, int destination)
{
    int dist[mx],parent[mx];
    for(int i=0; i<mx; i++)
    {
        dist[i] = infinity;
        parent[i] = -1;
    }

    priority_queue<data> pq;

    data u, v;
    u.node=source, u.weight=0;
    pq.push(u);
    dist[source]=0;

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();

        int ucost = dist[u.node];

        for(int i=0; i<graph[u.node].size(); i++)
        {
            v.node=graph[u.node][i], v.weight=cost[u.node][i]+ucost;
            if(dist[v.node] > v.weight)
            {
                dist[v.node]=v.weight;
                parent[v.node]=u.node;
                pq.push(v);
            }
        }
    }

    cout<<"COST : "<<dist[destination]<<endl;

    vector<int> route;
    int par=destination;
    route.push_back(par);

    while(true)
    {
        par=parent[par];
        route.push_back(par);
        if(par==source)break;
    }

    reverse(route.begin(),route.end());

    cout<<"PATH : ";
    for(auto r : route)cout<<r<<" ";
    cout<<endl;
    //return dist[destination];
}

int main()
{
    int src, dest;
    while(scanf("%d %d", &n, &e)==2)
    {
        while(e--)
        {
            int u, v, w;
            cin>>u>>v>>w;

            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        cin>>src>>dest;
        dijkstra(src, dest);
    }
    return 0;
}
