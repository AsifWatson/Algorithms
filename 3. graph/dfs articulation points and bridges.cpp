// O(V+E)
#include<bits/stdc++.h>
using namespace std;

#define maxn 100005

vector<int> graph[maxn];
vector<pair<int,int> > bridges;
set<int> points;

int parent[maxn], discoverTime[maxn], lowestTime[maxn], counter;
bool visited[maxn];

void init()
{
    counter=0;
    for(int i=0; i<maxn; i++)
    {
        parent[i]=-1;
        discoverTime[i]=lowestTime[i]=0;
        visited[i]=false;
        graph[i].clear();
    }
    bridges.clear();
    points.clear();
}

void dfs(int rootNode)
{
    visited[rootNode]=true;
    discoverTime[rootNode]=lowestTime[rootNode]=++counter;

    int child=0;

    for(int i=0; i<graph[rootNode].size(); i++)
    {
        int thisNode=graph[rootNode][i];

        if(!visited[thisNode])
        {
            child++;
            parent[thisNode]=rootNode;

            dfs(thisNode);

            if(lowestTime[thisNode]>discoverTime[rootNode])bridges.push_back({rootNode,thisNode});

            if(parent[rootNode]!=-1 && lowestTime[thisNode]>=discoverTime[rootNode])points.insert(rootNode);

            lowestTime[rootNode]=min(lowestTime[rootNode],lowestTime[thisNode]);
        }

        // checking for back edge only
        else if(visited[thisNode] && thisNode!=parent[rootNode])  // if true there is a back edge
        {
            lowestTime[rootNode]=min(lowestTime[rootNode],discoverTime[thisNode]);
        }
    }

    if(parent[rootNode]==-1 && child>1)points.insert(rootNode);
}

void showPoints()
{
    cout<<"Points : "<<endl;
    for(auto point : points)cout<<point<<" ";
    cout<<endl;
}

void showBridges()
{
    cout<<"Bridges : "<<endl;
    for(auto bridge : bridges)cout<<bridge.first<<" "<<bridge.second<<endl;
}

int main()
{
    int nodes, edges;

    while(cin>>nodes>>edges)
    {
        init();

        for(int i=1; i<=edges; i++)
        {
            int node1, node2;
            cin>>node1>>node2;

            graph[node1].push_back(node2);
            graph[node2].push_back(node1);
        }

        int startNode=1;
        dfs(startNode);
        showPoints();
        showBridges();
    }

    return 0;
}

/*
                    6             7
                   / \           /
                  /   \         /
                 /     \       /
                /       \     /
               /         \   /
              /           \ /
1-----2------3------4------5

7
7
1 2
2 3
3 4
4 5
5 6
3 6
5 7

*/
