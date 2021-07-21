/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-19 21:01:11
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
class Solution
{
public:
    pair<ListNode *, ListNode *> reverseCore(ListNode *begin, ListNode *end)
    {
        ListNode *pre;
        ListNode *cur;
        ListNode *next;
        cur = begin;
        while (cur != end->next)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return {end, begin};
    }
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        int i = 0;
        ListNode *cur = head;
        ListNode *pre;
        ListNode *begin;
        ListNode *end;
        ListNode *next;
        ListNode *prebegin;
        ListNode *nextend;
        while (cur)
        {
            i++;
            if (i == left)
            {
                begin = cur;
                prebegin = pre;
            }
            if (i == right)
            {
                end = cur;
                nextend = cur->next;
                break;
            }
            next = cur->next;
            pre = cur;
            cur = next;
        }
        auto temp = reverseCore(begin, end);
        prebegin->next = temp.first;
        temp.second->next = nextend;
        return head;
    }
    ListNode *next = nullptr;
    ListNode *reverseBeginN(ListNode *head, int N)
    {
        if (N == 1)
        {
            next = head->next;
            return head;
        }
        ListNode *last = reverseBeginN(head->next, N - 1);
        head->next->next = head;
        head->next = next;
        return last;
    }
    ListNode *reverseBetween2(ListNode *head, int left, int right)
    {
        if (left == 1)
            return reverseBeginN(head, right);
        ListNode *last = reverseBetween2(head->next, left - 1, right - 1);
        head->next = last;
        return head;
    }
};
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
    ListNode *reverseList1(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode *pre = nullptr;
        ListNode *cur;
        ListNode *next;
        cur = head;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
int main()
{
    vector<int> vec2 = {4, 5, 1, 3, 7, 4, 6, 0};
    for (auto num : vec2)
        cout << num << " ";
    return 0;
}
