//
//  main.cpp
//  天梯赛
//
//  Created by admin on 18/3/12.
//  Copyright © 2018年 Amon. All rights reserved.
//


/*
// 7
struct family{
    int mon1;
    int mon2;
    int fam;
    int num;
    //} family[10010];
};


int _find(int a, struct family family[]) {
    if (family[a].fam == 0 || family[a].fam == a) {
        return a;
    }
    a = _find(family[a].fam, family);
    return a;
}

void _union(int a, int b, struct family family[]) {
    a = _find(a, family);
    b = _find(b, family);
    if (a == b) {
        return;
    }
    a = a < b ? a : b;
    b = a < b ? b : a;
    family[b].fam = a;
    family[a].mon1 += family[b].mon1;
    family[a].mon2 += family[b].mon2;
    family[b].mon1 = 0;
    family[b].mon2 = 0;
    family[a].fam = a;
    family[a].num += family[b].num;
}

int main() {
    int n;
    scanf("%d", &n);
    struct family family[10010];
    for (int i = 0; i < n; ++i) {
        int now, f, m, k, a, b;
        cin >> now >> f >> m >> k;
        for (int j = 0; j < k; ++j) {
            int child;
            cin >> child;
            _union(now, child, family);
        }
        cin >> a >> b;
        family[now].mon1 = a;
        family[now].mon2 = a * b;
        if (f != -1) {
            _union(now, f, family);
        }
        if (m != -1) {
            _union(now, m, family);
        }
        
    }
    for (int i = 1000; i <= 9999; ++i) {
        if (family[i].fam == i) {
            printf("%d %d %0.3lf %0.3lf\n", i, family[i].num + 1, (double)family[i].mon1 / (double)(family[i].num + 1), (double)family[i].mon2 / (double)(family[i].num + 1));
        }
    }
    return 0;
}



//28
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            int k;
            scanf("%d", &k);
            int flag = 0;
            if (k != 2 && k % 2 == 0) {
                cout << "No" << endl;
                continue;
            }
            for (int d = 3; d < k; d += 2) {
                if (k % d == 0) {
                    cout << "No" << endl;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}



*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <cstddef>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;


/*
// L3 02
// 据说用线段树，我靠，那好麻烦啊
int cmp(int a, int b) {
    return a < b;
}

int stack[100010];
int size = 0;
int stack1[100010];

void pop() {
    if (size == 0) {
        cout << "Invalid" << endl;
    } else {
        --size;
        cout << stack[size] << endl;
    }
}

void push() {
    int value;
    cin >> value;
    stack[size++] = value;
}

void PeekMedian() {
    if (size == 0) {
        cout << "Invalid" << endl;
    } else {
        memcpy(stack1, stack, sizeof(int) * size + 20);
        sort(stack1, stack1 + size, cmp);
        if (size % 2 == 0) {
            cout << stack1[size / 2 - 1] << endl;
        } else {
            cout << stack1[size / 2] << endl;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    string com;
    for (int i = 0; i < n; ++i) {
        cin >> com;
        switch (com[1]) {
            case 'o':
                // pop
                pop();
                break;
            case 'u':
                // push
                push();
                break;
            case 'e':
                // PeekMedian 查看
                PeekMedian();
                break;
            default:
                cout << "=======" << endl;
                break;
        }
    }
    return 0;
}

////////////////////////////
//       L3
////////////////////////////

// 24
int map[10010];

int _find(int k) {
    if (k == map[k]) {
        return k;
    }
    map[k] = _find(map[k]);
    return map[k];
    
    
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int m, k;
        cin >> m >> k;
        if (map[k] == 0) {
            map[k] = k;
        }
        for (int j = 1; j < m; ++j) {
            int q;
            cin >> q;
            if (map[q] == 0) {
                map[q] = k;
            } else {
                map[_find(q)] = k;
            }
        }
    }
    int count1 = 0, count2 = 0;
    for(int i = 1; i <= 10000; ++i) {
        if (map[i] == i) {
            ++count1;
        }
        if (map[i] != 0) {
            ++count2;
        }
    }
    cout << count2 << ' ' << count1 << endl;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        a = _find(a);
        b = _find(b);
        if (a == b) {
            cout << 'Y' << endl;
        } else {
            cout << 'N' << endl;
        }
    }
    return 0;
}


// 22
struct map {
    int key;
    int prev;
    int next;
} map[100010];

int main() {
    int start, n, end = -1;
    scanf("%d%d", &start, &n);
    for (int i = 0; i < n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == -1) {
            end = a;
        } else {
            map[c].prev = a;
        }
        map[a].key = b;
        map[a].next = c;
    }
    while (start != end && map[start].next != end) {
        printf("%05d %d %05d\n", end, map[end].key, start);
        printf("%05d %d %05d\n", start, map[start].key, map[end].prev);
        end = map[end].prev;
        start = map[start].next;
    }
    if (start != end) {
        printf("%05d %d %05d\n", end, map[end].key, start);
    }
    printf("%05d %d -1\n", start, map[start].key);
    return 0;
}


// 21
struct _map {
    string name;
    set<int> s;
    double k;
};

int main() {
    int n, d;
    cin >> n;
    vector<struct _map> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].name;
        cin >> a[i].k;
        for (int j = 0; j < a[i].k; ++j) {
            cin >> d;
            (a[i].s).insert(d);
        }
    }
    unsigned long tmp = 0, tmpi = 0, tmpi1 = 0;
    for (int i = 0; i < n; ++i) {
        if (tmp < a[i].s.size() ||
            (tmp == a[i].s.size() &&
             a[i].k / (double)a[i].s.size() < a[tmpi].k / tmp)) {
                tmp = a[i].s.size();
                tmpi = i;
            }
    }
    if (n >= 1) {
        cout << a[tmpi].name << ' ';
    } else {
        cout << "- ";
    }
    if (n - 1 <= 0) {
        cout << "- ";
    } else {
        tmpi1 = (int)tmpi;
        tmp = 0, tmpi = 0;
        for (int i = 0; i < n; ++i) {
            if (i == tmpi1) {
                continue;
            }
            if (tmp < a[i].s.size() ||
                (tmp == a[i].s.size() &&
                 a[i].k / (double)a[i].s.size() < a[tmpi].k / tmp)) {
                    tmp = a[i].s.size();
                    tmpi = i;
                }
        }
        cout << a[tmpi].name << ' ';
    }
    if (n - 2 <= 0) {
        cout << "-" << endl;
    } else {
        int tmpi2 = (int)tmpi;
        tmp = 0, tmpi = 0;
        for (int i = 0; i < n; ++i) {
            if (i == tmpi1 || i == tmpi2) {
                continue;
            }
            if (tmp < a[i].s.size() ||
                (tmp == a[i].s.size() &&
                 a[i].k / (double)a[i].s.size() < a[tmpi].k / tmp)) {
                    tmp = a[i].s.size();
                    tmpi = i;
                }
        }
        cout << a[tmpi].name << endl;
    }
    return 0;
}

// 20
struct map {
    int par;
    int road;
    int mult;
} map[100010];

int findroad(int i) {
    int road = 1;
    if (i != 0 || map[i].road != 1) {
        road = findroad(map[i].par) + 1;
    }
    return road;
}

int main() {
    int n;
    double z, r;
    map[0].par = 0;
    scanf("%d%lf%lf", &n, &z, &r);
    for (int i = 0; i < n; ++i) {
        map[i].road = 1;
        map[i].mult = 0;
        int m, a;
        scanf("%d", &m);
        if (m == 0) {
            scanf("%d", &a);
            map[i].mult = a;
        } else {
            for (int j = 0; j < m; ++j) {
                scanf("%d", &a);
                map[a].par = i;
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        map[i].road = findroad(i);
    }
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        if (map[i].mult != 0) {
            double d = pow((100 - r)/100, map[i].road - 1);
            sum += d * map[i].mult * z;
        }
    }
    int ret = sum / 1;
    printf("%d\n", ret);
    return 0;
}


// 19
// 写了个set的结构体类型的排序，好吧，可以直接用map的，我个sb
struct Symbol {
    string name;
    int num;
};

struct SymCmp {
    bool operator () (const Symbol& x, const Symbol& y) const {
        if (x.name < y.name)
            return true;
        else
            return false;
    }
};

int main() {
    int n;
    while (~scanf("%d", &n)) {
        set<string> name1;
        set<Symbol, SymCmp> name2;
        string a;
        set<string>::iterator it;
        double aver = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a;
            name1.insert(a);
        }
        int m, d = 0;
        cin >> m;
        for (int i = 0; i < m; ++i) {
            Symbol a;
            cin >> a.name;
            cin >> a.num;
            aver += a.num;
            it = name1.find(a.name);
            if (it == name1.end()) {
                name2.insert(a);
                ++d;
            }
        }
        aver /= m;
        int flag = 0;
        for (int i = 0; i < d; ++i) {
            if ((*name2.begin()).num > aver) {
                cout << (*name2.begin()).name << endl;
                flag = 1;
            }
            name2.erase(name2.begin());
        }
        if (flag == 0) {
            cout << "Bing Mei You" << endl;
        }
    }
    return 0;
}


// 17
int out[100010];

int cmp(int a, int b) {
    return a < b;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> out[i];
    }
    sort(out, out + n, cmp); // 由小到大
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < n / 2; ++i) {
        sum1 += out[i];
    }
    for (int i = n / 2; i < n; ++i) {
        sum2 += out[i];
    }
    printf("Outgoing #: %d\nIntroverted #: %d\nDiff = %d\n", n - n / 2, n / 2, sum2 - sum1);
    return 0;
}


// 15
struct _stu {
    double a[15];
    double aver;
} stu[10010];

int cmp1 (double x, double y) {
    return x < y;
}

int cmp2(struct _stu x, struct _stu y) {
    return x.aver < y.aver;
}

int main() {
    int n, k, m;
    cin >> n >> m >> k; // 学生总数、每份作业的评审数、需要输出的学生数
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> stu[i].a[j];
        }
        sort(stu[i].a, stu[i].a + m, cmp1);
        for (int j = 1; j < m - 1; ++j) {
            stu[i].aver += stu[i].a[j];
        }
        stu[i].aver /= (m - 2);
    }
    sort(stu, stu + n, cmp2);
    for (int i = n - k; i < n - 1; ++i) {
        printf("%0.3lf ", stu[i].aver);
    }
    printf("%0.3lf\n", stu[n - 1].aver);
    return 0;
}


// 9
struct money {
    double m;
    int n;
    int a;
} money[10010];

int cmp(struct money a, struct money b) {
    if (a.m == b.m) {
        if (a.n == b.n) {
            return a.a < b.a;
        }
        return a.n > b.n;
    }
    return a.m > b.m;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        money[i].a = i;
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int a, b;
            cin >> a >> b;
            money[i].m -= b;
            money[a].m += b;
            ++money[a].n;
        }
    }
    sort(money + 1, money + 1 + n, cmp);
    for (int i = 1; i <= n; ++i) {
        printf("%d %0.2lf\n", money[i].a, money[i].m / 100);
    }
    return 0;
}


// 6
struct in {
    int inleft;
    int inright;
    int poleft;
    int poright;
};

int inorder[35];
int postorder[35];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &postorder[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &inorder[i]);
    }
    queue<struct in> q;
    struct in now;
    now.inleft = 0;
    now.inright = n;
    now.poleft = 0;
    now.poright = n;
    q.push(now);
    int flag = 0;
    while (!q.empty()) {
        now = q.front();
        int inl = now.inleft, inr = now.inright;
        if (inl >= inr) {
            q.pop();
            continue;
        } else {
            ++flag;
            if (flag != n) {
                cout << postorder[now.poright - 1] << ' ';
            } else {
                cout << postorder[now.poright - 1] << endl;
            }
            
        }
        int i = inl;
        for (; i < inr; ++i) {
            if (inorder[i] == postorder[now.poright - 1]) {
                now.inright = i;
                now.poright = now.poleft + i - inl;
                q.push(now);
                break;
            }
        }
        now.inleft = i + 1;
        now.inright = inr;
        now.poleft = now.poright;
        now.poright = now.poleft + now.inright - now.inleft;
        q.push(now);
        q.pop();
    }
    return 0;
}

// 5
int main() {
    int n;
    scanf("%d", &n);
    vector<set<int>> name(n + 1);
    for (int i = 1; i <= n; ++i) {
        int num;
        scanf("%d", &num);
        for (int j = 0; j < num; ++j) {
            int a;
            scanf("%d", &a);
            name[i].insert(a);
        }
    }
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        int count = 0;
        for (set<int>::iterator it = name[a].begin(); it != name[a].end(); ++it) {
            if (name[b].find(*it) != name[b].end()) {
                ++count;
            }
        }
        printf("%0.2lf", (double)count / (double)(name[a].size() + name[b].size() - count) * 100);
        cout << '%' << endl;
    }
    return 0;
}

// 3
struct cake {
    double q;
    double m;
    double aver;
}cake[1010];

int cmp(struct cake a, struct cake b) {
    return a.aver > b.aver;
}

int main() {
    int n, t;
    while (~scanf("%d%d", &n, &t)) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &cake[i].q);
        }
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &cake[i].m);
            cake[i].aver = cake[i].m / cake[i].q;
        }
        sort(cake, cake + n, cmp);
        double sum = 0;
        for (int i = 0; i < n; ++i) {
            if (cake[i].q <= t) {
                t -= cake[i].q;
                sum += cake[i].m;
            } else {
                sum += cake[i].m / (cake[i].q / t);
                break;
            }
        }
        printf("%0.2lf", sum);
    }
    
    return 0;
}

// 2
struct addr {
    int key;
    int next;
} addr[100010];

int main() {
    int n, start;
    scanf("%d%d", &start, &n);
    for (int i = 0; i < n; ++i) {
        int now, k, next;
        cin >> now >> k >> next;
        addr[now].key = k;
        addr[now].next = next;
    }
    set<int> key; // 存放key
    int flag = 0, prev = start, copystart = 0, copyend = 0, flag1 = 0;
    while (start != -1) {
        unsigned long size = key.size();
        key.insert(abs(addr[start].key));
        if (size == key.size()) {
            // 重复
            if (flag1 == 0) {
                copystart = start;
            } else {
                addr[prev].next = start;
            }
            ++flag1;
            prev = start;
            copyend = addr[start].next;
        } else {
            // 未重复
            if (flag != 0) {
                // 输出上一个结点的next
                printf("%05d\n", start);
            }
            printf("%05d %d ", start, addr[start].key);
            ++flag;
        }
        start = addr[start].next;
        flag++;
    }
    printf("-1\n");
    flag1 = 0;
    while (copystart != copyend) {
        if (flag1 != 0) {
            // 输出上一个结点的next
            printf("%05d\n", copystart);
        }
        ++flag1;
        printf("%05d %d ", copystart, addr[copystart].key);
        copystart = addr[copystart].next;
    }
    if (flag1 != 0) {
        printf("-1\n");
    }
    return 0;
}

/////////////////////////////////////////////
// L1
/////////////////////////////////////////////


// 48
int main() {
    int a1, a2, b1, b2;
    int a[1000][1000];
    int b[1000][1000];
    while (~scanf("%d%d", &a1, &a2)) {
        for (int i = 0; i < a1; ++i) {
            for (int j = 0; j < a2; ++j) {
                scanf("%d", &a[i][j]);
            }
        }
        scanf("%d%d", &b1, &b2);
        for (int i = 0; i < b1; ++i) {
            for (int j = 0; j < b2; ++j) {
                scanf("%d", &b[i][j]);
            }
        }
        if (a2 != b1) {
            printf("Error: %d != %d\n", a2, b1);
            continue;
        } else {
            printf("%d %d\n", a1, b2);
            for (int i = 0; i < a1; ++i) {
                for (int k = 0; k < b2 - 1; ++k) {
                    int sum = 0;
                    for (int j = 0; j < a2; ++j) {
                        sum += a[i][j] * b[j][k];
                    }
                    cout << sum << ' ';
                }
                int sum = 0;
                for (int j = 0; j < a2; ++j) {
                    sum += a[i][j] * b[j][b2 - 1];
                }
                cout << sum << endl;
            }
        }
    }
    return 0;
}


// 47
int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            char name[10];
            int a, b;
            scanf("%s%d%d", name, &a, &b);
            if (a > 20 || a < 15 || b < 50 || b > 70) {
                cout << name << endl;
            }
        }
    }
    return 0;
}


// 46
int candiv(int len, int n) {
    int s = 0;
    int ret[1010];
    for (int i = 0; i < len; ++i) {
        int t = s * 10 + 1;
        ret[i] = t / n;
        s = t % n;
    }
    if (s % n != 0) {
        return 0;
    } else {
        int i = 0;
        while (ret[i] == 0)
            ++i;
        for ( ; i < len; ++i)
            cout << ret[i];
        cout << ' ' << len << endl;
        return 1;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    for (int len = 1; ; ++len)
        if (candiv(len, n))
            break;
    return 0;
}


// 45
int main() {
    char str[10];
    while (~scanf("%s", str)) {
        printf("Hello %s\n", str);
    }
    return 0;
}


// 44
int main() {
    int n;
    while (~scanf("%d", &n)) {
        char str[10];
        int i = 0;
        while (scanf("%s", str) && strcmp(str, "End") != 0) {
            if (i == n) {
                cout << str << endl;
                i = 0;
            } else {
                if (strcmp(str, "ChuiZi") == 0) {
                    cout << "Bu" << endl;
                } else if (strcmp(str, "JianDao") == 0) {
                    cout << "ChuiZi" << endl;
                } else {
                    cout << "JianDao" << endl;
                }
                ++i;
            }
        }
    }
    return 0;
}


// 43
struct time {
    int hour;
    int min;
};

struct book {
    int Last; // 记录上一次是借还是还 0 还 1 借
    struct time S; // 记录上次借的时间
} book[1010];

int d;

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        memset(book, 0, sizeof(book));
        struct time read; // 记录阅读了多少时间
        read.hour = 0;
        read.min = 0;
        int num;
        int count = 0;
        while (cin >> num && num != 0) {
            char sym;
            scanf(" %c", &sym);
            switch (sym) {
                case 'S':
                    scanf("%d:%d", &book[num].S.hour, &book[num].S.min);
                    book[num].Last = 1;
                    break;
                case 'E':
                    int h, m;
                    scanf("%d:%d", &h, &m);
                    if (book[num].Last == 1) {
                        read.hour += h - book[num].S.hour;
                        read.min += m - book[num].S.min;
                        book[num].Last = 0;
                        ++count;
                    }
                    // huan
                    break;
                default:
                    cout << "========" << endl;
                    break;
            }
        }
        char k[2];
        scanf("%s%d:%d", k, &d, &d);
        if (count == 0) {
            printf("0 0\n");
        } else {
            double aver = (double)(read.hour * 60 + read.min) / (double)count;
            printf("%d %0.0lf\n", count, aver);
        }
    }
    return 0;
}

// 42
int main() {
    int a, b, c;
    while (~scanf("%d-%d-%d", &a, &b, &c)) {
        printf("%d-%02d-%02d\n", c, a, b);
    }
    return 0;
}


// 41
int main() {
    int n = 1, num;
    char ch;
    while (~scanf("%d%c", &num, &ch)) {
        n = 2;
        int flag = 0;
        if (num == 250) {
            cout << 1 << endl;
            flag = 1;
        }
        while (scanf("%d%c", &num, &ch)) {
            if (num == 250 && flag == 0) {
                cout << n << endl;
                flag = 1;
            }
            ++n;
            if (ch == '\n') {
                break;
            }
        }
    }
    return 0;
}


// 40
int main() {
    int n;
    char ch;
    while (~scanf("%d%c", &n, &ch)) {
        for (int i = 0; i < n; ++i) {
            char sex;
            double H;
            scanf("%c%lf%c", &sex, &H, &ch);
            if (sex == 'F') {
                printf("%0.2lf\n", H * 1.09);
            } else {
                printf("%0.2lf\n", H / 1.09);
            }
        }
    }
    return 0;
}


// 39
int main() {
    int n;
    char str[1000], ch;
    while (~scanf("%d%c", &n, &ch)) {
        
        fgets(str+1, 1010, stdin);
        unsigned long len = strlen(str + 1);
        str[len] = '\0';
        int i = 1;
        while (i + n < len) {
            i += n;
        }
        int k = i + n;
        for (int j = i; j < k; ++j) {
            i = j;
            while (i > 0) {
                if (i >= len) {
                    cout << ' ';
                } else {
                    cout << str[i];
                }
                i -= n;
            }
            cout << endl;
        }
    }
    return 0;
}


// 38
int main() {
    printf("Hello World\nHello New World\n");
    return 0;
}


// 37
int main() {
    double a, b;
    while (~scanf("%lf%lf", &a, &b)) {
        cout << a << '/';
        if (b == 0) {
            cout << b << "=Error" << endl;
            continue;
        } else if (b < 0) {
            cout << '(' << b << ')';
        } else {
            cout << b;
        }
        printf("=%0.2lf\n", a / b);
    }
    return 0;
}


// 36
int main() {
    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        cout << a * b << endl;
    }
    return 0;
}

// 35
char name[10000][16];

int main() {
    int n = 0;
    while (scanf("%s", name[n]) && strcmp(name[n], ".") != 0) {
        ++n;
    }
    if (n < 2) {
        printf("Momo... No one is for you ...\n");
    }
    else if (n >= 15) {
        printf("%s and %s are inviting you to dinner...\n", name[1], name[13]);
    } else{
        printf("%s is the only one for you...\n", name[1]);
    }
    return 0;
}

// 34
int F[1010];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        memset(F, 0, sizeof(F));
        for (int i = 0; i < n; ++i) {
            int K;
            scanf("%d", &K);
            for (int j = 0; j < K; ++j) {
                int f;
                scanf("%d", &f);
                ++F[f];
            }
        }
        int tmp = 0, tmpi = 0;
        for (int i = 1; i <= 1000; ++i) {
            if (F[i] >= tmp) {
                tmp = F[i];
                tmpi = i;
            }
        }
        cout << tmpi << ' ' << tmp << endl;
    }
    return 0;
}


// 33
int main() {
    
    int n, def;
    while (~scanf("%d%d", &n, &def)) {
        for (int i = n; ; ++i) {
            set<int> age;
            age.insert(i % 10);
            age.insert(i / 10 % 10);
            age.insert(i / 100 % 10);
            age.insert(i / 1000);
            if (age.size() == def) {
                printf("%d %04d\n", i - n, i);
                break;
            }
        }
    }
    return 0;
}


// 32
char str[1001000];
int main() {
    unsigned long n;
    char ch, k;
    while (~scanf("%lu %c%c", &n, &ch, &k)) {
        fgets(str, 1001000, stdin);
        unsigned long len = strlen(str);
        if (len <= n) {
            for (unsigned long i = 0; i < n - len + 1; ++i) {
                cout << ch;
            }
            cout << str;
        } else {
            for (unsigned long i = len - n - 1; i < len; ++i) {
                cout << str[i];
            }
        }
    }
    return 0;
}


// 31
int main() {
    int n;
    double H, W;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%lf%lf", &H, &W);
            H -= 100;
            H *= 1.8;
            if (fabs(W - H) < H * 0.1) {
                cout << "You are wan mei!" << endl;
            } else if ( (W - H > H * 0.1) ||
                       (fabs(W - H - H * 0.1) < 0.0000001) ) {
                cout << "You are tai pang le!" << endl;
            } else {
                cout << "You are tai shou le!" << endl;
            }
        }
    }
    return 0;
}


// 30
struct stu {
    char name[10];
    int sex;
    bool isarrange;
} stu[55];

int main() {
    int n;
    while (~scanf("%d", &n)) {
        for (int i = 0; i < n; ++i) {
            scanf("%d%s", &stu[i].sex, stu[i].name);
            stu[i].isarrange = 0;
        }
        for (int i = 0; i < n; ++i) {
            if (stu[i].isarrange == 1) {
                continue;
            }
            cout << stu[i].name << ' ';
            for (int j = n - 1; j > i; --j) {
                if (stu[j].sex != stu[i].sex && stu[j].isarrange == 0) {
                    stu[j].isarrange = 1;
                    cout << stu[j].name << endl;
                    break;
                }
            }
        }
    }
    return 0;
}


// 29
int main() {
    double H;
    while (~scanf("%lf", &H)) {
        H -= 100;
        H *= 1.8;
        printf("%0.1lf", H);
    }
    return 0;
}


// 27
int main() {
    char str[15];
    while (~scanf("%s", str)) {
        int a[10];
        memset(a, 0, sizeof(a));
        for (int i = 0; str[i] != '\0'; ++i) {
            ++a[str[i] - '0'];
        }
        int arr[15];
        int count = 0;
        for (int i = 9; i >= 0; --i) {
            if (a[i] != 0) {
                arr[count++] = i;
            }
        }
        cout << "int[] arr = new int[]{";
        for (int i = 0; i < count - 1; ++i) {
            cout << arr[i] << ',';
        }
        cout << arr[count - 1] << "};" << endl << "int[] index = new int[]{";
        int i = 0;
        for (; str[i + 1] != '\0'; ++i) {
            for (int j = 0; j < count; ++j) {
                if (str[i] - '0'== arr[j]) {
                    cout << j << ',';
                    continue;
                }
            }
        }
        for (int j = 0; j < count; ++j) {
            if (str[i] - '0' == arr[j]) {
                cout << j << "};" << endl;;
                continue;
            }
        }
    }
}


// 26
int main() {
    printf("I\n \nL\no\nv\ne\n \nG\nP\nL\nT\n");
    return 0;
}


// 25
int main() {
    char str1[1000];
    char str2[1000];
    char str[1000];
    while (fgets(str, 1000, stdin)) {
        int i = 0, flag1 = 0;
        // 1 为判定str1阶段
        for (; str[i] != '\0'; ++i) {
            if (str[i] == ' ') {
                if (i == 0) {
                    flag1 = 1;
                }
                break;
            }
            if (flag1 == 1) {
                continue;
            }
            if (str[i] > '9' || str[i] < '0') {
                flag1 = 1;
            } else {
                str1[i] = str[i];
            }
        }
        str1[i] = '\0';
        ++i;
        int flag2 = 0;
        int j = 0;
        for (; str[i] != '\0'; ++i) {
            if (str[i+1] == '\0' && str[i] == '\n') {
                continue;
            }
            if (str[i] > '9' || str[i] < '0') {
                flag2 = 1;
            } else {
                str2[j++] = str[i];
            }
        }
        str2[j] = '\0';
        if (strcmp(str1, "0") == 0 || strlen(str1) > 4) {
            flag1 = 1;
        }
        if (strcmp(str2, "0") == 0 || strlen(str2) > 4) {
            flag2 = 1;
        }
        if (flag1 == 0 && flag2 == 0) {
            int a = atoi(str1), b = atoi(str2);
            int c = a + b;
            if (a <= 1000) {
                cout << a << " + ";
            } else {
                cout << '?' << " + ";
            }
            if (b <= 1000) {
                cout << b << " = ";
            } else {
                cout << '?' << " = ";
            }
            if (a <= 1000 && b <= 1000) {
                cout << c << endl;
            } else {
                cout << '?' << endl;
            }
        } else if (flag1 == 0 && flag2 == 1) {
            cout << str1 << " + ? = ?" << endl;
        } else if (flag1 == 1 && flag2 == 0) {
            cout << "? + " << str2 <<" = ?" << endl;
        } else {
            cout << "? + ? = ?" << endl;
        }
    }
    return 0;
}


// 24
int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n <= 5) {
            cout << n + 2 << endl;
        } else {
            cout << n - 5 << endl;
        }
    }
    return 0;
}


// 23
int main() {
    char str[10010];
    while (~scanf("%s", str)) {
        int G = 0, P = 0, L = 0, T = 0;
        for (int i = 0; str[i] != '\0'; ++i) {
            if (str[i] == 'g' || str[i] == 'G') {
                ++G;
            } else if (str[i] == 'p' || str[i] == 'P') {
                ++P;
            } else if (str[i] == 'l' || str[i] == 'L') {
                ++L;
            } else if (str[i] == 't' || str[i] == 'T') {
                ++T;
            }
        }
        while (G > 0 || P > 0 || L > 0 || T > 0) {
            if (G > 0) {
                cout << 'G';
                --G;
            }
            if (P > 0) {
                cout << 'P';
                --P;
            }
            if (L > 0) {
                cout << 'L';
                --L;
            }
            if (T > 0) {
                cout << 'T';
                --T;
            }
        }
    }
    return 0;
}


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

// 20
int main() {
    int n, k;
    scanf("%d", &n);
    vector<set<int>> frid(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &k);
        for (int j = 0; j < k; ++j) {
            int q;
            scanf("%d", &q);
            frid[i].insert(q);
        }
    }
    cin >> k;
    int flag = 0;
    set<int> aaa;
    for (int i = 0; i < k; ++i) {
        int num;
        scanf("%d", &num);
        unsigned long size = aaa.size();
        aaa.insert(num);
        if (size == aaa.size()) {
            continue;
        }
        int flag1 = 0;
        for (int j = 0; j < n; ++j) {
            set<int>::iterator it = frid[j].find(num);
            if (it != frid[j].end() && frid[j].size() > 1) {
                flag1 = 1;
            }
        }
        if (flag1 == 0 && flag == 0) {
            ++flag;
            printf("%05d", num);
        } else if (flag1 == 0) {
            ++flag;
            printf(" %05d", num);
        }
    }
    if (flag == 0) {
        cout << "No one is handsome";
    }
    cout << endl;
    return 0;
}


// 19
int main() {
    int a, b, n;
    scanf("%d%d%d", &a, &b, &n);
    int count1 = 0, count2 = 0, flag = 0, a1, a2, a3, a4;
    
    for (int i = 0; i < n; ++i) {
        scanf("%d%d%d%d", &a1, &a2, &a3, &a4);
        if (a2 == a1 + a3 && flag == 0 && a4 != a1 + a3) {
            ++count1;
        }
        if (a4 == a1 + a3 && flag == 0 && a2 != a1 + a3) {
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


// 16
int check[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char m[12] = "10X98765432";

struct _id {
    char test[19];
    int sum;
} _id;

int main() {
    int n;
    cin >> n;
    int f = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", _id.test);
        int sum = 0;
        for (int j = 0; j < 17; ++j) {
            sum += check[j] * (_id.test[j] - '0');
        }
        sum %= 11;
        if (m[sum] != _id.test[17]) {
            cout << _id.test << endl;
            f = 1;
        }
    }
    if (f == 0) {
        cout << "All passed" << endl;
        
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


// 6
int main() {
    int n;
    scanf("%d", &n);
    int max = sqrtl(n);
    int min = n;
    for (int len = 12; len >= 1; --len) {
        for (int l = 2; l <= max; ++l) {
            if (l < min && n % l == 0) {
                min = l;
            }
            int flag = 0;
            int d = n;
            for (int r = l; r <= l + len && r <= n; ++r) {
                if (d % r == 0) {
                    d /= r;
                } else {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                cout << len + 1 << endl;
                for (int i = 0; i < len; ++i)
                    printf("%d*", l + i);
                printf("%d\n", l + len);
                return 0;
            }
        }
    }
    printf("1\n%d\n", min);
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


// 2
int main() {
    double n;
    char ch, ch2;
    while (~scanf("%lf%c%c", &n, &ch2, &ch)) {
        double h = sqrt( (n + 1) / 2 );
        int high = (int)h;
        int m = 0;
        for (int i = 2 * high - 1; i >= 1; i -= 2) {
            for (int j = 0; j < m; ++j) {
                cout << ' ';
            }
            ++m;
            for (int j = 1; j <= i; ++j) {
                cout << ch;
            }
            cout << endl;
        }
        --m;
        for (int i = 3; i <= 2 * high - 1; i += 2) {
            --m;
            for (int j = 0; j < m; ++j) {
                cout << ' ';
            }
            for (int j = 1; j <= i; ++j) {
                cout << ch;
            }
            cout << endl;
        }
        int d = n - high * high * 2 + 1;
        cout << d << endl;
        
    }
    return 0;
}

*/
