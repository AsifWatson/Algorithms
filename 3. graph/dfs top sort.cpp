#include <bits/stdc++.h>
#define CLR(a) memset(a, 0, sizeof(a))

using namespace std;

int n, take[110][110], indegree[110], taken[110];

void topsort()
{
    vector<int> task;
    int i, j, k;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(!indegree[j] && !taken[j])
            {
                taken[j] = 1;
                task.push_back(j);
                for(k=1; k<=n; k++)
                {
                    if(take[j][k])
                    {
                        --indegree[k];
                    }
                }
                break;
            }
        }
    }

    cout<<task[0];

    for(int i=1; i<n; i++)
    {
        cout<<" "<<task[i];
    }

    cout<<endl;

    task.clear();
}

int main()
{
    int a, b, m;
    while(cin>>n>>m)
    {
        if(n==0 && m==0) break;
        for(int i=1; i<=m; i++)
        {
            cin>>a>>b;
            take[a][b] = 1;
            indegree[b]++;
        }
        topsort();
        CLR(take);
        CLR(indegree);
        CLR(taken);
    }
    return 0;
}
