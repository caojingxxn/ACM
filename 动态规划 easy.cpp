//
//  main.cpp
//  ACM_0203
//
//  Created by admin on 18/2/3.
//  Copyright © 2018年 Amon. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;


int a[100010];

int main()
{
    int T;
    cin >> T;
    int _case = 1;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }
        
        int nowmax = 0, max = -1000, nowk1 = 1, k1 = 1, k2 = 1;
        for (int i = 1; i <= n; i++) {
            nowmax += a[i];
            if (nowmax > max) {
                max = nowmax;
                k1 = nowk1;
                k2 = i;
            }
            if (nowmax < 0) {
                nowmax = 0;
                nowk1 = i + 1;
            }
        }
        printf("Case %d:\n%d %d %d\n", _case++, max, k1, k2);
        if (T > 0) {
            cout << endl;
        }
    }
    return 0;
}


/*
// F
int a[1010];
int b[1010];

int main()
{
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        b[0] = 1;
        for (int i = 1; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < i; j++) {
                if (a[i] > a[j] && tmp < b[j]) {
                    tmp = b[j];
                }
            }
            b[i] = tmp + 1;
        }
        int tmp = 1;
        for (int i = 0; i < n; i++) {
            if (tmp < b[i]) {
                tmp = b[i];
            }
        }
        printf("%d\n",tmp);
    }
    return 0;
}


// M 简单背包问题
int value[1005];
int w[1005];
int dp[1005][1005];

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, const char * argv[]) {
    int T, N, V;
    cin >> T;
    while (T--) {
        memset(dp, 0, sizeof(dp));
        memset(value, 0, sizeof(value));
        memset(w, 0, sizeof(w));
        scanf("%d%d", &N, &V);
        for (int i = 1; i <= N; i++) {
            scanf("%d", &value[i]);
        }
        for (int i = 1; i <= N; i++) {
            scanf("%d", &w[i]);
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 0; j <= V; j++) { // 注意 从0开始 有的背包重量为0
                if (j >= w[i]) {
                    dp[i][j] = Max(dp[i-1][j-w[i]]+value[i], dp[i-1][j]);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        printf("%d\n", dp[N][V]);
    }
    return 0;
}


// A 简单数塔问题
int triangle[101][101];

int Max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            scanf("%d", &triangle[i][j]);
        }
    }
    for (int i = N-1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            triangle[i][j] += Max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }
    printf("%d\n",triangle[1][1]);
    return 0;
}

 

*/
