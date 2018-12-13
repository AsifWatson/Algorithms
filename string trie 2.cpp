#include<bits/stdc++.h>
#define N 300005
using namespace std;

int ch[N][10], ss=0, isWord[N];
///int ch[N][26], ss=0, isWord[N];

void inl()
{
    memset(ch, 0, sizeof ch);
    memset(isWord, 0, sizeof isWord);
    ss=0;
}

void insertt(string s)
{
    int u=0;
    for(int i=0; i<s.size(); i++)
    {
        int c=s[i]-'0';
        ///int c=s[i]-'a';
        if(!ch[u][c])
        {
            ch[u][c]=++ss;
        }
        u=ch[u][c];
    }
    isWord[u]=1;
    ///isWord[u]++;
}

bool searchh(string s)/// whether the string is present or not.
{
    int u=0;
    for(int i=0; i<s.size(); i++)
    {
        int c=s[i]-'0';
        ///int c=s[i]-'a';
        u=ch[u][c];
    }
    if(isWord[u]==1)
    {
        return true;
    }
    return false;
}

int searchh(string s) /// returns how much times the string is present;
{
    int u=0;
    for(int i=0; i<s.size(); i++)
    {
        int c=s[i]-'0';
        u=ch[u][c];
    }
    if(isWord[u]>0)
    {
        return isWord[u];
    }
    return 0;
}

int main()
{
    return 0;
}
