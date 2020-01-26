#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,a,b=0,c=0;
    char str[100];
    char str1[100];
    scanf("%s",str);
    scanf("%s",str1);
    for(i=0;i<strlen(str);i++)
    {
        a=i;
        c=0;
        if(str[a]==str1[0])
        {
            for(j=0;j<strlen(str1);j++)
            {
                if(str[a++]==str1[j])
                {
                    c++;
                }
            }
        }
        if(strlen(str1)==c)
        {
            b=1;
            break;
        }
    }
    if(b==1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    
    return 0;
}



