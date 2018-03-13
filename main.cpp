//
//  main.cpp
//  天梯赛
//
//  Created by admin on 18/3/12.
//  Copyright © 2018年 Amon. All rights reserved.
//

/*
int main() {
    int a, b, n;
    while (~scanf("%d%d%d", &a, &b, &n)) {
        int count1 = 0, count2 = 0, flag = 0, a1, a2, a3, a4;
        for (int i = 0; i < n; ++i) {
            scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
            if (a2 == a1 + a3 && flag == 0) {
                ++count1;
            }
            if (count1 > a || count2 > b) {
                flag = 1;
            }
            if (a4 == a1 + a3 && flag == 0) {
                ++count2;
            }
            if (count1 > a || count2 > b) {
                flag = 1;
            }
        }
        if (count1 > a) {
            printf("A\n%d\n", count2);
        } else if (count2 > b){
            printf("B\n%d\n", count1);
        }
    }
    return 0;
}


struct frie {
    vector<int> f;
    int K;
}frie[110];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        memset(frie, 0, sizeof(frie));
        for (int i = 0; i < n; ++i) {
            scanf("%d", &frie[i].K);
            for (int j = 0; j < frie[i].K; ++j) {
                int q;
                scanf("%d", &q);
                frie[i].f.push_back(q);
            }
        }
        int m;
        for (int i = 0; i < m; ++i) {
            int num;
            scanf("%d", &num);
            int flag = 0;
            for (int j = 0; j < n; ++j) {
                vector<int>
            }
        }
    }
    
    return 0;
}

*/


//#include <iostream>
//#include <cstdio>
//#include <cstring>
//#include <algorithm>
//#include <set>
//#include <cstddef>
//#include <vector>
//using namespace std;
//
//int main() {
//    
//    char str[10010];
//    while (~scanf("%s", str)) {
//        int G = 0, P = 0, L = 0, T = 0;
//        for (int i = 0; str[i] != '\0'; ++i) {
//            if (str[i] == 'g' || str[i] == 'G') {
//                ++G;
//            } else if (str[i] == 'p' || str[i] == 'P') {
//                ++P;
//            } else if (str[i] == 'l' || str[i] == 'L') {
//                ++L;
//            } else if (str[i] == 't' || str[i] == 'T') {
//                ++T;
//            }
//        }
//        while (G > 0 || P > 0 || L > 0 || T > 0) {
//            if (G > 0) {
//                cout << 'G';
//                --G;
//            }
//            if (P > 0) {
//                cout << 'P';
//                --P;
//            }
//            if (L > 0) {
//                cout << 'L';
//                --L;
//            }
//            if (T > 0) {
//                cout << 'T';
//                --T;
//            }
//        }
//    }
//    return 0;
//}

#include <iostream>
using namespace std;
int Add(int a, int b) {
    int c = a + b;
    return c;
}

int main() {
    int a = 1;
    const int& ret = a;
    cout << a << endl;
    cout << ret << endl;
    a = 2;
    cout << a << endl;
    cout << ret << endl;
}


/*
// 22
int main() {
    int n;
    while (~scanf("%d", &n)) {
        int num;
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &num);
            if (num % 2 == 1) {
                ++count1;
            } else {
                ++count2;
            }
        }
        cout << count1 << ' ' << count2;
    }
    return 0;
}


// 18
int main() {
    int a, b;
    while (~scanf("%d:%d", &a, &b)) {
        if (a < 12 || (a == 12 && b == 0)) {
            printf("Only %02d:%02d.  Too early to Dang.\n", a, b);
        } else {
            if (b == 0) {
                for (int i = 1; i <= a-12; ++i) {
                    printf("Dang");
                }
                cout << endl;
            } else {
                for (int i = 0; i <= a-12; ++i) {
                    printf("Dang");
                }
                cout << endl;
            }
        }
    }
    return 0;
}


// 17
int main() {
    char str[55];
    while (~scanf("%s", str)) {
        double mult = 1;
        int flag = 0;
        if (str[0] == '-') {
            mult = 1.5;
            flag = 1;
        }
        double count = 0;
        int i = 0;
        for (; str[i] != '\0'; ++i) {
            if (str[i] == '2') {
                ++count;
            }
        }
        if (str[i-1] % 2 == 0) {
            mult *= 2;
        }
        printf("%.2f", 100.0 * count * mult / (i - flag));
        cout << '%' << endl;
    }
    return 0;
}


// 15
int main() {
    int n;
    char ch;
    while (~scanf("%d%c%c", &n, &ch, &ch)) {
        int k = n / 2;
        if (n % 2 == 1) {
            ++k;
        }
        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << ch;
            }
            cout << endl;
        }
    }
    return 0;
}


// 14
int main() {
    
    printf("This is a simple problem.\n");
}


// 13
int64_t k(int n) {
    int64_t sum = 1;
    for (int i = 1; i <= n; ++i) {
        sum *= i;
    }
    return sum;
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        int64_t sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += k(i);
        }
        cout << sum << endl;
    }
    return 0;
}


// 12
int main() {
    int n;
    while (~scanf("%d", &n)) {
        switch (n) {
            case 1:
                printf("2^1 = 2\n");
                break;
            case 2:
                printf("2^2 = 4\n");
                break;
            case 3:
                printf("2^3 = 8\n");
                break;
            case 4:
                printf("2^4 = 16\n");
                break;
            case 5:
                printf("2^5 = 32\n");
                break;
            case 6:
                printf("2^6 = 64\n");
                break;
            case 7:
                printf("2^7 = 128\n");
                break;
            case 8:
                printf("2^8 = 256\n");
                break;
            case 9:
                printf("2^9 = 512\n");
                break;
            case 10:
                printf("2^10 = 1024\n");
                break;
            default:
                break;
        }
    }
    return 0;
}


// 11
int main() {
    set<char> a;
    char str[10010];
    
    while (~scanf("%c", &str[0])) {
        for (int i = 1; str[i-1] != '\n'; ++i) {
            scanf("%c", &str[i]);
        }
        char ch;
        while (1) {
            scanf("%c", &ch);
            if (ch == '\n') {
                break;
            }
            a.insert(ch);
        }
        for (int i = 0; str[i-1] != '\n'; ++i) {
            size_t count = a.count(str[i]);
            if (count == 0) {
                cout << str[i];
            }
        }
    }
    return 0;
}


// 10
int cmp(int a, int b) {
    return a < b;
}

int main() {
    
    int a[3];
    while (~scanf("%d%d%d", &a[0], &a[1], &a[2])) {
        sort(a, a + 3, cmp);
        printf("%d->%d->%d\n", a[0], a[1], a[2]);
    }
    return 0;
}


// 8
int main() {
    int a = 0, b = 0;
    while (~scanf("%d%d", &a, &b)) {
        int k = 0;
        for (int i = a; i <= b; ++i) {
            printf("%5d", i);
            ++k;
            if (k % 5 == 0) {
                cout << endl;
            }
        }
        if (k % 5 != 0) {
            cout << endl;
        }
        printf("Sum = %d\n", (a + b) * (b - a + 1) / 2);
    }
    return 0;
}


// 7
void print(char a) {
    switch (a) {
        case '0':
            cout << "ling";
            break;
        case '1':
            cout << "yi";
            break;
        case '2':
            cout << "er";
            break;
        case '3':
            cout << "san";
            break;
        case '4':
            cout << "si";
            break;
        case '5':
            cout << "wu";
            break;
        case '6':
            cout << "liu";
            break;
        case '7':
            cout << "qi";
            break;
        case '8':
            cout << "ba";
            break;
        case '9':
            cout << "jiu";
            break;
        default:
            printf("======\n");
            break;
    }
}


int main() {
    char a[1000];
    while (~scanf("%s", a)) {
        int i = 0;
        if (a[0] == '-') {
            cout << "fu ";
            i = 1;
        }
        for (; a[i + 1] != '\0'; ++i) {
            print(a[i]);
            cout << ' ';
        }
        print(a[i]);
        cout << endl;
    }
    return 0;
}


// 5
struct stu {
    char a[20];
    int b;
    int c;
}stu[1010];

int cmp(struct stu a, struct stu b) {
    return a.b < b.b;
}

int main() {
    int M, N;
    while (~scanf("%d", &N)) {
        for (int i = 0; i < N; ++i) {
            scanf("%s%d%d", stu[i].a, &stu[i].b, &stu[i].c);
        }
        sort(stu, stu + N, cmp);
        scanf("%d", &M);
        for (int i = 0; i < M; ++i) {
            int set;
            scanf("%d", &set);
            printf("%s %d\n", stu[set-1].a, stu[set-1].c);
        }
    }
    return 0;
}


// 4
int main() {
    int F;
    while (~scanf("%d", &F)) {
        printf("Celsius = %d\n", 5 * (F - 32) / 9);
    }
    return 0;
}

// 3
int main(int argc, const char * argv[]) {
    
    int a[10];
    char num[1010];
    
    while (~scanf("%s", num)) {
        memset(a, 0, sizeof(a));
        for (int i = 0; num[i] != '\0'; ++i) {
            int k = num[i] - '0';
            ++a[k];
        }
        for (int i = 0; i < 10; ++i) {
            if (a[i] != 0) {
                printf("%d:%d\n", i, a[i]);
            }
        }
    }
    return 0;
}
*/
