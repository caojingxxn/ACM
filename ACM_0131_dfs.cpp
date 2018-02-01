//
//  main.cpp
//  ACM_0131
//
//  Created by admin on 18/1/31.
//  Copyright © 2018年 Amon. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int maze[5][5];
bool vis[5][5];
struct road
{
    int x;
    int y;
}road[25];

int num = 0;

bool canstay(int i, int j)
{
    if (i >= 0 && j >= 0 && i < 5 && j < 5 && vis[i][j] == 0 && maze[i][j] == 0) {
        return 1;
    }
    return 0;
}

void dfs(int a, int b)
{
    if (canstay(a, b) == 1) {
        vis[a][b] = 1;
        road[num].x = a;
        road[num++].y = b;
        if (a == 4 && b == 4) {
            for (int i = 0; i < num; i++) {
                printf("(%d,%d)\n",road[i].x,road[i].y);
            }
            return;
        }
        dfs(a-1,b);
        dfs(a,b+1);
        dfs(a+1,b);
        dfs(a,b-1);
        vis[a][b] = 0;
        num--;
    }
}

int main()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    dfs(0, 0);
    
    return 0;
}



/*
// C
int a[20]; // 1-19
int prime[40] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,1,0,0}; // 0-39
int num;
bool visit[20];
int n;
int flag = 0;
int _case = 1;

void dfs()
{
    if (num == n && prime[a[num]+1] == 1) {
        flag = 1;
        for (int i = 1; i < n; i++) {
            printf("%d ",a[i]);
        }
        printf("%d\n",a[n]);
        return;
    }
    for (int i = 2; i <= n; i++) {
        if (visit[i] == 0 && prime[a[num]+i] == 1) {
            a[++num] = i;
            visit[i] = 1;
            dfs();
//            if (flag == 1) {
//                return;
//            }
            visit[i] = 0;
            --num;
        }
        
    }
}

int main()
{
    while (~scanf("%d", &n)) {
        printf("Case %d:\n",_case++);
        memset(visit, 0, sizeof(visit));
        flag = 0;
        num = 1;
        a[1] = 1;
        dfs();
        printf("\n");
    }
    return 0;
}

 
// E
bool visrow[10][10];
bool viscol[10][10];
bool visblo[9][10];
char map[10][10];
int num = 0;

struct ques
{
    int x;
    int y;
}ques[90];

int isvis(int i, int j, int id)
{
    if ( visrow[i][id] == 0 && viscol[j][id] == 0) {
        if (i <= 3 && visblo[(j-1)/3][id] == 0) {
            return 0;
        }
        else if (i > 6 && visblo[(j-1)/3+6][id] == 0) {
            return 0;
        }
        else if (i > 3 && i <= 6 && visblo[(j-1)/3+3][id] == 0){
            return 0;
        }
    }
    return 1;
}

void mapvis(int i, int j, int id)
{
    if (i <= 3) {
        visblo[(j-1)/3][id] = 1;
    }
    else if (i > 6) {
        visblo[(j-1)/3+6][id] = 1;
    }
    else if (i > 3 && i <= 6){
        visblo[(j-1)/3+3][id] = 1;
    }
    visrow[i][id] = 1;
    viscol[j][id] = 1;
    map[i][j] = id +'0';
}

void remvisblo(int i, int j, int id)
{
    if (i <= 3 && visblo[(j-1)/3][id] == 1) {
        visblo[(j-1)/3][id] = 0;
    }
    else if (i > 6 && visblo[(j-1)/3+6][id] == 1) {
        visblo[(j-1)/3+6][id] = 0;
    }
    else if (i > 3 && i <= 6 && visblo[(j-1)/3+3][id] == 1){
        visblo[(j-1)/3+3][id] = 0;
    }
    visrow[i][id] = 0;
    viscol[j][id] = 0;
    map[i][j] = '?';
}

int flag = 0;
int _case = 0;

void dfs(int m)
{
    if (m == num) {
        flag = 1;
        if (_case != 1) {
            cout << endl;
        }
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 8; j++) {
                printf("%c ",map[i][j]);
            }
            cout << map[i][9] << endl;
        }
        return;
    }
    int i = ques[m].x;
    int j = ques[m].y;
    
    for (int k = 1; k <= 9; k++)
    {
        if (isvis(i, j, k) == 0) {
            mapvis(i, j, k);
            dfs(m+1);
            if (flag == 1) {
                return;
            }
            remvisblo(i, j, k);
        }
    }
}

int main()
{
    char ch[2];
    while ( scanf("%s",ch) != EOF) {
        map[1][1] = ch[0];
        _case++;
        memset(visrow, 0, sizeof(visrow));
        memset(viscol, 0, sizeof(viscol));
        memset(visblo, 0, sizeof(visblo));
        num = 0;
        flag = 0;
        if (map[1][1] != '?') {
            int id = map[1][1] - '0';
            visrow[1][id] = 1;
            viscol[1][id] = 1;
            visblo[0][id] = 1;
        }
        else {
            ques[num].x = 1;
            ques[num++].y = 1;
        }
        int j;
        for (int i = 1; i <= 9; i++) {
            if (i == 1)
                j = 2;
            else
                j = 1;
            for ( ; j <= 9; j++) {
                scanf("%s",ch);
                map[i][j] = ch[0];
                if (map[i][j] != '?') {
                    int id = map[i][j] - '0';
                    visrow[i][id] = 1;
                    viscol[j][id] = 1;
                    if (i <= 3) {
                        visblo[(j-1)/3][id] = 1;
                    }
                    else if (i > 6) {
                        visblo[(j-1)/3+6][id] = 1;
                    }
                    else {
                        visblo[(j-1)/3+3][id] = 1;
                    }
                }
                else {
                    ques[num].x = i;
                    ques[num++].y = j;
                }
            }
        }
        dfs(0);
    }
    return 0;
}


// B
char map[100][100];
bool visit[100][100];
int n,m;
int _time = 0;

void dfs(int i, int j)
{
    if (i >= 0 && j >= 0 && i < n && j < m && map[i][j] == '@' && visit[i][j] == 0) {
        visit[i][j] = 1;
        dfs(i-1,j-1);
        dfs(i-1,j);
        dfs(i-1,j+1);
        dfs(i,j+1);
        dfs(i+1,j+1);
        dfs(i+1,j);
        dfs(i+1,j-1);
        dfs(i,j-1);
    }
}

int main()
{
    while (~scanf("%d%d",&n,&m) && n != 0) {
        _time = 0;
        memset(visit, 0, sizeof(visit));
        for (int i = 0; i < n; i++) {
            scanf("%s",map[i]);
        }
//        for (int i = 0; i < n; i++) {
//            printf("%s",map[i]);
//        }

        int i = 0, j = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (map[i][j] == '@' && visit[i][j] == 0) {
                    _time++;
                    dfs(i, j);
                }
            }
        }
        cout << _time << endl;
    }
    return 0;
}


// A
int main(int argc, const char * argv[]) {
    
    std::cout << "Hello World!\n";
    return 0;
}
*/
