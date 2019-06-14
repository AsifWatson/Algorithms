#include <bits/stdc++.h>
#define mx 20010

using namespace std;

vector<int> adj[mx], cost[mx];
const int infinity = 1000000000;

struct data
{
    int node, weight;
    bool operator < ( const data& p ) const
    {
        return weight > p.weight;
    }
};

int dijkstra(int source, int destination)
{
    int d[mx];
    for(int i=0; i<=mx; i++)
        d[i] = infinity;

    priority_queue<data> pq;
    data u, v;
    u.node = source, u.weight = 0;
    pq.push(u);
    d[source] = 0;

    while(!pq.empty())
    {
        u = pq.top();
        pq.pop();
        int ucost = d[u.node];

        for(int i=0; i<adj[u.node].size(); i++)
        {
            v.node = adj[u.node][i], v.weight = cost[u.node][i] + ucost;
            // relaxing :)
            if(d[v.node] > v.weight)
            {
                d[v.node] = v.weight;
                pq.push( v );
            }
        }
    }
    for(int i=0;i<8;i++)
    {
        printf("d[%d] = %d\n",i+1,d[i+1]);
    }
    return d[destination];
}

int main()
{
    int n, e, src, dest;
    while(scanf("%d %d", &n, &e)==2)
    {
        while(e--)
        {
            int u, v, w;
            cin>>u>>v>>w;

            adj[u].push_back(v);
            adj[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        cin>>src>>dest;
        int ans = dijkstra(src, dest);
        cout<<ans<<endl;
    }
    return 0;
}
