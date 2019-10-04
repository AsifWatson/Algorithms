// O(n log n)

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

int main()
{
    seive();

    for(int i=0; i<pr.size(); i++)
    {
        cout<<pr[i]<<endl;
    }

    return 0;
}
