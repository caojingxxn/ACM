//
//  main.cpp
//  ACM_day_03
//
//  Created by admin on 18/1/23.
//  Copyright © 2018年 Amon. All rights reserved.
//




// I 超时
#include <iostream>
#include <list>

using namespace std;

int main()
{
    int N;
    while (~scanf("%d", &N)) {
        while (N--) {
            list<int> soldier;
            int num;
            cin >> num;
            for (int i = 0; i < num; i++) {
                soldier.push_back(i+1);
            }
            
            list<int>::iterator it;
            while (num > 3) {
                it = soldier.begin();
                while ( num > 3 && it != soldier.end() ) {
                    it++;
                    if ( it == soldier.end() ) {
                        break;
                    }
                    list<int>::iterator it2;
                    it2 = it;
                    it2++;
                    if (it2 == soldier.end()) {
                        it = soldier.erase(it);
                        num--;
                        break;
                    }
                    it = soldier.erase(it);
                    num--;
                }
                for (it = soldier.begin(); it != soldier.end(); it++) {
                    cout << *it << ' ';
                }
                cout << endl;
                it = soldier.begin();
                while ( num > 3 && it != soldier.end() ) {
                    it++;
                    if ( it == soldier.end()) {
                        break;
                    }
                    it++;
                    if ( it == soldier.end()) {
                        break;
                    }
                    list<int>::iterator it2;
                    it2 = it;
                    it2++;
                    if (it2 == soldier.end()) {
                        it = soldier.erase(it);
                        num--;
                        break;
                    }
                    it = soldier.erase(it);
                    num--;
                    
                }
                for (it = soldier.begin(); it != soldier.end(); it++) {
                    cout << *it << ' ';
                }
                cout << endl;
            }
            for (it = soldier.begin(); it != soldier.end(); it++) {
                cout << *it << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}



/*
// E
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void find_row(vector<int> relat[], int num, int t, int &row) // 查找在哪个队
{
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < relat[i].size(); j++) {
            if (relat[i][j] == num) {
                row = i;
                return;
            }
        }
    }
}

int judge(vector<int> order, int n) // 判断
{
    for (int i = 0; i < order.size(); i++) {
        if (order[i] == n) {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t = 0;
    int Scenario = 0;
    while (~scanf("%d", &t) && t != 0) {
        
        vector<int> relat[1000]; // 存储关系
        queue<int> Queue[1000]; // 存储入队出队顺序
        vector<int> order; // 存储组别是否出队完
        
        int d = 0;
        for (int i = 0; i < t; i++) {
            cin >> d;
            for (int j = 0; j < d; j++) {
                int num;
                cin >> num;
                relat[i].push_back(num);
            }
        }
        string command;
        cin >> command;
        printf("Scenario #%d\n",++Scenario);
        while ( command[0] != 'S' ) {
            if (command[0] == 'E') {
                // 入队
                int num;
                cin >> num;
                int row = 0;
                find_row(relat, num, t, row);
                Queue[row].push(num);
                if (judge(order, row) == 0) {
                    order.push_back(row);
                }
            }
            else {
                // 出队
                int row1 = order[0];
                printf("%d\n",Queue[row1].front());
                Queue[row1].pop();
                if (Queue[row1].size() == 0) {
                    order.erase(order.begin());
                }
            }
            cin >> command;
        }
        printf("\n");
    }
    return 0;
}





// B
// 人生中 第一段C++代码
//  move a onto b 将a、b上的积木还原、a放到b上
//  move a over b 将a上的积木还原，a放到b顶端
//  pile a onto b 将b上积木还原，a及a上积木放到b上
//  pile a over b a及a上积木放到b顶端


#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

vector<int> pile[25];

void search(int &row, int &height, int a) // 查看第几行和高度
{
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < pile[i].size(); j++) {
            if (pile[i][j] == a) {
                row = i;
                height = j;
                return;
            }
        }
    }
}

void reset(int a, int row, int height) // 还原某一个块上的积木
{
    for (unsigned long i = pile[row].size() - 1; i > height; i--) {
        int k = pile[row][i];
        pile[row].pop_back();
        pile[k].push_back(k);
    }
}

void block_move(int row1, int row2, int height_a) //移动a到b上，或b顶端
{
    for (int i = height_a; i < pile[row1].size(); i++) {
        pile[row2].push_back(pile[row1][i]);
    }
    pile[row1].resize( height_a );
}

int main(int argc, const char * argv[]) {
    int n;
    scanf("%d",&n);
    for ( int i = 0; i < n; i++) {
        pile[i].push_back(i);
    }
    vector<int> ::iterator it;
    string command1;
    string command2;
    while (cin >> command1 && command1 != "quit" ) {
        int a;
        cin >> a;
        cin >> command2;
        int b;
        cin >> b;
        
        int row1 = 0, row2 = 0, height1 = 0, height2 = 0;
        search(row1, height1, a);
        search(row2, height2, b);
        if (row1 == row2) {
            continue;
        }
        
        if ( command1 == "move" ) {
            if ( command2 == "onto" ) {
                // move onto
                // 将a、b上的积木还原、a放到b上
                reset(a, row1, height1);
                reset(b, row2, height2);
            }
            else {
                // move over
                // 将a上的积木还原，a放到b顶端
                reset(a, row1, height1);
            }
        }
        else {
            if ( command2 == "onto" ) {
                // pile onto
                // 将b上积木还原，a及a上积木放到b上
                reset(b, row2, height2);
            }
            // pile over
            // a及a上积木放到b顶端
        }
        block_move(row1, row2, height1);
    }
    for (int i = 0; i < n; i++) {
        printf("%d:",i);
        for (int j = 0; j < pile[i].size(); j++) {
            printf(" %d",pile[i][j]);
        }
        printf("\n");
        
    }
    return 0;
}

*/
