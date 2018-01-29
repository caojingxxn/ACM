//
//  main.cpp
//  ACM_0128
//
//  Created by admin on 18/1/28.
//  Copyright © 2018年 Amon. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
    char str[20000];
    char ch[2000];
    int now = 0;
    while (fgets(str, 2000, stdin) && strcmp(str, "#\n") != 0) {
        map<string, int> kkkk;
        int i = 0;
        while (str[i] == ' ') {
            i++;
        }
        while (str[i] != '\n') {
            if (str[i] != ' ') {
                ch[now++] = str[i++];
            }
            else {
                ch[now++] = '\0';
                now = 0;
                // map
                kkkk[ch] = 1;
                while (str[i] == ' ') {
                    i++;
                }
            }
        }
        ch[now++] = '\0';
        if (str[i-1] != ' ') {
            kkkk[ch] = 1;
        }
        now = 0;
        printf("%lu\n",kkkk.size());
    }
    return 0;
}


/*
int map[100010][11];
int sum[100010];
char str[5005][200];
int top = 1;
int row = 0;
int now = 0;

void insert()
{
    int rt = 1;
    for (int i = 0; str[row][i] != '\0'; i++) {
        int id = str[row][i] - '0';
        if (map[rt][id] == 0) {
            map[rt][id] = ++top;
            sum[rt] = 0;
        }
        rt = map[rt][id];
    }
    sum[rt] = 1;
}

void my_find()
{
    int rt = 1;
    for (int i = 0; str[now][i] != '\0'; i++) {
        int id = str[now][i] - '0';
        if (map[rt][id] != 0 && sum[map[rt][id]] != 0) {
            printf("%s\n",str[now]);
            return;
        }
        rt = map[rt][id];
    }
    
    
}

int main()
{
    while (~scanf("%s",str[row]) && strcmp(str[row], "0") != 0) {
        insert();
        ++row;
    }
    for (now = 0; now < row; now++) {
        my_find();
    }
    return 0;
}





#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int map[50000][26];
int sum[50000];
int top = 1;
int all = 0;

void insert(char* str)
{
    int rt = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        int id = str[i] - 'a';
        if (map[rt][id] == -1) {
            map[rt][id] = ++top;
        }
        rt = map[rt][id];
    }
    if (sum[rt] == 0) {
        all++;
    }
    sum[rt]++;
}

int main()
{
    char str[2000];
    char ch[200];
    int now = 0;
    memset(map, -1, sizeof(map));
    while (fgets(str, 2000, stdin) && strcmp(str, "#\n") != 0) {
        int i = 0;
        while (str[i] == ' ') {
            i++;
        }
        while (str[i] != '\n') {
            if (str[i] != ' ') {
                ch[now++] = str[i++];
            }
            else {
                ch[now++] = '\0';
                now = 0;
                insert(ch);
                while (str[i] == ' ') {
                    i++;
                }
            }
        }
        ch[now++] = '\0';
        if (str[i-1] != ' ') {
            insert(ch);
        }
        now = 0;
        printf("%d\n",all);
        memset(map, -1, sizeof(map));
        memset(sum, 0, sizeof(sum));
        memset(str, '\0', sizeof(str));
        top = 1;
        all = 0;
    }
    return 0;
}


int map[1000000][4];
int sum[1000000];
// char a[4] = {'A','C','G','T'};
int top = 1;
int tmp = 0;

void insert(char* str)
{
    int rt = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        int id;
        switch (str[i]) {
            case 'A':
                id = 0;
                break;
            case 'C':
                id = 1;
                break;
            case 'G':
                id = 2;
                break;
            case 'T':
                id = 3;
                break;
            default:
                cout << "1111111111111111111";
                break;
        }
        if (map[rt][id] == -1) {
            map[rt][id] = ++top;
        }
        rt = map[rt][id];
        sum[rt] += (i+1);
    }
}


int my_find(int rt)
{
    for (int i = 0; i < 4; i++) {
        if (map[rt][i] == -1) {
            continue;
        }
        if (tmp < sum[rt]) {
            tmp = sum[rt];
        }
        my_find(map[rt][i]);
    }
    return tmp;
}

int main()
{
    int T;
    cin >> T;
    int _case = 1;
    while (T--) {
        memset(map, -1, sizeof(map));
        memset(sum, 0, sizeof(sum));
        top = 1;
        tmp = 0;
        int n;
        scanf("%d", &n);
        char str[55];
        while (n--) {
            scanf("%s",str);
            insert(str);
        }
        printf("Case %d: %d\n", _case++, my_find(1));
    }
    return 0;
}

// O
int map[100010][11];
int road[100010];
int END[100010];
int flag;
int top = 1;

void insert(char *str)
{
    int rt = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        int id = str[i] - '0';
        if (map[rt][id] == -1) {
            map[rt][id] = ++top;
        }
        if (END[rt] == 1) {
            flag = 1;
            return;
        }
        rt = map[rt][id];
        road[rt]--;
    }
    if (END[rt] == 1) {
        flag = 1;
        return;
    }
    END[rt] = 1;
    for (int i = 0; i <= 9; i++) {
        if (map[rt][i] != -1) {
            flag = 1;
            return;
        }
    }
}

int main()
{
    int T,n;
    scanf("%d",&T);
    int _case = 1;
    while (T--) {
        flag = 0;
        top = 1;
        memset(map, -1, sizeof(map));
        memset(END, 0, sizeof(END));
        scanf("%d",&n);
        char str[15];
        while (n--) {
            scanf("%s",str);
            if (flag == 0) {
                insert(str);
            }
        }
        printf("Case %d: ",_case++);
        if (flag == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}


// G
int map[1000000][26];
int sum[1000000];
int top = 1;

void insert(char* str)
{
    int rt = 1;
    for (int i = 0; str[i] != '\n'; i++) {
        int id = str[i] - 'a';
        if (map[rt][id] == 0) {
            map[rt][id] = ++top;
        }
        rt = map[rt][id];
        sum[rt]++;
    }
}

int my_find(char* str)
{
    int rt = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        int id = str[i] - 'a';
        if (map[rt][id] == 0) {
            return 0;
        }
        rt = map[rt][id];
    }
    return sum[rt];
}

int main()
{
    char str[15];
    while (fgets(str, 12, stdin) && strcmp(str, "\n") != 0) {
        insert(str);
    }
    while (~scanf("%s",str)) {
        printf("%d\n",my_find(str));
    }
    return 0;
}


// D
int map[100010][11];
int road[100010];
int END[100010];
int flag;
int top = 1;


void insert(char *str)
{
    int rt = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        int id = str[i] - '0';
        if (map[rt][id] == -1) {
            map[rt][id] = ++top;
        }
        if (END[rt] == 1) {
            flag = 1;
            return;
        }
        rt = map[rt][id];
        road[rt]--;
    }
    if (END[rt] == 1) {
        flag = 1;
        return;
    }
    END[rt] = 1;
    for (int i = 0; i <= 9; i++) {
        if (map[rt][i] != -1) {
            flag = 1;
            return;
        }
    }
}

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--) {
        flag = 0;
        top = 1;
        memset(map, -1, sizeof(map));
        memset(END, 0, sizeof(END));
        scanf("%d",&n);
        char str[15];
        while (n--) {
            scanf("%s",str);
            if (flag == 0) {
                insert(str);
            }
        }
        if (flag == 1)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}



// B
int map[100010][26];
int sum[100010];
char s[1010];
char keyboard[8][5] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int top = 1;
int _time = 0;
char str[1010];
char str2[1010];
int stop;

void insert(int num)
{
    int rt = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        int id = s[i] - 'a';
        if (map[rt][id] == -1) {
            map[rt][id] = ++top;
        }
        rt = map[rt][id];
        sum[rt] += num;
    }
}

void cmp(int rt, int now)
{
    if (now >= stop+1) {
        if (sum[rt] > _time) {
            _time = sum[rt];
            str2[now] = '\0';
            strcpy(str, str2);
        }
        return;
    }
    int key = s[now] - '0' - 2;
    for (int i = 0; keyboard[key][i] != '\0'; i++) {
        char a = keyboard[key][i];
        if (map[rt][a - 'a'] == -1) {
            continue;
        }
        str2[now] = a;
        cmp(map[rt][a-'a'], now+1);
    }
}

int main(int argc, const char * argv[]) {
    int scenarios = 1;
    int T;
    cin >> T;
    while (T--) {
        memset(map, -1, sizeof(map));
        memset(sum, 0, sizeof(sum));
        int w;
        cin >> w;
        while (w--) {
            scanf("%s",s);
            int num;
            cin >> num;
            insert(num);
        }
        printf("Scenario #%d:\n",scenarios++);
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            scanf("%s",s);
            for (stop = 0; s[stop] != '\0' && s[stop] != '1'; stop++) {
                _time = 0;
                memset(str, '\0', sizeof(str));
                memset(str2, '\0', sizeof(str2));
                cmp(1, 0);
                if (_time == 0)
                    printf("MANUALLY\n");
                else
                    printf("%s\n",str);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

// Q
int map[100000][26];
int sum[100000];
int top = 1;

void insert(char* str)
{
    int rt = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        int id = str[i] - 'a';
        if (map[rt][id] == 0) {
            map[rt][id] = ++top;
        }
        rt = map[rt][id];
        sum[rt]++;
    }
}

void my_find(char* str)
{
    int rt = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        int id = str[i] - 'a';
        rt = map[rt][id];
        
        printf("%c",str[i]);
        if (sum[rt] == 1 || str[i+1] == '\0') {
            printf("\n");
            return;
        }
    }
}

int main()
{
    char str[1001][25];
    int i = 0;
    while (~scanf("%s",str[i]) ) {
        insert(str[i++]);
    }
    int num = i;
    i = 0;
    while (num--) {
        printf("%s ",str[i]);
        my_find(str[i++]);
    }
    return 0;
}
*/
