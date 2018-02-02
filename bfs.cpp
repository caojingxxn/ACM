//
//  main.cpp
//  ACM_0201
//
//  Created by admin on 18/2/1.
//  Copyright © 2018年 Amon. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

/*
int n,m;
int map[30][30];
int num[30][30];

void filpNode(int i, int j)
{
    if (map[i][j] == 0)
        map[i][j] = 1;
    else
        map[i][j] = 0;
}

void filp(int i, int j)
{
    filpNode(i, j);
    if (i-1 >= 0) {
        filpNode(i-1, j);
        if (j-1 >= 0) {
            filpNode(i-1, j-1);
        }
        if (j+1 < m) {
            filpNode(i-1, j+1);
        }
    }
    if (j-1 >= 0) {
        filpNode(i, j-1);
    }
    if (j+1 < m) {
        filpNode(i, j+1);
    }
    if (i+1 < m) {
        filpNode(i+1, j);
        if (j-1 >= 0) {
            filpNode(i-1, j-1);
        }
        if (j+1 < m) {
            filpNode(i-1, j+1);
        }
    }
}

void Fliptile()
{
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 1) {
                filp(i+1,j);
                num[i+1][j]++;
            }
        }
    }
    for (int j = 0; j < m; j++) {
        if (map[n-1][j] == 1) {
            printf("IMPOSSIBLE\n");
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m-1; j++) {
            printf("%d ",num[i][j]%2);
        }
        printf("%d\n",num[i][m-1]%2);
    }
    
}

int main()
{
    while (~scanf("%d%d",&n,&m)) {
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d",&map[i][j]);
            }
        }
        Fliptile();
    }
    return 0;
}


int n,m;
char map[201][201];
struct _road {
    int x,y;
    int num;
}s,e;

void bfs()
{
    
    
}

int main()
{
    while (~scanf("%d%d",&n,&m)) {
        for (int i = 0; i < n; i++) {
            scanf("%s",map[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (map[i][j] == 'Y') {
                    s.x = i;
                    s.y = j;
                    s.num = 0;
                }
                if (map[i][j] == 'M') {
                    e.x = i;
                    e.y = j;
                    e.num = 0;
                }
            }
        }
        bfs();
    }
    
    return 0;
}

// G
int N,M,C;
// 1 FILL(2) 倒满
// 2 DROP(1) 倒空
// 3 POUR(2,1)

struct Node {
    int cho,i;
    int a,b; // 当前
    int num;
}s,now1,nex1;

vector<Node> ss,now,nex;

void bfs(int vis[][1000])
{
    queue<vector<Node> > q;
    ss.push_back(s);
    q.push(ss);
    while (!q.empty()) {
        now = q.front();
        now1 = now.back();
        if (now1.a == C || now1.b == C) {
            printf("%d\n",now1.num);
            for (int i = 1; i < now.size(); i++) {
                now1 = now[i];
                if (now1.cho == 3) {
                    if (now1.i == 1)
                        printf("POUR(1,2)\n");
                    else
                        printf("POUR(2,1)\n");
                }
                else if (now1.cho == 1)
                    printf("FILL(%d)\n", now1.i);
                else
                    printf("DROP(%d)\n", now1.i);
            }
            return;
        }
        nex1.num = now1.num+1;
        
        // 1
        nex1.cho = 1;
        // 倒满a
        nex1.a = N;
        nex1.b = now1.b;
        nex1.i = 1;
        if (vis[nex1.a][nex1.b] == 0) {
            vis[nex1.a][nex1.b] = 1;
            nex = now;
            nex.push_back(nex1);
            q.push(nex);
        }
        
        // 倒满b
        nex1.b = M;
        nex1.a = now1.a;
        nex1.i = 2;
        if (vis[nex1.a][nex1.b] == 0) {
            vis[nex1.a][nex1.b] = 1;
            nex = now;
            nex.push_back(nex1);
            q.push(nex);
        }
        
        // 2
        nex1.cho = 2;
        // 倒空a
        nex1.a = 0;
        nex1.b = now1.b;
        nex1.i = 1;
        if (vis[nex1.a][nex1.b] == 0) {
            vis[nex1.a][nex1.b] = 1;
            nex = now;
            nex.push_back(nex1);
            q.push(nex);
        }
        
        // 倒满b
        nex1.b = 0;
        nex1.a = now1.a;
        nex1.i = 2;
        if (vis[nex1.a][nex1.b] == 0) {
            vis[nex1.a][nex1.b] = 1;
            nex = now;
            nex.push_back(nex1);
            q.push(nex);
        }
        
        // 3
        nex1.cho = 3;
        // a倒到b
        nex1.i = 1;
        if (now1.a+now1.b <= M) {
            nex1.a = 0;
            nex1.b = now1.a+now1.b;
        }
        else
        {
            nex1.a = now1.a+now1.b-M;
            nex1.b = M;
        }
        if (vis[nex1.a][nex1.b] == 0) {
            vis[nex1.a][nex1.b] = 1;
            nex = now;
            nex.push_back(nex1);
            q.push(nex);
        }
        
        // b倒到a
        nex1.i = 2;
        if (now1.a+now1.b <= N) {
            nex1.b = 0;
            nex1.a = now1.a+now1.b;
        }
        else
        {
            nex1.b = now1.a+now1.b-N;
            nex1.a = N;
        }
        if (vis[nex1.a][nex1.b] == 0) {
            vis[nex1.a][nex1.b] = 1;
            nex = now;
            nex.push_back(nex1);
            q.push(nex);
        }
        q.pop();
    }
    printf("impossible\n");
}

int main()
{
    while (~scanf("%d%d%d",&N,&M,&C)) {
        int vis[1000][1000] = {0};
        s.a = 0;
        s.b = 0;
        s.num = 0;
        bfs(vis);
    }
    return 0;
}

// L
int button[201];

struct lift {
    int height;
    int num;
}s,now,nex;

bool vis[201];
int N,A,B;

bool islegal(lift r)
{
    if (r.height >= 1 && r.height <= N && vis[r.height] == 0) {
        return 1;
    }
    return 0;
}

void bfs()
{
    queue<lift> q;
    q.push(s);
    while (!q.empty()) {
        now = q.front();
        if (now.height == B) {
            printf("%d\n",now.num);
            return;
        }
        nex.num = now.num + 1;
        nex.height = now.height + button[now.height];
        if (islegal(nex) == 1) {
            q.push(nex);
            vis[nex.height] = 1;
        }
        nex.height = now.height - button[now.height];
        if (islegal(nex) == 1) {
            q.push(nex);
            vis[nex.height] = 1;
        }
        q.pop();
    }
    printf("-1\n");
}

int main()
{
    while (~scanf("%d", &N) && N != 0) {
        scanf("%d%d", &A, &B);
        for (int i = 1; i <= N; i++) {
            scanf("%d",&button[i]);
        }
        s.num = 0;
        s.height = A;
        memset(vis, 0, sizeof(vis));
        bfs();
    }
    return 0;
}


// J
int maze[5][5];
bool vis[5][5];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

struct Node
{
    int x,y;
}start, now1, nex1;

struct _road
{
    vector<Node> road;
}s, now, nex;

int num = 0;

bool canstay(Node r)
{
    int i = r.x;
    int j = r.y;
    if (i >= 0 && j >= 0 && i < 5 && j < 5 && vis[i][j] == 0 && maze[i][j] == 0) {
        return 1;
    }
    return 0;
}

void bfs()
{
    queue<_road> q;
    q.push(s);
    vis[0][0] = 1;
    while (!q.empty()) {
        now = (q.front());
        now1 = now.road.back();
        if (now1.x == 4 && now1.y == 4) {
            for (int i = 0; i < now.road.size(); i++) {
                Node a = now.road[i];
                printf("(%d, %d)\n",a.x, a.y);
            }
            return;
        }

        for (int i = 0; i < 4; i++) {
            nex = now;
            nex1 = now1;
            nex1.x += dir[i][0];
            nex1.y += dir[i][1];
            if (canstay(nex1)) {
                nex.road.push_back(nex1);
                vis[nex1.x][nex1.y] = 1;
                q.push(nex);
            }
        }
        q.pop();
    }
}

int main()
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &maze[i][j]);
        }
    }
    start.x = 0;
    start.y = 0;
    s.road.push_back(start);
    bfs();
    
    return 0;
}


// E
int s,e;
struct _road {
    int x;
    int num;
}S, now, nex;
bool vis[10000];

bool isprime(int n)
{
    if (vis[n] == 1) {
        return 0;
    }
    if (n > 9999 || n < 1000 || n %2 == 0) {
        return 0;
    }
    for (int i = 3; i < n; i += 2) {
        if (n%i == 0) {
            return 0;
        }
    }
    return 1;
}

void bfs()
{
    queue<_road> q;
    q.push(S);
    while (!q.empty()) {
        now = q.front();
        if (now.x == e) {
            printf("%d\n",now.num);
            return;
        }
        // 1043
        int n = now.x;
        int a[4];
        // a[0] = 3, a[1] = 4, a[2] = 0, a[3] = 1;
        int i = 0;
        while (n != 0) {
            a[i++] = n%10;
            n /= 10;
        }
        nex.num = now.num+1;
        for (int i = 0; i <= 9; i++) {
            nex.x = a[3]*1000+a[2]*100+a[1]*10+i;
            if (isprime(nex.x) == 1) {
                q.push(nex);
                vis[nex.x] = 1;
            }
            nex.x = a[3]*1000+a[2]*100+i*10+a[0];
            if (isprime(nex.x) == 1) {
                q.push(nex);
                vis[nex.x] = 1;
            }
            nex.x = a[3]*1000+i*100+a[1]*10+a[0];
            if (isprime(nex.x) == 1) {
                q.push(nex);
                vis[nex.x] = 1;
            }
            nex.x = i*1000+a[2]*100+a[1]*10+a[0];
            if (isprime(nex.x) == 1) {
                q.push(nex);
                vis[nex.x] = 1;
            }
        }
        q.pop();
    }
    printf("Impossible\n");
    
}

int main()
{
    int _case;
    scanf("%d",&_case);
    for (int i = 1; i <= _case; i++) {
        scanf("%d%d", &s,&e);
        memset(vis, 0, sizeof(vis));
        S.num = 0;
        S.x = s;
        bfs();
    }
    return 0;
}


// B
int S,E;
int vis[200010];

struct _road {
    int x;
    int num;
}s, now, nex;

int canstay(_road r)
{
    if (r.x >= 0 && r.x <= 200010 && vis[r.x] == 0) {
        return 1;
    }
    return 0;
}

void bfs()
{
    queue<_road> q;
    q.push(s);
    vis[S] = 1;
    while (!q.empty()) {
        now = q.front();
        if (now.x == E) {
            printf("%d\n", now.num);
            return;
        }
        // x-1
        nex = now;
        nex.num++;
        nex.x -= 1;
        if (canstay(nex) == 1) {
            q.push(nex);
            vis[nex.x] = 1;
        }
        // x+1
        nex.x += 2;
        if (canstay(nex) == 1) {
            q.push(nex);
            vis[nex.x] = 1;
        }
        // x*2
        nex.x = (now.x)*2;
        if (canstay(nex) == 1) {
            q.push(nex);
            vis[nex.x] = 1;
        }
        q.pop();
    }
}


int main()
{
    while (~scanf("%d%d", &S,&E)) {
        memset(vis, 0, sizeof(vis));
        s.x = S;
        s.num = 0;
        bfs();
    }
    return 0;
}


// A
struct all {
    char maze[35][35];
}all[35], vis[35];

struct _road {
    int l;
    int x;
    int y;
    int num;
}s, e, now, nex;
int L, r, c;

int dir[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
int flag;
int sum;

void map(_road k, int state)
{
    vis[k.l].maze[k.x][k.y] = state;
}

int canstay(_road a)
{
    int i = a.l;
    int j = a.x;
    int k = a.y;
    if (i >= 0 && i < L && j >= 0 && j < r && k >= 0 && j < c
            && vis[i].maze[j][k] == 0 && (all[i].maze[j][k] == '.' || all[i].maze[j][k] == 'E')) {
            return 1;
    }
    return 0;
}

void bfs()
{
    queue<_road> q;
    q.push(s);
    while ( !q.empty() ) {
        now = q.front();
        if (now.l == e.l && now.x == e.x && now.y == e.y) {
            printf("Escaped in %d minute(s).\n", now.num);
            return;
        }
        for (int i = 0; i <= 5; i++) {
            nex = now;
            nex.num++;
            nex.l += dir[i][0];
            nex.x += dir[i][1];
            nex.y += dir[i][2];
            if (canstay(nex)) {
                q.push(nex);
                map(nex, 1);
            }
        }
        q.pop();
    }
    printf("Trapped!\n");
}


int main()
{
    while (~scanf("%d%d%d", &L, &r, &c)) {
        if (L == 0 && r == 0 && c == 0) {
            break;
        }
        sum = L*r*c;
        flag = 0;
        for (int i = 0; i < 35; i++) {
            memset(vis[i].maze, 0, sizeof(vis[i].maze));
        }
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < r; j++) {
                scanf("%s", all[i].maze[j]);
            }
        }
        for (int i = 0; i < L; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    if (all[i].maze[j][k] == 'S') {
                        s.l = i;
                        s.x = j;
                        s.y = k;
                        s.num = 0;
                    }
                    if (all[i].maze[j][k] == 'E') {
                        e.l = i;
                        e.x = j;
                        e.y = k;
                    }
                }
                
            }
        }
        bfs();
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello World!\n";
    return 0;
}
*/
