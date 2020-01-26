#include<bits/stdc++.h>
using namespace std;

#define maxn 100005

struct info{
    long long sum, prop;
    info(){
        sum = 0, prop = 0;
    }
};

int arr[maxn];
info tree[4 * maxn];

void build(int node, int L, int R)
{
    if(L == R){
        tree[node].sum = arr[L];
        return;
    }

    int leftNode  = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (L + R) / 2;

    build(leftNode, L, mid);
    build(rightNode, mid+1, R);

    tree[node].sum = tree[leftNode].sum + tree[rightNode].sum;
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if(i > e || j < b) return 0;

    if(b >= i && e <= j) return tree[node].sum + carry * (e - b + 1);

    int leftNode  = node * 2;
    int rightNode = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = query(leftNode, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(rightNode, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

void update(int node, int b, int e, int i, int j, long long x)
{
    if(i > e || j < b) return;

    if(b >= i && e <= j){
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }

    int leftNode = node * 2;
    int rightNode = (node * 2) + 1;
    int mid = (b + e) / 2;

    update(leftNode, b, mid, i, j, x);
    update(rightNode, mid + 1, e, i, j, x);

    tree[node].sum = tree[leftNode].sum + tree[rightNode].sum + (e - b + 1) * tree[node].prop;
}

int main()
{

    int n = 7;

    for(int i = 1; i <= n; ++i){
            cin >> arr[i];
    }

    build(1, 1, n);

    update(1, 1, n, pos1, pos2, addValue);

    query(1, 1, n, pos1, pos2);

    return 0;
}
