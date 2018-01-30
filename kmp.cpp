//
//  main.cpp
//  ACM_0129_KMP
//
//  Created by admin on 18/1/29.
//  Copyright © 2018年 Amon. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[100010];
int _next[100010];

void GetNext(unsigned long int len)
{
    int k = -1;
    _next[0] = -1;
    for (int q = 1; str[q] != '\0'; q++) {
        while (k > -1 && str[q] != str[k+1]) {
            k = _next[k];
        }
        if (str[q] == str[k+1]) {
            k++;
        }
        _next[q] = k;
    }
}
char str1[50010];
char str2[50010];

int main()
{
    while (~scanf("%s",str1)) {
        scanf("%s",str2);
        unsigned long len = strlen(str1);
        strcpy(str, str1);
        for (int i = 0; str2[i] != '\0'; i++) {
            str[len++] = str2[i];
        }
        str[len] = '\0';
        GetNext(len);
        _next[len-1]++; // 表示前缀后缀相等的长度

        if (_next[len-1] > strlen(str1)
                    || _next[len-1] > strlen(str2) ) {
            if (_next[len-1] > strlen(str1))
                printf("%s %lu\n",str1,strlen(str1));
            else
                printf("%s %lu\n",str2,strlen(str2));
        }
        else {
            for (int i = 0; i < _next[len-1]; i++) {
                printf("%c", str[i]);
            }
            if (_next[len-1] > 0 ) {
                cout << ' ' ;
            }
            cout << _next[len-1]++ << endl;
        }
    }
    return 0;
}


/*
char ch[200010];
int _next[200010];

void GetNext()
{
    int k = -1;
    _next[0] = -1;
    for (int q = 1; ch[q] != '\0'; q++) {
        while (k > -1 && ch[q] != ch[k+1] ) {
            k = _next[k];
        }
        if (ch[q] == ch[k+1]) {
            k++;
        }
        _next[q] = k;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        scanf("%s",ch);
        GetNext();
        int all = 0;
        for (int i = 0; ch[i] != '\0'; i++) {
            cout << _next[i]+1 << endl;
            //all += (_next[i]+1);
        }
        cout << all+1 << endl;
        
    }
    
    return 0;
}


// G
char str[10001000];
int _next[10001000];

void GetNext(unsigned long int len)
{
    int k = -1;
    _next[0] = -1;
    for (int q = 1; str[q] != '\0'; q++) {
        while (k > -1 && str[q] != str[k+1]) {
            k = _next[k];
        }
        if (str[q] == str[k+1]) {
            k++;
        }
        _next[q] = k;
    }
}

int main()
{
    while (~scanf("%s",str) && strcmp(str, ".") != 0) {
        
        unsigned long int len = strlen(str);
        GetNext(len);
        _next[len-1]++; // 表示前缀后缀相等的长度
        int cycle_once = (int)len - _next[len-1];
        
        if (cycle_once != len && len%cycle_once == 0) {
            cout << len/cycle_once << endl;
        }
        else {
            cout << 1 << endl;
        }
    }
    return 0;
}


// C
char str[1000010];
char ch[10010];
int _next[1000010];
int _time = 0;

void GetNext()
{
    int k = -1;
    _next[0] = -1;
    for (int q = 1; ch[q] != '\0'; q++) {
        while (k > -1 && ch[q] != ch[k+1] ) {
            k = _next[k];
        }
        if (ch[q] == ch[k+1]) {
            k++;
        }
        _next[q] = k;
    }
}

void kmp(int m)
{
    int k = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        while (k > -1 && str[i] != ch[k+1]) {
            k = _next[k];
        }
        if (str[i] == ch[k+1]) {
            k++;
        }
        if (k == m-1) {
            _time++;
            i += strlen(ch)-1;
        }
    }
}


int main()
{
    int T;
    cin >> T;
    while (~scanf("%s", str) && strcmp(str, "#") != 0) {
        scanf("%s", ch);
        GetNext();
        _time = 0;
        kmp(strlen(ch));
        printf("%d\n",_time);
    }
    
    return 0;
}


// D
char str[100010];
int _next[100010];

void GetNext(unsigned long int len)
{
    int k = -1;
    _next[0] = -1;
    for (int q = 1; str[q] != '\0'; q++) {
        while (k > -1 && str[q] != str[k+1]) {
            k = _next[k];
        }
        if (str[q] == str[k+1]) {
            k++;
        }
        _next[q] = k;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        scanf("%s",str);
        unsigned long int len = strlen(str);
        GetNext(len);
        _next[len-1]++; // 表示前缀后缀相等的长度
        
        
        
        int cycle_once = (int)len - _next[len-1];
        
        if (cycle_once != len && len%cycle_once == 0) {
            cout << "0" << endl;
        }
        else {
            cout << cycle_once - _next[len-1]%cycle_once << endl;
        }
    }
    return 0;
}

// B
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char str[1000010];
char ch[10010];
int _next[1000010];
int _time = 0;

void GetNext()
{
    int k = -1;
    _next[0] = -1;
    for (int q = 1; ch[q] != '\0'; q++) {
        while (k > -1 && ch[q] != ch[k+1] ) {
            k = _next[k];
        }
        if (ch[q] == ch[k+1]) {
            k++;
        }
        _next[q] = k;
    }
}

void kmp(int m)
{
    int k = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        while (k > -1 && str[i] != ch[k+1]) {
            k = _next[k];
        }
        if (str[i] == ch[k+1]) {
            k++;
        }
        if (k == m-1) {
            _time++;
        }
    }
}


int main()
{
    int T;
    cin >> T;
    while (T--) {
        scanf("%s%s", ch, str);
        GetNext();
        _time = 0;
        kmp(strlen(ch));
        printf("%d\n",_time);
    }
    
    return 0;
}


// A
int str[1000010];
void GetNext(int* ch, int* next, int m)
{
    int k = -1;
    next[0] = -1;
    for (int q = 1; q < m; q++) {
        while (k > -1 && ch[q] != ch[k+1] ) {
            k = next[k];
        }
        if (ch[q] == ch[k+1]) {
            k++;
        }
        next[q] = k;
    }
}

int kmp(int* str, int* ch, int* next, int n, int m)
{
    int k = -1;
    for (int i = 0; i < n; i++) {
        while (k > -1 && str[i] != ch[k+1]) {
            k = next[k];
        }
        if (str[i] == ch[k+1]) {
            k++;
        }
        if (k == m-1) {
            return i - k + 1;
        }
    }
    return -1;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        
        int ch[10010];
        int n,m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            scanf("%d",&str[i]);
        }
        for (int i = 0; i < m; i++) {
            scanf("%d",&ch[i]);
        }
        int next[10010];
        GetNext(ch, next, m);
        
        int d = kmp(str, ch, next, n, m);
        cout << d << endl;
    }
    
    return 0;
}

// F
#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    printf("Hello World!\n");
    return 0;
}
*/
