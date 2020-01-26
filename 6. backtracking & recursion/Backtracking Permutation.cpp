#include "bits/stdc++.h"
using namespace std;
/*
int position[5], n = 4, Count = 0;
bool taken[5];

void Perm(int idx)
{
    Count++;
    if(idx == n + 1)
    {
        for(int i = 1; i <= n; i ++) cout << position[i] << " ";
        cout << endl;

        return;
    }

    for(int i = 1; i <= n; i ++)
    {
        if(taken[i] == false)
        {
            if((idx == 4 && i != 4) || (i == 4 && idx != 4)) continue;
            taken[i] = true;
            position[idx] = i;

            Perm(idx + 1);

            taken[i] = false;
        }
    }
}
*/
int Elements[] = {1, 1, 2, 2}, position[5], n = 4;
bool taken[5];

void Perm(int idx)
{
    if(idx == n + 1)
    {
        for(int i = 1; i <= n; i ++) cout << position[i] << " ";
        cout << endl;

        return;
    }

    for(int i = 1; i <= n; i ++)
    {
        if(taken[i] == false)
        {
            taken[i] = true;
            position[idx] = Elements[i - 1];

            Perm(idx + 1);

            taken[i] = false;
        }
    }
}

int main()
{
    /*Perm(1);
    cout << Count << endl;
*/

    Perm(1);

    return 0;
}
