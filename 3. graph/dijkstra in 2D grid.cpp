#include "bits/stdc++.h"
using namespace std;

const int infinity=INT_MAX;
int row, col, grid[1005][1005], min_cost[1005][1005];
bool visited[1005][1005];

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

struct data
{
    int Row,Col,Cost;
    data(){}
    data(int ROW, int COLUMN, int COST)
    {
        Row=ROW;
        Col=COLUMN;
        Cost=COST;
    }
    bool operator < (const data& p) const
    {
        return Cost > p.Cost;
    }
};

bool insideGrid(int r,int c) // checks whether the cell is inside the grid or not
{
    return ((r>=1 && r<=row) && (c>=1 && c<=col));
}

bool destinationCell(int r,int c) // checks whether last cell is reached or not
{
    return (r==row && c==col);
}

void dijkstra()
{
    priority_queue<data> pq;
    data Data;

    pq.push(data(1,1,grid[1][1]));
    min_cost[1][1]=grid[1][1];

    while(!pq.empty())
    {
        Data=pq.top();
        pq.pop();

        if(visited[Data.Row][Data.Col])continue;
        visited[Data.Row][Data.Col]=true;

        /*if(destinationCell(Data.Row,Data.Col))
        {
            printf("%d\n",Data.Cost);
            break;
        }*/

        for(int i=0;i<4;i++)
        {
            int r=Data.Row+dx[i];
            int c=Data.Col+dy[i];

            if(insideGrid(r,c) && (min_cost[r][c] > min_cost[Data.Row][Data.Col]+grid[r][c]))
            {
                min_cost[r][c] = min_cost[Data.Row][Data.Col]+grid[r][c];
                pq.push(data(r,c,min_cost[r][c]));
            }
        }
    }

    cout<<min_cost[row][col]<<endl;
}

int main()
{

    cin>>row>>col;

    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            cin>>grid[i][j];
        }
    }

    for(int i=1; i<=row; i++)
    {
        for(int j=1; j<=col; j++)
        {
            visited[i][j]=false;
            min_cost[i][j]=infinity;
        }
    }

    dijkstra();

    return 0;
}
