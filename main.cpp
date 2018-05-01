//
//  main.cpp
//  劳动节爱劳动
//
//  Created by admin on 18/4/28.
//  Copyright © 2018年 Amon. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long int arr[100000];
long long int now[50010];

void set(long long int a) {
    int h = a % 98931;
    while (arr[h] != -1) {
        h = (h + 1) % 100000;
    }
    arr[h] = a;
}

bool _find(long long int a) {
    int h = a % 98931;
    while (arr[h] != -1) {
        if (arr[h] == a) {
            return 1;
        } else {
            h = (h + 1) % 100000;
        }
    }
    return 0;
}

int main() {
    
    int T;
    cin >> T;
    while (T--) {
        memset(arr, -1, sizeof(arr));
        int n;
        cin >> n;
        int k = 0;
        long long int a;
        for (int i = 0; i < n; ++i) {
            scanf("%lld", &a);
            if (_find(a) == 0) {
                now[k++] = a;
                set(a);
            }
        }
        for (int i = 0; i < k - 1; ++i) {
            printf("%lld ", now[i]);
        }
        printf("%lld\n", now[k - 1]);
    }
    return 0;
}





/*
// H
int main() {
    int n;
    cin >>n;
    while (n--) {
        long long int t;
        cin >> t;
        cout << (t * t) % 10000 << endl;
    }
}


// F
int main() {
    
    int n;
    cin >> n;
    while (n--) {
        int H, M, S, h, m, s;
        scanf("%d:%d:%d", &H, &M, &S);
        scanf("%d:%d:%d", &h, &m, &s);
        h %= 12;
        H -= h;
        M -= m;
        S -= s;
        while (S < 0) {
            S += 60;
            --M;
        }
        while (M < 0) {
            M += 60;
            --H;
        }
        while (H < 0) {
            H += 12;
        }
        printf("%02d:%02d:%02d\n", H, M, S);
    }
}


// E
bool prime[16010] = {1, 1, 1, 0};
// 0 primer
int main(int argc, const char * argv[]) {
    
    for ( int now = 2; now < 16010; ++now) {
        if (prime[now] == 0 || now == 2) {
            for (int i = 2; now * i < 16010; ++i) {
                prime[now * i] = 1;
            }
        }
    }
    int q, t = 1;
    while (~scanf("%d", &q) && q > 0) {
        printf("%d: ", t++);
        if (prime[q] == 1) {
            cout << "no" << endl;
        } else {
            cout << "yes" << endl;
        }
    }
    return 0;
}

// G
int main(int argc, const char * argv[]) {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        int left = 2, right = left + 2 * (m - 1);
        
        while (right < n * 2) {
            if (left != right) {
                cout << (left + right) / 2 << ' ';
            } else {
                cout << left << ' ';
            }
            left = right + 2, right = left + 2 * (m - 1);
        }
        if (left != n * 2) {
            cout << (left + n * 2) / 2 << endl;
        } else {
            cout << left << endl;
        }
    }
    return 0;
}


// B
long long int arr[55] = {0, 1, 2};

int main(int argc, const char * argv[]) {
    for (int i = 3; i < 55; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    int m;
    while (~scanf("%d", &m)) {
        cout << arr[m] << endl;
    }
    return 0;
}

// A
int main(int argc, const char * argv[]) {
    
    
    cout << "Hello World!" << endl;
    
    return 0;
}
*/
