#include "bits/stdc++.h"
using namespace std;

const int MX = 100;
int queen[MX];
int column[MX], diagonal1[MX + MX], diagonal2[MX + MX];
int totalSolution;

void nqueen(int now, int n)
{
    if(now == n + 1) // complete
    {
        totalSolution++;

        for(int i = 1; i <= n; i++)
        {
            printf("(%d , %d) ", i, queen[i]);
        }
        printf("\n");

        return;
    }

    for(int i = 1; i <= n; i++)
    {
        if(column[i] || diagonal1[i + now] || diagonal2[n + now - i]) continue;
        // As i - now can be negative thats why we are adding n
        queen[now] = i; // position of column

        column[i] = 1;
        diagonal1[i + now] = 1; // down left /
        diagonal2[n + now - i] = 1;  // down right \

        nqueen(now + 1, n);

        column[i] = 0;
        diagonal1[i + now] = 0;
        diagonal2[n + now - i] = 0;
    }
}

int main()
{
    nqueen(1, 4);

    cout << totalSolution << endl;

    return 0;
}
