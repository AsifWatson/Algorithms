///O(V+E)

#inlude "bits/std++.h"
using namespace std;

int fx[]={1,-1,0,0};
int fx[]={0,0,1,-1};

int visited[1005],grid[1005][1005],dest[1005][1005],row,col;

void bfs(int x,int y)
{
    memset(visited,0,sizeof(visited));
    visited[x][y]=1;

    queue<pair<int,int> >q;
    q.push({source_x,source_y});

    while(!q.empty())
    {
        pair<int,int> top=q.top();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int tx=top.first+fx[i];
            int ty=top.second+fy[i];
            if(tx>=0 && tx<row && ty>=0 && ty<col && grid[tx][ty]!=-1 && !visited[tx][ty])
            {
                visited[tx][ty]=1;
                dest[tx][ty]=dest[top.first][top.second]+1;
                q.push({tx,ty});
            }
        }
    }
}

int main()
{
    return 0;
}
