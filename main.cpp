//
//  main.cpp
//  ACM_0125
//
//  Created by admin on 18/1/25.
//  Copyright © 2018年 Amon. All rights reserved.
//
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int n;
//    while ( ~scanf("%d", &n)) {
//        vector<string, vector<string>> boy;
//        vector<string, vector<string>> girl;
//        vector<string> dog;
//        vector<int> boy1(500,-1); // 初始化为-1 没女朋友
//        vector<int> girl1(500,-1); // 记录第i个女生的男朋友是第j个男生
//        
//        int num = 0;
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j <= n; j++) {
//                cin >> boy[i][j];
//                dog[num++] = boy[i][j];
//            }
//        } // 第i个男生喜欢的第j个女生
//        for (int i = 0; i < n; i++) {
//            for (int j = 0; j <= n; j++) {
//                cin >> girl[i][j];
//            }
//        } // 第i个女生喜欢的第j个男生
//        while (dog.size() != 0) {
//            for (int i = 0; i <= n; i++) { // boy
//                for (int j = 0; j < n; j++) {
//                    
//                }
//            }
//        }
//
//        
//        
//        
//        
//        
//        
//    }
//    return 0;
//}



//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int cmp(int a, int b)
//{
//    return b-a;
//}
//
//int a[100000];
//
//int main()
//{
//    int n, m, k;
//    while ( ~scanf("%d%d%d",&n,&m,&k)) {
//        for (int i = 0; i < n; i++) {
//            cin >> a[i];
//        }
//        int left = 0, right = 0;
//        int d = a[right] - a[left];
//        int max = a[right];
//        int min = a[left];
//        int num = 0;
//        int length[10000];
//        int t = 0;
//    
//        while (right < n) {
//            
//            right++;
//            num++;
//            d = a[right] - a[left];
//        }
//        sort(length, length+t-1, cmp);
//        cout << length[0] << endl;
//        
//        
//        
//    }
//    return 0;
//}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct cow{
    int minSPF;
    int maxSPF;
    int is; // 初始化为0
};
struct lot{
    int SPF;
    int num;
};

int cmp1(cow a, cow b)
{
    return a.maxSPF < b.maxSPF;
}

int cmp2(lot a, lot b)
{
    return a.SPF < b.SPF;
}

int main()
{
    int C,L;
    while (~scanf("%d%d",&C,&L)) {
        cow cows[2502];
        lot lots[2502];
        for (int i = 0; i < C; i++) {
            cin >> cows[i].minSPF >> cows[i].maxSPF;
            cows[i].is = 0;
        }
        for (int i = 0; i < L; i++) {
            cin >> lots[i].SPF >> lots[i].num;
        }
        sort(cows, cows+C, cmp1);
        sort(lots, lots+L, cmp2);
//        for (int i = 0; i < C; i++) {
//            cout << cows[i].minSPF << ' ' << cows[i].maxSPF<< endl;
//        }
//        for (int i = 0; i < L; i++) {
//            cout << lots[i].SPF << ' ' << lots[i].num << endl;
//        }
        int lnum = 0;
        int num = 0;
        for (int i = lnum; i < L; i++) {
            for (int j = 0; j < C; j++) {
                if (cows[j].is == 1) {
                    continue;
                }
                if (lots[i].num == 0) {
                    break;
                }
                if (lots[i].SPF <= cows[j].maxSPF && lots[i].SPF >= cows[j].minSPF) {
                    num++;
                    cows[j].is = 1;
                    lots[i].num--;
                }
            }
        }
        cout << num << endl;
    }
}





/*
// G 错误....
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct cow{
    int minSPF;
    int maxSPF;
};

struct lot{
    int SPF;
    int num;
};

priority_queue<cow> cows;
priority_queue<lot> lots;

bool operator< (cow a, cow b)
{
    if (a.maxSPF == b.maxSPF) {
        return a.minSPF > b.minSPF;
    }
    return (a.maxSPF > b.maxSPF);
}

bool operator< (lot a, lot b)
{
    return (a.SPF > b.SPF);
}

int main()
{
    int C,L;
    while (~scanf("%d%d",&C,&L)) {
        while (cows.size() > 0) {
            cows.pop();
        }
        while (lots.size() > 0) {
            lots.pop();
        }
        for (int i = 0; i < C; i++) {
            cow a;
            cin >> a.minSPF >> a.maxSPF;
            cows.push(a);
        }
        for (int i = 0; i < L; i++) {
            lot a;
            cin >> a.SPF >> a.num;
            lots.push(a);
        }
//        for (int i = 0; i < C; i++) {
//            cow a;
//            a = cows.top();
//            cout << a.minSPF << ' '<< a.maxSPF << endl;
//            cows.pop();
//        }
        
        int n = 0;
        while (cows.size() != 0 && lots.size() != 0) {
            lot l = lots.top();
            if (l.num == 0) {
                lots.pop();
                continue;
            }
            cow c = cows.top();
            if (c.minSPF <= l.SPF && c.maxSPF >= l.SPF ) {
                l.num--;
                lots.pop();
                lots.push(l);
                n++;
                cows.pop();
            }
            else if (l.SPF > c.maxSPF){
                cows.pop();
            }
        }
        cout << n << endl;
        
    }
    
    return 0;
}


// D
#include <iostream>
#include <queue>
#include <string>
using namespace std;

typedef struct command {
    string name;
    int para;
    int prio;
    int k;
}command;

//priority_queue<command> com;

bool operator< (const command &a, const command &b) // 重载
{
    if (b.prio ==a.prio) {
        return a.k > b.k;
    }
    return b.prio < a.prio;
}

int main(int argc, const char * argv[]) {
    
    priority_queue<command> com;
    
    char command1[4];
    int i = 0;
    while (~scanf("%s", command1)) {
        
        switch (command1[0]) {
            case 'G':
                if (com.size() == 0) {
                    cout << "EMPTY QUEUE!" << endl;
                }
                else {
                    command a = com.top();
                    com.pop();
                    cout << a.name << ' ' << a.para << endl;
                }
                break;
            case 'P':{
                command a;
                cin >> a.name >> a.para;
                cin >> a.prio;
                a.k = i++;
                com.push(a);
            }
                break;
            default:
                cout << "错了啊啊啊啊啊啊" << endl;
                break;
        }
    }
    return 0;
}



// A
#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main()
{
    stack<double> s;
    double num;
    char ch;
    char blank;
    while (~scanf("%lf%c", &num, &blank)) {
        if (num == 0 && blank == '\n') {
            break;
        }
        s.push(num);
        while (scanf("%c", &ch)) {
            scanf("%c%lf", &blank, &num);
            switch (ch) {
                case '+':
                    s.push(num);
                    break;
                case '-':
                    s.push(-num);
                    break;
                case '*':{
                    double a = s.top();
                    s.pop();
                    s.push(a*num);
                }
                    break;
                case '/':{
                    double a = s.top();
                    s.pop();
                    s.push(a/num);
                }
                default:
                    break;
            }
            scanf("%c", &blank);
            if (blank == '\n') {
                break;
            }
        }
        double sum = 0;
        while (s.size() != 0) {
            sum += s.top();
            s.pop();
        }
        printf("%0.2lf\n", sum);
    }
    return 0;
}


 
//B
#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    getchar();
flag:
    while (n--) {
        stack<char> str;
        char a[130];
        fgets(a, 130, stdin);
        int i = 0;
        while ( a[i] != '\0') {
            switch (a[i]) {
                case '(':
                    str.push('(');
                    break;
                case '[':
                    str.push('[');
                    break;
                case ')':
                    if (str.size() > 0 && str.top() == '(') {
                        str.pop();
                    }
                    else {
                        cout << "No" << endl;
                        goto flag;
                    }
                    break;
                case ']':
                    if (str.size() > 0 && str.top() == '[') {
                        str.pop();
                    }
                    else {
                        cout << "No" << endl;
                        goto flag;
                    }
                    break;
                default:
                    break;
            }
            i++;
        }
        if (str.size() != 0) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
    return 0;
}



// E
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    char str[1002];
    while (~scanf("%s", str)) {
        int num = 0;
        int i = 0;
        while ( str[i] != 'B') {
            if (str[i] == '(') {
                num++;
            }
            else{
                num--;
            }
            i++;
        }
        cout << num << endl;
    }
    return 0;
}
*/
