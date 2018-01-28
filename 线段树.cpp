//
//  main.cpp
//  ACM_0127
//
//  Created by admin on 18/1/27.
//  Copyright © 2018年 Amon. All rights reserved.
//
// 区间延迟：当我们改变一段区间的值，当发现有一整段区间都属于我们需要的区间内，那改完这个区间的值，下面子区间的值我们暂且不去修改，给他们做上延迟标记，当需要用时，再去修改
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long int sum[400010];
int _flag[400010];
int A[100010];

void tree_push(int l, int r, int rt)
{
    if (l == r) {
        sum[rt] += A[l];
        return;
    }
    int m = (l+r)/2;
    tree_push(l, m, rt*2);
    tree_push(m+1, r, rt*2+1);
    sum[rt] = sum[rt*2] + sum[rt*2+1];
}

void putdown(int rt,int ln, int rn)
{
    if (_flag[rt]) {
        _flag[rt*2] += _flag[rt];
        _flag[rt*2+1] += _flag[rt];
        sum[rt*2] += ln*_flag[rt];
        sum[rt*2+1] += rn*_flag[rt];
        _flag[rt] = 0;
    }
}

void tree_add(int i, int j, int l, int r, int rt, int data)
{
    if (l >= i && r <= j) {
        sum[rt] += (long long int)(r-l+1)*data;
        _flag[rt] += data;
        return;
    }
    int m = (l+r)/2;
    putdown(rt, m-l+1, r-m);

    if (i <= m ) {
        tree_add(i, j, l, m, rt*2, data);
    }
    if (j > m ) {
        tree_add(i, j, m+1, r, rt*2+1, data);
    }
    sum[rt] = sum[rt*2] + sum[rt*2+1];
}

long long int tree_query(int i, int j, int l, int r, int rt)
{
    if (l >= i && r <= j) {
        return sum[rt];
    }
    int m = (l+r)/2;
    putdown(rt, m-l+1, r-m);
    long long int ans = 0;
    if (i <= m ) {
        ans += tree_query(i, j, l, m, rt*2);
    }
    if (j > m ) {
        ans += tree_query(i, j, m+1, r, rt*2+1);
    }
    return ans;
}

int main()
{
    int N,Q;
    cin >> N >> Q;
    int data;
    for (int i = 1; i <= N; i++) {
        scanf("%d",&A[i]);
    }
    tree_push(1, N, 1);
    char com[3];
    int i,j;
    while (Q--) {
        scanf("%s",com);
        switch (com[0]) {
            case 'C':
                scanf("%d%d%d",&i,&j,&data);
                tree_add(i, j, 1, N, 1, data);
                break;
            case 'Q':
            {
                scanf("%d%d",&i,&j);
                long long int ans = tree_query(i, j, 1, N, 1);
                printf("%lld\n",ans);
            }
                break;
            default:
                break;
        }
    }
    return 0;
}







/*
// B
int sum[200030];

void tree_add(int l, int r, int i, int j, int rt)
{
    if (l == r) {
        sum[rt] += j;
        return;
    }
    int m = (l+r)/2;
    if (i <= m) {
        tree_add(l, m, i, j, rt*2);
    }
    else {
        tree_add(m+1, r, i, j, rt*2+1);
    }
    sum[rt] = sum[rt*2] + sum[rt*2+1];
}

int tree_query(int l, int r, int i, int j, int rt)
{
    if (r < i || l > j) {
        return 0;
    }
    if (i <= l && j >= r) {
        return sum[rt];
    }
    int ans = 0;
    int m = (l+r)/2;
    ans += tree_query(l, m, i, j, rt*2);
    ans += tree_query(m+1, r, i, j, rt*2+1);
    return ans;
}

int main()
{
    int T;
    int _case = 1;
    scanf("%d",&T);
    while (T--) {
        memset(sum, 0, sizeof(sum));
        int N;
        scanf("%d", &N);
        int i = 1;
        for ( ; i <= N; i++) {
            int data;
            scanf("%d",&data);
            tree_add(1, N, i, data, 1);
        }
        printf("Case %d:\n", _case++);
        string command;
        int j = 0;
        while (1) {
            cin >> command;
            if (command[0] == 'E') {
                break;
            }
            cin >> i >> j;
            switch (command[0]) {
                case 'A':
                    tree_add(1, N, i, j, 1);
                    break;
                case 'S':
                    tree_add(1, N, i, -j, 1);
                    break;
                case 'Q':
                {
                    int s = tree_query(1, N, i, j, 1);
                    printf("%d\n", s);
                }
                    break;
                default:
                    cout << "错了啊啊啊啊啊啊" << endl;
                    break;
            }
        }
    }
    return 0;
}

// A
 int main(int argc, const char * argv[]) {
 printf("Hello World!\n");
 return 0;
 }
 */
