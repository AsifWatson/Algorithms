#include<bits/stdc++.h>
using namespace std;

int cost[1001],weight[1001];

int dp[1001][31];

int fun(int i,int w,int capacity,int n)
{
    if(i==n+1) return 0;

    if(dp[i][w]!=-1) return dp[i][w];

    int profit1=0,profit2=0;
    if(w+weight[i]<=capacity) profit1=cost[i]+fun(i+1,w+weight[i],capacity,n);

    profit2=fun(i+1,w,capacity,n);

    dp[i][w]=max(profit1,profit2);

    return dp[i][w];
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>cost[i];
        cin>>weight[i];
    }
    int capacity;
    cin>>capacity;
    memset(dp,-1,sizeof(dp));
    cout<<fun(1,0,capacity,n)<<endl;
    return 0;
}
