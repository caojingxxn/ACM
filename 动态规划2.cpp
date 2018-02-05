//
//  main.cpp
//  ACM_0204
//
//  Created by admin on 18/2/4.
//  Copyright © 2018年 Amon. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long a[1010][1010];
long long dp1[1010][1010];
long long dp2[1010][1010];
long long dp3[1010][1010];
long long dp4[1010][1010];

long long _max(long long a, long long b)
{
    return a > b ? a : b;
}

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        memset(dp3, 0, sizeof(dp3));
        memset(dp4, 0, sizeof(dp4));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%lld", &a[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp1[i][j] = _max(a[i-1][j], a[i][j-1]) + a[i][j];
            }
        }
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                dp2[i][j] = _max(a[i+1][j], a[i][j-1]) + a[i][j];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                dp3[i][j] = _max(a[i-1][j], a[i][j+1]) + a[i][j];
            }
        }
        for (int i = n; i >= 1; i--) {
            for (int j = m; j >= 1; j--) {
                dp4[i][j] = _max(a[i+1][j], a[i][j+1]) + a[i][j];
            }
        }
        long long Max = 0;
        for (int i = 2; i < n; i++) {
            for (int j = 2; j < m; j++) {
                Max = _max(Max, dp1[i-1][j] + dp2[i][j-1] + dp3[i][j+1] + dp4[i+1][j]);
                Max = _max(Max, dp1[i][j-1] + dp2[i+1][j] + dp3[i-1][j] + dp4[i][j+1]);
            }
        }
        printf("%lld\n", Max);
    }
    return 0;
}


/*
// J
char a[1010];
char b[1010];
int dp[1010][1010];

int Max(int i, int j)
{
    return i > j ? i : j;
}

int main()
{
    while (~scanf("%s", a)) {
        scanf("%s",b);
        memset(dp, 0, sizeof(dp));
        int i = 0,j = 0;
        for (i = 1; a[i-1] != '\0'; i++) {
            for (j = 1; b[j-1] != '\0'; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {
                    dp[i][j] = Max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        cout << dp[i-1][j-1] << endl;
    }
    return 0;
}


// I
int a[110];
int c[305];
int b[11000];

int main()
{
    
    int N, T, maxfind = 0;
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        c[a[i]]++;
        maxfind = c[a[i]] > maxfind ? c[a[i]] : maxfind;
    }
    b[0] = 1;
    int max = 0;
    
    int t = N > T ? T : N;
    
    for (int i = 1; i < N*t; i++) {
        int tmp = 0;
        for (int j = 0; j < i; j++) {
            if (a[i%N] >= a[j%N] && tmp < b[j]) {
                tmp = b[j];
            }
        }
        b[i] = tmp + 1;
        if (b[i] > max) {
            max = b[i];
        }
    }
    if (T > N) {
        max += maxfind*(T-N);
    }
    printf("%d\n", max);
    return 0;
}


// G
int a[10010];
int b[10010];

int main(int argc, const char * argv[]) {
    
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        memset(b, 0, sizeof(b));
        b[0] = 1;
        int tmp;
        int max = 1;
        for (int i = 1; i < n; i++) {
            tmp = 0;
            for (int j = 0; j < i; j++) {
                if (a[j] < a[i] && b[j] > tmp) {
                    tmp = b[j];
                }
                b[i] = tmp + 1;
                if (b[i] > max) {
                    max = b[i];
                }
            }
        }
        printf("%d\n", max);
    }
    return 0;
}
*/
