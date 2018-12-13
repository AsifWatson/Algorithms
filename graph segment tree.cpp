#include<bits/stdc++.h>
using namespace std;

#define mx 100001

int arr[mx];
int tree[mx*3];

void build(int node,int st,int ed)
{
    if(st==ed)
    {
        tree[node]=arr[st];
        return;
    }
    int leftNode=node*2;
    int rightNode=node*2+1;
    int mid=(st+ed)/2;
    build(leftNode,st,mid);
    build(rightNode,mid+1,ed);
    tree[node]=tree[leftNode]+tree[rightNode];
}

int query(int node,int st,int ed,int i,int j)
{
    if(i>ed || j<st)
    {
        return 0;
    }
    if(st>=i && ed<=j)
    {
        return tree[node];
    }
    int leftNode=node*2;
    int rightNode=node*2+1;
    int mid=(st+ed)/2;
    int p1=query(leftNode,st,mid,i,j);
    int p2=query(rightNode,mid+1,ed,i,j);
    return p1+p2;
}
void update(int node,int st,int ed,int i,int newValue)
{
    if(i>ed || i<st)
    {
        return;
    }
    if(st>=i && ed<=i)
    {
        tree[node]=newValue;
        return;
    }
    int leftNode=node*2;
    int rightNode=node*2+1;
    int mid=(st+ed)/2;
    update(leftNode,st,mid,i,newValue);
    update(rightNode,mid+1,ed,i,newValue);
    tree[node]=tree[leftNode]+tree[rightNode];
}


int main()
{
    return 0;
}
