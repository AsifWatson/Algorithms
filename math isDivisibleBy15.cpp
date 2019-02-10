#include <bits/stdc++.h>

using namespace std;

int isDivisibleBy15(char str[])
{
    int sum=0;

    for(int i=0;i<strlen(str);i++)
    {
        sum = sum+(str[i]-'0');
    }

    if(sum%3==0 && (((str[strlen(str)-1]-'0')==0) || ((str[strlen(str)-1]-'0')==5)))
        return 1;
    else
        return 0;
}

int main()
{
    char str[1000];

    while(1)
    {
        printf("Take a number:\n");
        scanf("%s",str);
        if(isDivisibleBy15(str))
        {
            printf("Yes %s is divisible by 15\n",str);
        }
        else
        {
            printf("No %s is not divisible by 15\n",str);
        }
    }
    return 0;
}

