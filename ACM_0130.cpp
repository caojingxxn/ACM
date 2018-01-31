//
//  main.cpp
//  ACM_0130
//
//  Created by admin on 18/1/30.
//  Copyright © 2018年 Amon. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
char ch[55];

struct Node
{
    Node* next[26];
    Node* fail;
    int sum;
}* queue[1000010];

void Init(Node* root)
{
    root = (Node*)malloc(sizeof(Node));
    root->fail = NULL;
    root->sum = 0;
    for (int i = 0; i < 26; i++)
        root->next[i] = NULL;
}

void insert(Node* root)
{
    Node* p = root;
    for (int i = 0; ch[i] != '\0'; i++) {
        int id = ch[i] - 'a';
        if (p->next[id] == NULL) {
            Node* newnode = (Node*)malloc(sizeof(Node));
            Init(newnode);
            p->next[id] = newnode;
        }
        p = p->next[id];
    }
    p->sum++;
}

void build_fail(Node* root) // 用队列做
{
    int head = 0;
    int tail = 1;
    queue[0] = root;
    while (head < tail) {
        Node* tmp = queue[head++]; // 同时出队
        // tmp 为当前结点的父亲结点
        // tmp->next[i] 为当前结点
        for (int i = 0; i < 26; i++) {
            if (tmp->next[i] != NULL) {
                // 当前结点不为空
                if (tmp == root) {
                    // 让当前结点的fail指向root
                    tmp->next[i]->fail = root;
                }
                else
                {
                    Node* p = tmp->fail;
                    // 回溯父亲结点的fail，直到找到与自己相同的
                    while (p != NULL) {
                        if (p->next[i] != NULL) {
                            // 找到了，连上
                            tmp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if (p == NULL) {
                        // 未找到
                    }
                    
                    
                    
                    
                    
                    
                    
                }
                queue[tail++] = tmp;
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        Node* root;
        Init(root);
        
        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            scanf("%s",ch);
            insert(root);
        }
        
        build_fail(root);
        
        
        
    }
    
    return 0;
}

/*
int main(int argc, const char * argv[]) {
    
    cout << "Hello World!\n";
    return 0;
}
*/
