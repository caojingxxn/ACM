//
//  main.c
//  ACM_day02
//
//  Created by admin on 18/1/21.
//  Copyright © 2018年 Amon. All rights reserved.
//

/*
#include <stdio.h>
#include <time.h>
#include <string.h>

int b[55600000];

int judge(int a)
{
    int p[10];
    int i = 0;
    for ( ; i < 10; i++) {
        p[i] = -1;
    }
    i = 0;
    while (a != 0) {
        p[i] = a%10;
        a /= 10;
        i++;
    }
    int j = 0;
    while(p[j] != -1)
    {
        j++;
    }
    j--;
    i = 0;
    while (i <= j) {
        if (p[i] != p[j]) {
            return 0;
        }
        i++,j--;
    }
    return 1;
}

// 测试代码
//int main()
//{
//    int i = judge(12564521);
//    printf("%d\n", i);
//    return 0;
//}
//

int main()
{
    unsigned long p = clock();
    int i = 4;
    for ( ; i < 100000000; i++) {
        if (i%2 == 0 || i%3 == 0) {
            b[i] = 1;
            continue;
        }
        int j = 2;
        for ( ; j*j <= i ; j++) {
            if (i%j == 0) {
                b[i] = 1;
                break;
            }
        }
    }
    for (i = 0; i < 100000000; i++) {
        if (b[i] == 0 && judge(b[i]) == 0 ) {
            b[i] = 1;
        }
    }
    unsigned long m=clock();
    int a1,a2;
    scanf("%d %d", &a1, &a2);
    for (i = a1; i <= a2; i++) {
        if (b[i] == 0) {
            printf("%d\n",b[i]);
        }
    }
    printf("%lu\n",m-p);
    
    //    int N;
    //    while (~scanf("%d", &N)) {
    //        int j = N/2;
    //        while ( !(b[j] == 0 && b[N-j] == 0) && j < N) {
    //            j++;
    //        }
    //        printf("%d %d\n", N-j, j);
    //    }
    return 0;
}

*/
// 素数范围 x以内的素数大约有x/lnx个（不准确的）
/*
 #include <stdio.h>
 #include <time.h>
 #include <stdbool.h>

 bool b[10000000];

 int main()
 {
    unsigned long p = clock();
    int i = 4;
    for ( ; i < 10000000; i++) {
        if (i%2 == 0 || i%3 == 0) {
            b[i] = 1;
            continue;
        }
        int j = 2;
        for ( ; j*j <= i ; j++) {
            if (i%j == 0) {
                b[i] = 1;
                break;
            }
        }
    }
    unsigned long m=clock();
 
    printf("%lu\n",m-p);
 //    int N;
 //    while (~scanf("%d", &N)) {
 //        int j = N/2;
 //        while ( !(b[j] == 0 && b[N-j] == 0) && j < N) {
 //            j++;
 //        }
 //        printf("%d %d\n", N-j, j);
 //    }
 return 0;
 }
 
 */
 
/*
#include <stdio.h>
#include <time.h>
int b[10001];
int main()
{
    unsigned long p = clock();
    int i = 4;
    for ( ; i < 10000; i++) {
        if (i%2 == 0 || i%3 == 0) {
            b[i] = 1;
            continue;
        }
        int j = 2;
        for ( ; j*j <= i ; j++) {
            if (i%j == 0) {
                b[i] = 1;
                break;
            }
        }
    }
    unsigned long m=clock();
    
    printf("%lu\n",m-p);
//    int N;
//    while (~scanf("%d", &N)) {
//        int j = N/2;
//        while ( !(b[j] == 0 && b[N-j] == 0) && j < N) {
//            j++;
//        }
//        printf("%d %d\n", N-j, j);
//    }
    return 0;
}
 //筛法
*/

/*
#include <stdio.h>
#include <time.h>

int a[1300] = {2,3};
int b[10001];
int q = 1;
// 质数为0 合数改为1

int main()
{
    unsigned long p = clock();
    int i = 4;
    for ( ; i < 10000; i++) { //判断i是否为质数
        //        if (b[i] == 1) {
        //            continue;
        //        }
        if (i%2 == 0 || i%3 == 0) {
            b[i] = 1;
            continue;
        }
        
        int j = 0;
        for ( ; j <= q ; j++) {
            if (i%a[j] == 0) {
                b[i] = 1;
                break;
            }
        }
        if (j > q) {
            q++;
            a[q] = i;
        }
    }
//    for (i = 0; i < 1200; i++) {
//        printf("%d\n", a[i]);
//    }
    
    unsigned long m=clock();
    
    printf("%lu\n",m-p);
    //    int N;
    //    while (~scanf("%d", &N)) {
    //        int j = N/2;
    //        while ( !(b[j] == 0 && b[N-j] == 0) && j < N) {
    //            j++;
    //        }
    //        printf("%d %d\n", N-j, j);
    //    }
    return 0;
}
// 试除法 除素数
*/





//#define Bproblem
#ifdef Bproblem
 //最小公倍数=两数的乘积/最大公约（因）数
#include <stdio.h>

int seachgcd(int a, int b)
{
    int max;
    int min;
    ( a > b ) ? (max = a, min = b):(max = b, min = a);
    while (max%min != 0) {
        int c = max%min;
        max = min; //原来的除数
        min = c; //新的余数
    }
    return min;
}

int main()
{
    int a,b;
    while (scanf("%d %d", &a, &b) != EOF) {
        int gcd = seachgcd(a, b);
        printf("%d\n",a*b/gcd);
    }
}
#endif






// 辗转相除法
// 10 3
// 10/3=3……1
// 3/1=3……0 最后的除数为最大公因数


// 10 6
// 10/6=1……4
// 6/4=1……2
// 4/2=2……0
//
// a除b余c，则(a,b)=(b,c)




//#define Aproblem
#ifdef Bproblem
// 欧拉函数是小于n的正整数中与n互质的数的数目
#include <stdio.h>

int seachgcd(int a, int b)
{
    int max;
    int min;
    ( a > b ) ? (max = a, min = b):(max = b, min = a);
    while (max%min != 0) {
        int c = max%min;
        max = min; //原来的除数
        min = c; //新的余数
    }
    return min;
}


int main(int argc, const char * argv[]) {
    int T;
    scanf("%d",&T);
    while (T--) {
        int N,M;
        scanf("%d %d",&N, &M);
        // 找有多少个X，M<=X<=N, X和N的最大公因数大于M；
        int i = M;
        int k = 0;
        for ( ; i <= N; i++) {
            //如果i和N的最大公约数大于M，k++
            if (N%i == 0) {
                k++;
            }
            else {
                int gcd = seachgcd(i,N);
                if ( gcd >= M) {
                    printf("%d\n",i);
                    k++;
                }
            }
        }
        //printf("%d\n",k);
    }
    return 0;
}
#endif


//测试代码
//int main()
//{
//    int a = seachgcd(10, 6);
//    printf("%d\n", a);
//    return 0;
//}

//#define Hproblem
#ifdef Hproblem
// H 素数回文
// 看了下结果，只有奇数位个数的才可以回文，所以题目所说范围内的10000000-99999999都不行，所以我们可以将范围缩小为原来的十分之一
#include <stdio.h>
#include <time.h>
#include <stdbool.h>

int a[700000];
bool b[10000000];// 用布尔值更省空间

int q = 1;
// 质数为0 合数改为1

int judge(int y)
{
    int p[10];
    int i = 0;
    for ( ; i < 10; i++) {
        p[i] = -1;
    }
    i = 0;
    while (y != 0) {
        p[i] = y%10;
        y /= 10;
        i++;
    }
    int j = 0;
    while(p[j] != -1)
    {
        j++;
    }
    j--;
    i = 0;
    while (i <= j) {
        if (p[i] != p[j]) {
            return 0;
        }
        i++,j--;
    }
    return 1;
}

int main()
{
    //unsigned long p = clock();
    
    //////////////////////////////////////////////
 
    int i = 2;
    for ( ; i < 10000000; i++) { //判断i是否为质数
        if (b[i] == 0) { //说明i被小于它的所有数试除过后，标记仍为0
            a[q++] = i; //记下这个素数
        }
        // 无论这个数是否为素数，都将它一定范围内的倍数试除
        int j = 1;
        for ( ; j < q; j++) {
            // j小于等于已有素数的下标（由于前面为q++，所以这里不需要等号）
            if (a[j]*i > 10000000) {
                break;
            }
            
            b[a[j]*i] = 1;
            ////////////////
            if(i % a[j] == 0)
                break;
        }
    }

//        for (i = 1; i < 5560000; i++) {
//            printf("%d\n", a[i]);
//        }
    int w,e;
    while (~scanf("%d %d", &w, &e)) {
        int j;
        for (j = 1; j < 10000000; j++) {
            if (a[j] >= w) {
                break;
            }
        }
        for (i = j; a[i] <= e && i < q; i++) {
            if (judge(a[i]) == 1) {
                printf("%d\n",a[i]);
            }
        }
        printf("\n");
    }
    
    /////////////////////////////////////////////////////
    //unsigned long m=clock();
    //printf("%lu\n",m-p);
    
    return 0;
}
// 欧拉筛法 目前较快
#endif





// I 美素数
//#define Iproble
#ifdef Iproblem
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int value[78000];
bool check[1000000];
int check2[1000000];
int num = 1;

//判断相加的和
int add(int a)
{
    int ret = 0;
    while (a != 0) {
        ret = ret + a%10;
        a /= 10;
    }
    return ret;
}

int main()
{
    //unsigned long d1 = clock();
    int j = 2;
    for ( ; j < 1000000; j++) {
        if (check[j] == 0) {
            value[num++] = j;
        }
        int k = 1;
        for ( ; k < num && j*value[k] < 1000000; k++) {
            check[j*value[k]] = 1;
            if (j%value[k] == 0) {
                break;
            }
        }
    }
    check[1] = 1;
    for (j = 1000000; j >= 2; j--) {
        if (check[add(j)] == 1) {
            check[j] = 1;
        }
    }
    int m = 0;
    check2[0] = 0;
    for ( j = 1; j <= 1000000; j++) {
        check2[j] = m;
        if (check[j] == 0) {
            m++;
            check2[j] = m;
        }
    }
    
    //unsigned long d2 = clock();
    //printf("%lu\n",d2-d1);
    int T;
    while ( ~scanf("%d", &T) ) {
        int i = 0;
        for ( ; i < T; i++) {
            int L,R;
            scanf("%d %d", &L, &R);
            printf("Case #%d: %d\n",i+1,check2[R]-check2[L-1]);
        }
    }
    return 0;
}
#endif

// 测试代码
//#define Itest
#ifdef Itest
int main()
{
    int a = add(898);
    printf("%d\n",a);
    return 0;
}
#endif


//#define Jproblem
#ifdef Jproblem
// N/M=k，k为素数，求最小的M，即求最大的K
// 即求最大的质因数

#include <stdio.h>
#include <math.h>

int prime[1000000];

// 求最大因数
int seach_prime_gcd_max(int a)
{
    int k = 0;
    int i = a;
    for ( i = 2; i <= (int)sqrt((double)a); i++) {
        while (a%i == 0 ) {
            a /= i;
            k = i;
        }
    }
    return (k>a)?k:a;
}
// 关于为什么可以这么求最大质因数：
// 一个数a,sqrt(a) 分为两部分
// |||| ||||| （分别代表前后两部分中的数）
// 1.第二部分无质数，那只需算到第一部分即可
// 2.第二部分有质数：
//    这个数一定是唯一的。
//    即除去前面所有的质数后，剩下的那个质数。
//    (如果有两个质数都大于sqrt(a)，那这两个数相乘已经大于a）

int main()
{
    int N;
    while (~scanf("%d",&N)) {

        if (N > 1) {
            printf("%d\n",N/seach_prime_gcd_max(N));
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
#endif

#include <stdio.h>
int main()
{
    printf("hello world\n");
    return 0;
}




