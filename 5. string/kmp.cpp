#include<bits/stdc++.h>
#define MAX 100010
using namespace std;

int fail[MAX];

void failure(string text)
{
    memset(f,0,MAX);
    fail[0]=0;
    int j = 0;
    int n = text.size();
    for(int i = 1; i < n; i++)
    {
        if(text[i]==text[j])
        {
            fail[i]=++j;
        }
        else
        {
            while(j!=0)
            {
                j = fail[j-1];
                if(text[i]==text[j])
                {
                    fail[i] = ++j;
                    break;
                }
            }
        }
    }
}

bool kmp(string text, string pattern)
{
    int j = 0;
    int n=text.size();
    int m=pattern.size();
    for(int i = 0; i < n; i++)
    {
        if(text[i]==pattern[j])
        {
            if(j==m-1)
            {
                return true;
            }
            j++;
        }
        else
        {
            while(j!=0)
            {
                j = fail[j-1];
                if(text[i]==pattern[j])
                {
                    j++;
                    break;
                }
            }
        }
    }
    return false;
}

int main()
{
    string text;
    cin>>text;
    string pattern;
    failure(text);
    while(1)
    {
        cin>>pattern;
        if(kmp(text,pattern))
        {
            cout<<"substring"<<endl;
        }
        else
        {
            cout<<"not substring"<<endl;
        }
    }
    return 0;
}
