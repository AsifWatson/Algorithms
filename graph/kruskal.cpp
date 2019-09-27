#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u,v,w;
};

vector<edge>graph,output;
int parent[200005],mstValue=0;

bool compare(edge a, edge b)
{
    return a.w<b.w;
}

int Find(int r)
{
    if(parent[r]==r)
        return r;
    return parent[r]=Find(parent[r]);
}

void initPar(int r)
{
    for(int i=0 ; i<r ; i++)
    {
        parent[i]=i;
    }
}
void kruskal(int n)
{
    sort(graph.begin(), graph.end(), compare);
    initPar(n);
    int cnt=0;
    for(int i=0 ; i<(int)graph.size() ; i++)
    {
        int uPr=Find(graph[i].u);
        int vPr=Find(graph[i].v);
        if(uPr!=vPr)
        {
            if(cnt==n-1)
                break;
            output.push_back(graph[i]);
            mstValue+=graph[i].w;
            parent[uPr]=vPr;
            cnt++;
        }
    }

}


int main()
{
    int n,e;
    cin>>n>>e;

    for(int i=0 ; i<e ; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edge input;
        input.u=u;
        input.v=v;
        input.w=w;
        graph.push_back(input);
    }

    kruskal(n);

    cout<<"MST Value : "<<mstValue<<endl;
    for(int i=0 ; i<(int)output.size() ; i++)
    {
        cout<<output[i].u<<" "<<output[i].v<<" "<<output[i].w<<endl;
    }

    return 0;
}
