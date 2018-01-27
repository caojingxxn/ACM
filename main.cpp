//
//  main.cpp
//  ACM_0126
//
//  Created by admin on 18/1/26.
//  Copyright © 2018年 Amon. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int pre[2005];
//int d[2005];
int flag = 0;

int find1(int a,int d[])
{
    if (pre[a] == a) {
        return a;
    }
    int m = pre[a];
    pre[a] = find1(pre[a],d);
    d[a] = d[m] + 1 + d[a];
    return pre[a];
}

int find2(int a)
{
    int r = a;
    while (a != pre[a]) {
        a = pre[a];
    }
    while (r != a) {
        int i = pre[r];
        pre[r] = a;
        r = i;
    }
    return a;
}

void my_union(int a, int b, int d[])
{
    int a1 = find1(a,d);
    int b1 = find1(b,d);
    if ( a1 == b1) {
        if ((d[a]+d[b]) % 2 == 0) {
            flag = 1;
            return;
        }
    }
    pre[a1] = b1;
    d[a1] = d[b] + 1 + d[a];
}


int main()
{
    int scenario;
    cin >> scenario;
    int _case = 1;
    int d[2005];

    while(scenario--) {
        memset(pre, 0, sizeof(pre));
        memset(d, 0, sizeof(d));
        flag = 0;
        int number,intera; // 虫  行为
        scanf("%d%d",&number,&intera);
        if (intera == 0) {
            printf("Scenario #%d:\nNo suspicious bugs found!\n",_case++);
            continue;
        }
        
        int n,m;
        for (int i = 1; i <= intera; i++) {
            scanf("%d%d", &n, &m);
            if (pre[n] == 0) {
                pre[n] = n;
            }
            if (pre[m] == 0) {
                pre[m] = m;
            }
            my_union(n, m, d);
            
        }
        
        if (flag == 1) {
            printf("Scenario #%d:\nSuspicious bugs found!\n",
                   _case++);
            
        }
        else{
            printf("Scenario #%d:\nNo suspicious bugs found!\n",_case++);
        }
    }
    
    return 0;
}



//#include <iostream>
//#include <cstdio>
//#include <algorithm>
//#include <cstring>
//
//using namespace std;
//int pre[100005];
//int in[100005];// 记录入度
//int flag = 0;
//
//
//
//int find1(int a)
//{
//    if (pre[a] == a) {
//        return a;
//    }
//    pre[a] = find1(pre[a]);
//    return pre[a];
//}
//
//int find2(int a)
//{
//    int r = a;
//    while (a != pre[a]) {
//        a = pre[a];
//    }
//    while (r != a) {
//        int i = pre[r];
//        pre[r] = a;
//        r = i;
//    }
//    return a;
//}
//
//void my_union(int a, int b)
//{
//    int a1 = find2(a);
//    int b1 = find2(b);
//    if ( a1 == b1) {
//        flag = 1;
//        return;
//    }
//    pre[a1] = b1;
//    in[b] += 1;
//}
//
//
//int main()
//{
//    int n,m;
//    int _case = 1;
//aaaaaa:
//    while (~scanf("%d%d",&n,&m) && n != -1 && m != -1) {
//        if (n == 0 && m == 0) {
//            printf("Case %d is a tree.\n",_case++);
//            continue;
//        }
//        memset(pre, 0, sizeof(pre));
//        memset(in, 0, sizeof(in));
//        int p = 0;
//        int num = 0;
//        if (pre[n] == 0) {
//            pre[n] = n;
//            p++;
//        }
//        if (pre[m] == 0) {
//            pre[m] = m;
//            p++;
//        }
//        my_union(n, m);
//        num++;
//        
//        while (scanf("%d%d", &n, &m) && n != 0 && m != 0) {
//            if (pre[n] == 0) {
//                pre[n] = n;
//                p++;
//            }
//            if (pre[m] == 0) {
//                pre[m] = m;
//                p++;
//            }
//            my_union(n, m);
//            num++;
//        }
//        if (flag == 1) {
//            printf("Case %d is not a tree.\n", _case++);
//            continue;
//        }
//        
//        int k = 0;
//        
//        for (int i = 1; i <= 100005; i++) {
//            if (pre[i] != 0) {
//                if (pre[i] == i) {
//                    k++;
//                }
//                else if (in[i] > 1) {
//                    printf("Case %d is not a tree.\n", _case++);
//                    goto aaaaaa;
//                }
//            }
//        }
//        
//        if (k == 1 && num+1 == p) {
//            printf("Case %d is a tree.\n",_case++);
//        }else {
//            printf("Case %d is not a tree.\n", _case++);
//        }
//    }
//    return 0;
//}

/*
// G
int pre[10000005];
int ran[10000005];
int flag = 0;

int find1(int a)
{
    if (pre[a] == a) {
        return a;
    }
    pre[a] = find1(pre[a]);
    return pre[a];
}

int find2(int a)
{
    int r = a;
    while (a != pre[a]) {
        a = pre[a];
    }
    while (r != a) {
        int i = pre[r];
        pre[r] = a;
        r = i;
    }
    return a;
}

void my_union(int a, int b)
{
    int a1 = find1(a);
    int b1 = find1(b);
    if ( a1 == b1) {
        flag = 1;
        return;
    }
    if (ran[a1] > ran[b1]) {
        pre[b1] = a1;
        ran[a1] += ran[b1];
    }
    else {
        pre[a1] = b1;
        ran[b1] += ran[a1];
    }
}


int main()
{
    int n = 0;
    while (~scanf("%d", &n)) {
        if (n == 0) {
            printf("1\n");
            continue;
        }
//        int pre[15];
//        int ran[15];

        for (int i = 1; i <= 10000000; i++) {
            ran[i] = 1;
        }
        memset(pre, 0, sizeof(pre));
        
        for (int i = 1; i <= n; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            if (pre[a] == 0) {
                pre[a] = a;
            }
            if (pre[b] == 0) {
                pre[b] = b;
            }
            my_union(a, b);
        }
        int tmp = 1;
        for (int i = 1; i <= 10000000; i++) {
            if (pre[i] == i) {
                if (tmp < ran[i]) {
                    tmp = ran[i];
                }
            }
        }
        printf("%d\n",tmp);
    }
    return 0;
}



// D
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int pre[100005];
int flag = 0;

int find1(int a)
{
    if (pre[a] == a) {
        return a;
    }
    pre[a] = find1(pre[a]);
    return pre[a];
}

int find2(int a)
{
    int r = a;
    while (a != pre[a]) {
        a = pre[a];
    }
    while (r != a) {
        int i = pre[r];
        pre[r] = a;
        r = i;
    }
    return a;
}

void my_union(int a, int b, int pre[])
{
    int a1 = find1(a);
    int b1 = find1(b);
    if ( a1 == b1) {
        flag = 1;
        return;
    }
    if (a1 > b1) {
        pre[b1] = a1;
    }
    else {
        pre[a1] = b1;
    }
}


int main()
{
    int n,m;
    while (~scanf("%d%d",&n,&m) && n != -1 && m != -1) {
        if (n == 0 && m == 0) {
            printf("Yes\n");
            continue;
        }
        memset(pre, 0, sizeof(pre));
        int p = 0;
        int num = 0;
        if (pre[n] == 0) {
            pre[n] = n;
            p++;
        }
        if (pre[m] == 0) {
            pre[m] = m;
            p++;
        }
        my_union(n, m,pre);
        num++;
        
        while (scanf("%d%d", &n, &m) && n != 0 && m != 0) {
            if (pre[n] == 0) {
                pre[n] = n;
                p++;
            }
            if (pre[m] == 0) {
                pre[m] = m;
                p++;
            }
            my_union(n, m,pre);
            num++;
        }
        if (flag == 1) {
            printf("No\n");
            continue;
        }
        
        int k = 0;
        
        for (int i = 1; i <= 100000; i++) {
            if (pre[i] != 0) {
                if (pre[i] == i) {
                    k++;
                }
            }
        }
        
        if (k == 1) {
            printf("Yes\n");
        }else {
            printf("No\n");
        }
    }
    return 0;
}




// B
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int pre[1005];

int find1(int a)
{
    if (pre[a] == a) {
        return a;
    }
    pre[a] = find1(pre[a]);
    return pre[a];
}

int find2(int a)
{
    int r = a;
    while (a != pre[a]) {
        a = pre[a];
    }
    while (r != a) {
        int i = pre[r];
        pre[r] = a;
        r = i;
    }
    return a;
}

void my_union(int a, int b)
{
    int a1 = find1(a);
    int b1 = find1(b);
    if ( a1 == b1) {
        return;
    }
    if (a1 > b1) {
        pre[b1] = a1;
    }
    else {
        pre[a1] = b1;
    }
}


int main()
{
    int T = 0;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            pre[i] = i;
        }
        
        for (int i = 0; i < m; i++) {
            int a,b;
            scanf("%d%d", &a, &b);
            int a1 = find1(a);
            int b1 = find1(b);
            my_union(a1, b1);
        }
        int k = 0;
        for (int i = 1; i <= n; i++) {
            if (pre[i] == i) {
                k++;
            }
        }
        
        printf("%d\n",k);
        
    }
    return 0;
}



// A
int pre[105];

struct aaa {
    int i;
    int j;
    int dist;
};
struct aaa city[10100];

bool cmp(const aaa a, const aaa b) {
    return a.dist < b.dist;
}

int find1(int a)
{
    if (pre[a] == a) {
        return a;
    }
    pre[a] = find1(pre[a]);
    return pre[a];
}

int find2(int a)
{
    int r = a;
    while (a != pre[a]) {
        a = pre[a];
    }
    while (r != a) {
        int i = pre[r];
        pre[r] = a;
        r = i;
    }
    return a;
}

void my_union(int a, int b)
{
    int a1 = find1(a);
    int b1 = find1(b);
    if ( a1 == b1) {
        return;
    }
    if (a1 > b1) {
        pre[b1] = a1;
    }
    else {
        pre[a1] = b1;
    }
}


int main()
{
    int n = 0;
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) {
            pre[i] = i;
        }
        
        int num = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int a;
                scanf("%d", &a);
                if (i != j) {
                    city[num].dist = a;
                    city[num].i = i;
                    city[num++].j = j;
                }
            }
        }
        sort(city, city+num, cmp);
        
        
        
        
        int Q = 0;
        scanf("%d",&Q);
        int a1,b1;
        int l = 0;
        for (int i = 0; i < Q; i++) {
            int a,b;
            scanf("%d%d", &a, &b);
            int a1 = find1(a);
            int b1 = find1(b);
            my_union(a1, b1);
        }
        int k = 0;
        for (int i = 0; i < num && l < n; i++) {
            a1 = find1(city[i].i);
            b1 = find1(city[i].j);
            
            if (a1 != b1) {
                if (a1 > b1) {
                    pre[b1] = a1;
                }
                else {
                    pre[a1] = b1;
                }
                k += city[i].dist;
                l++;
            }
        }
        printf("%d\n",k);
        
    }
    return 0;
}


// C
int main(int argc, const char * argv[]) {
    
    int n = 0,m = 0;
    while (~scanf("%d", &n) && n != 0) {
        scanf("%d", &m);
        for (int i = 1; i <= n; i++) {
            pre[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            my_union(a, b);
        }
        int num = 0;
        for (int i = 1; i <= n; i++) {
            if (pre[i] == i) {
                num++;
            }
        }
        printf("%d\n",num-1);
    }
    return 0;
}
*/
