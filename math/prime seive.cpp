#include<bits/stdc++.h>
using namespace std;

int Prime[300000],nPrime;
int mark[1000002];

void seive(int n)
{
    int i,j,limit=sqrt(n*1)+2;

    mark[1]=1;

    for(i=4;i<=n;i+=2)
        mark[i]=1;

    Prime[nPrime++]=2;

    for(i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
            Prime[nPrime++]=i;
            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=i*2)
                {
                    mark[j]=1;
                }
            }
        }
    }
}

int main()
{
    return 0;
}
