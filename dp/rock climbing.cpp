#include<bits/stdc++.h>
using namespace std;

long long row,col,matrix[1000][1000],dp[1000][1000];

long long call(int i,int j)
{
    if((i>=0 && i<row) && (j>=0 && j<col))
    {
        if(dp[i][j]!=-1) return dp[i][j];
        long long ret1,ret2,ret3;
        ret1=call(i+1,j)+matrix[i][j];
        ret2=call(i+1,j+1)+matrix[i][j];
        ret3=call(i+1,j-1)+matrix[i][j];
        dp[i][j]=max(ret1,max(ret2,ret3));
        return dp[i][j];
    }
    else return 0;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%lld %lld",&row,&col);
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%lld",&matrix[i][j]);
        }
    }
    printf("%lld\n",call(0,0));
    return 0;
}
