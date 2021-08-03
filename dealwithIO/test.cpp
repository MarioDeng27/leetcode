/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-03 21:13:19
 */
/*
 * @FilePath: \Sort\test.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-10-05 22:41:14
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-02 00:37:48
 */
#include <algorithm>
#include <array>
#include <atomic>
#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <mutex>
#include <pthread.h> // pthread_create(), pthread_join()
#include <queue>
#include <semaphore.h> // sem_init()
#include <set>
#include <sstream>
#include <stack>
#include <thread>
#include <unordered_map>
#include <vector>
using namespace std;

/* #include <bits/stdc++.h>
using namespace std; */

void func(vector<vector<int>> &A)
{
    int R = A.size();
    int C = A[0].size();
    vector<vector<int>> B(R, vector<int>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            B[j][R - 1 - i] = A[i][j];
        }
    }
    A = B;
}
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct Node
{
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int key, int val) : key(key), value(value) {}
};

class DoubleList
{
private:
    int size;
    Node *head;
    Node *tail;

public:
    DoubleList()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addLast(Node *node)
    {
        node->next = tail;
        node->prev = tail->prev;

        tail->prev->next = node;
        tail->prev = node;
        size++;
    }
    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        size--;
    }
    Node *removeBegin()
    {
        Node *node = head->next;
        remove(node);
        return node;
    }
    int getSize()
    {
        return size;
    }
};

class LRUCache
{
private:
    DoubleList *doubleList;
    map<int, Node *> mp;
    int capacity;

public:
    LRUCache(int size)
    {
        doubleList = new DoubleList();
        capacity = size;
    }
    /*makeRecently，addRecently，deleteKey，deleteLeastRecently四个函数封装了对DoubleList以及map的增删改，让get和set不需要在函数体里以Node为数据去创建和删除记录*/
    //LRU里一定存在该node
    void makeRecently(int key)
    {
        Node *node = mp[key];
        doubleList->remove(node);
        doubleList->addLast(node);
    }
    void addRecently(int key, int value)
    {
        Node *node = new Node(key, value);
        doubleList->addLast(node);
        mp[node->key] = node;
    }
    void deleteKey(int key)
    {
        Node *node = mp[key];
        doubleList->remove(node);
        mp.erase(node->key);
    }
    void deleteLeastRecently()
    {
        Node *node = doubleList->removeBegin();
        mp.erase(node->key);
    }
    /*makeRecently，addRecently，deleteKey，deleteLeastRecently四个函数封装了对DoubleList以及map的增删改，让get和set不需要在函数体里以Node为数据去创建和删除记录*/
    int get(int key)
    {
        if (mp.count(key) == 1)
        {
            makeRecently(key);
            return mp[key]->value;
        }
        return -1;
    }
    void set(int key, int value)
    {
        if (mp.count(key) == 1)
        {
            deleteKey(key);
        }
        if (capacity == doubleList->getSize())
        {
            deleteLeastRecently();
        }
        addRecently(key, value);
    }
};

int main()
{
    vector<int> vec(4);
    cout << " " << endl;
    return 0;
}
