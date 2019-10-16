//O(n) // O(n log log n)

#include<bits/stdc++.h>
using namespace std;

const int N = 1000005;    //10000000;
int lp[N+1], prime[N+1];  // lp[] = lowest prime that divides it
vector<int> pr;

void seive()
{
    for(int i=2; i<=N; i++)
    {
        if(lp[i]==0)
        {
            lp[i]=i;
            prime[i]=1;  //if prime[i]==1 => it is prime;
            pr.push_back(i);
        }

        for(int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; j++)
        {
            lp[i*pr[j]] = pr[j];
        }
    }
}

/*
const int n=1000000;
int mark[n+5],prime[n+5],nprime;
void seive()
{
    for(int i=2; i<=n; i++)mark[i]=1;  /// initializing mark[i]==1 => prime;

    for(int i=4; i<=n; i+=2)mark[i]=0;

    prime[nprime++]=2;

    for(int i=3; i<=n; i+=2)
    {
        if(mark[i])
        {
            prime[nprime++]=i;

            if(i <= sqrt(n)+1)
            {
                for(int j=i*i; j<=n; j+=i*2)mark[j]=0;
            }
        }
    }
}
*/

int main()
{
    seive();

    return 0;
}
