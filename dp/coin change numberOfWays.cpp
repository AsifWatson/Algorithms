/// number of ways an amount can be made with given coins.
#include<bits/stdc++.h>
using namespace std;

int nways[9];

int main()
{
    int coin[2]={2,4};

    for(int i=0;i<2;i++)
    {
        for(int j=coin[i],k=0;j<=8;j++,k++)
        {
            nways[j]+=nways[k];
        }
    }

    return 0;
}
