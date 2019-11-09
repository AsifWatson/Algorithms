#include "bits/stdc++.h"
using namespace std;
/*
int Array[3], k = 3, n = 5;

void Comb(int idx, int Left)
{
    if(Left > n - idx + 1) return;

    if(idx == n + 1)
    {
        for(int i = 0; i < k; i ++) cout << Array[i] << " ";
        cout << endl;

        return;
    }

    if(Left)
    {
        Array[k - Left] = idx;
        Comb(idx + 1, Left - 1);
    }

    Comb(idx + 1, Left);
}
*/

int Array[3], n = 5, k = 2;
void Comb(int idx, int last)
{
    if(idx == k + 1)
    {
        for(int i = 1; i <= k; i ++) cout << Array[i] << " ";
        cout << endl;

        return;
    }

    for(int i = last + 1; i <= n - k + idx; i ++)
    {
        Array[idx] = i;
        Comb(idx + 1, i);
    }
}

int main()
{
    //Comb(1, k);

    Comb(1, 0);

    return 0;
}
