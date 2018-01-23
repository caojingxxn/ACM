//
//  main.c
//  ACM_day01_C
//
//  Created by admin on 18/1/19.
//  Copyright © 2018年 Amon. All rights reserved.
//

#include <stdio.h>

struct Node {
    char a[51];
    int k;
}DNA[101];


int main()
{
    int t;
    while (~scanf("%d", &t)) {
        while (t--) {
            int n,m;
            scanf("%d", &n);
            scanf("%d", &m);
            int i = 0;
            int j;
            int z;
            for ( ; i < m; i++) {
                DNA[i].k = 0;
                scanf("%s",DNA[i].a);
                for ( j = 0; j < n-1; j++) {
                    for ( z = j+1; z < n; z++) {
                        if ( DNA[i].a[j] > DNA[i].a[z]) {
                            DNA[i].k++;
                        }
                    }
                }
            }
            for (j = 0; j < m-1; j++) {
                for (z = 0; z < m-1-j; z++) {
                    if (DNA[z].k > DNA[z+1].k) {
                        struct Node tmp = DNA[z];
                        DNA[z] = DNA[z+1];
                        DNA[z+1] = tmp;
                    }
                }
            }
            for (j = 0; j < m; j++) {
                printf("%s\n", DNA[j].a);
            }
        }
    }
}

//
//#include <stdio.h>
//
//int a[100005];
//
//int main()
//{
//    int t;
//    while (scanf("%d", &t) != EOF) {
//        while (t--) {
//            int N,T;
//            scanf("%d %d", &N, &T);
//            int i = 0;
//            for ( ; i < N; i++) {
//                scanf("%d", &a[i]);
//            }
//            
//            
//            
//            
//        }
//    }
//    
//    return 0;
//}

/*
 H
#include <stdio.h>

struct Node {
    int x;
    int y;
    int flag;
    int number;
}point[25000000];

int main()
{
    int N;
    while (scanf("%d", &N) != EOF) {
        int i = 0;
        for ( ; i < N; i++) {
            scanf("%d %d", &point[i].x, &point[i].y);
            if (point[i].y == point[i].x) {
                point[i].flag = 1;
                if (point[i].x % 2 == 0) {
                    point[i].number = 2*point[i].x;
                }
                else
                    point[i].number = 2*point[i].x - 1;
            }
            else if(point[i].y == point[i].x-2)
            {
                point[i].flag = 2;
                if (point[i].x % 2 == 0) {
                    point[i].number = 2*point[i].x - 2;
                }
                else
                    point[i].number = 2*point[i].x - 3;
                
            }
            else
                point[i].flag = 0;
        }
        for (i = 0; i < N; i++) {
            if (point[i].flag == 0) {
                printf("No Number\n");
            }
            else {
                printf("%d\n",point[i].number);
            }
        }
    }
    return 0;
}
*/

/*
 I
#include <stdio.h>
#include <stdlib.h>

int a[10000];
int cmp(const void* a, const void* b)
{
    return (*(int*)b - *(int*)a);
}

int main()
{
    int N;
    while (scanf("%d", &N) != EOF) {
        int i = 0;
        for ( ; i < N; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, N, sizeof(int), cmp);
        i = 0;
        int j = N-1;
        while (i < j) {
            printf("%d ", a[i]);
            i++;
            if (i < j) {
                printf("%d ", a[j]);
                j--;
            }
        }
        printf("%d\n", a[i]);
    }
    return 0;
}
*/



/*
 F
#include <stdio.h>
#include <stdlib.h>

int b[4500000];

int cmp(const void* a,const void* b)
{
    return (*(int*)b - *(int*)a);
}

int main()
{
    int a[3001];
    int N,M; //N个数
    while (scanf("%d", &N) != EOF) {
        scanf("%d", &M);
        int i = 0;
        int k = 0;
        for ( ; i < N; i++) {
            scanf("%d", &a[i]);
            int j = 0;
            for ( ; j < i; j++) {
                b[k] = a[i]+a[j];
                k++;
            }
        }
        qsort(b, k, sizeof(int), cmp);
        for (i = 0; i < M-1; i++) {
            printf("%d ",b[i]);
        }
        printf("%d\n",b[i]);

    }
    
    return 0;
}
*/

/*
E
#include <stdio.h>
#include <string.h>

struct student1 {
    char CS[21];
    int result;
}student[1002];

int main(int argc, const char * argv[]) {
    int N;
    int a[11] = {0};
    while (scanf("%d",&N) != EOF && N != 0) {
        int M,G;
        scanf("%d", &M);
        scanf("%d", &G);
        int i = 1;
        for ( ; i <= M; i++) {
            scanf("%d", &a[i]);
        }
        
        for (i = 0; i < N; i++) {
            scanf("%s", student[i].CS);
            int number;
            student[i].result = 0;
            scanf("%d", &number);
            while (number--) {
                int n;
                scanf("%d", &n);
                student[i].result += a[n];
            }
        }
        for (i = 0; i < N; i++) {
            int j;
            for (j = 0; j < N-i-1; j++) {
                if (student[j].result < student[j+1].result ||
                    ( student[j].result == student[j+1].result && strcmp(student[j].CS,student[j+1].CS) > 0) ) {
                    struct student1 tmp = student[j];
                    student[j] = student[j+1];
                    student[j+1] = tmp;
                }
            }
        }
        for ( i = 0; i < N; i++) {
            if (student[i].result < G) {
                break;
            }
        }
        printf("%d\n", i);
        int j = 0;
        for ( ; j < i; j++) {
            printf("%s", student[j].CS);
            printf(" %d\n", student[j].result);
        }
    }
    return 0;
}
*/

/*
 D
 double的绝对值 用fabs；int用abs
#include <stdio.h>
#include <math.h>

typedef struct _time {
    int h;
    int m;
    double d;
}_time;

void swap(_time* a, _time* b)
{
    _time tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int T;
    scanf("%d",&T);
    int i = 0;
    for ( ; i < T; i++) {
        _time time[5];
        int j = 0;
        for ( ; j < 5; j++) {
            scanf("%d:%d", &time[j].h, &time[j].m);
            
            time[j].d = fabs( (double)time[j].m*6 -
            ((time[j].h%12)*30+(double)time[j].m/2));
                 // 注意钟上时间<12h
            if (time[j].d > 180) {
                time[j].d = 360 - time[j].d;
            }
        }
        for (j = 0; j < 5; j++) {
            int k;
            for (k = 0; k < 5-j-1; k++) {
                if ( (time[k].d - time[k+1].d) > 0.000000001) {
                    swap( &time[k], &time[k+1]);
                }
                else if
               ( fabs(time[k].d - time[k+1].d) < 0.000000001){
                    if (time[k].h > time[k+1].h) {
                        swap( &time[k], &time[k+1]);
                    }
                    else if (time[k].h == time[k+1].h){
                        if (time[k].m > time[k+1].m) {
                            swap( &time[k], &time[k+1]);
                        }
                    }
                }
            }
        }
        
        printf("%02d:%02d\n", time[2].h, time[2].m);//不到两位时补0
    }
    return 0;
}
*/

/*
 C 注意 1.开头为5；2.连续的5；
#include <stdio.h>
#include <string.h>

int my_atoi(char a[], int k, int n)
{
    int i = 0;
    int ret = 0;
    for ( i = k; i < n; i++) {
        ret = ret*10 + a[i]-'0';
    }
    return ret;
}

int main() {
    char a[1002];
    while (scanf("%s", a) != EOF ) {
        int b[1001] = {0};
        int i = 0;
        int j = 0;
        int k = 0;
        long n = strlen(a);
        a[n] = '5';
        while ( i <= n+1 ) {
            if (a[i] == '5') {
                b[j] = my_atoi(a, k, i);
                if (a[i-1] != '5' && i != 0 ) {
                    j++;
                }
                k = i+1;
            }
            i++;
        }
        for (i = 0; i < j; i++) {
            int k;
            for (k = 0; k < j-i-1; k++) {
                if (b[k] > b[k+1]) {
                    int tmp = b[k];
                    b[k] = b[k+1];
                    b[k+1] = tmp;
                }
            }
        }
        for (i = 0; i < j-1; i++) {
            printf("%d ",b[i]);
        }
        printf("%d\n",b[i]);
    }
}
*/
