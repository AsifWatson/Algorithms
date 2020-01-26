#include<bits/stdc++.h>
using namespace std;
#define N 1000000

bool mark [N];
vector <long long int> primeList;

void sieve ()
{
    memset(mark, true, sizeof (mark));
    mark [0] = mark [1] = false;

    for(int i=4;i<N;i+=2)mark[i]=false;

    for(int i=3;i*i<=N;i++ )
    {
        if(mark[i])
        {
            for(int j=i*i;j<N;j+=2*i)mark[j]=false;
        }
    }
    primeList.push_back(2);

    for(int i=3;i<N;i+=2)
    {
        if(mark[i])primeList.push_back(i);
    }
}

bool isPrime(long long int n)
{
    if (n<N) return mark[n];

    long long int index = 0;

    while (primeList[index]*primeList[index]<=n)
    {
        if (n%primeList[index]==0) return false;
        index++;
    }

    return true;
}
