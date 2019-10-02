#include<bits/stdc++.h>
using namespace std;

#define maxn 100005

int arr[maxn];
int tree[4*maxn];

void build(int node, int L, int R)
{
    if(L==R)
    {
        tree[node]=arr[L];
        return;
    }

    int leftNode=node*2;
    int rightNode=node*2+1;

    int mid=(L+R)/2;

    build(leftNode,L,mid);
    build(rightNode,mid+1,R);

    tree[node]=tree[leftNode]+tree[rightNode];
}

int query(int node, int L, int R, int l, int r)
{
    if(l>R || r<L)return 0;
    if(L>=l && R<=r)return tree[node];

    int leftNode=node*2;
    int rightNode=node*2+1;

    int mid=(L+R)/2;

    int p1=query(leftNode,L,mid,l,r);
    int p2=query(rightNode,mid+1,R,l,r);

    return p1+p2;
}

void update(int node, int L, int R, int pos, int newValue)
{
    if(pos>R || pos<L)return;
    if(L==pos && R==pos)
    {
        tree[node]=newValue;
        return;
    }

    int leftNode=node*2;
    int rightNode=node*2+1;

    int mid=(L+R)/2;

    update(leftNode,L,mid,pos,newValue);
    update(rightNode,mid+1,R,pos,newValue);

    tree[node]=tree[leftNode]+tree[rightNode];
}

int main()
{
    build(1,1,n);
    update(1,1,n,pos,newValue);
    query(1,1,n,l,r);

    return 0;
}
