/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-09 15:44:53
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
    unordered_map<string, int> m;
    unordered_map<int, string> backm;
    int numOfWord = 0;
    vector<unordered_set<int>> edges;
    int addWord(string word)
    {
        if (m.count(word) == 0)
        {
            backm[numOfWord] = word;
            m[word] = numOfWord++;
            edges.push_back({});
            return numOfWord - 1;
        }
        return m[word];
    }
    void buildMap(string &word)
    {
        int id0 = addWord(word);
        for (auto &chr : word)
        {
            char tmp = chr;
            chr = '*';
            int id1 = addWord(word);
            edges[id0].insert(id1);
            edges[id1].insert(id0);
            chr = tmp;
        }
    }

    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        buildMap(beginWord);
        for (auto word : wordList)
        {
            buildMap(word);
        }
        if (m.count(endWord) == 0)
            return ans;
        unordered_set<int> q1 = {m[beginWord]};
        unordered_set<int> q2 = {m[endWord]};
        bool isfound = false, reversed = false;
        vector<vector<int>> next(numOfWord, vector<int>());
        while (!q1.empty())
        {
            unordered_set<int> q;
            for (auto src : q1)
            {
                auto set = edges[src];
                for (int dst : set)
                {
                    reversed ? next[dst].push_back(src) : next[src].push_back(dst);
                    if (q2.count(dst))
                    {
                        isfound = true;
                        break;
                    }
                    q.insert(dst);
                    edges[src].erase(dst);
                    edges[dst].erase(src);
                }
            }
            if (isfound)
                break;
            if (q.size() < q2.size())
            {
                q1 = q;
            }
            else
            {
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
        }
        if (isfound)
        {
            vector<string> path;
            backtrack(m[beginWord], m[endWord], next, path);
        }
        return ans;
    }
    void backtrack(int src, int dst, vector<vector<int>> &next, vector<string> &path)
    {
        if (src == dst)
        {
            ans.push_back(path);
            return;
        }
        for (auto &index : next[src])
        {
            if (backm[index].find('*') == string::npos)
                path.push_back(backm[index]);
            backtrack(index, dst, next, path);
            if (backm[index].find('*') == string::npos)
                path.pop_back();
        }
    }
};

int main()
{
    string w1 = "red";
    string w2 = "tax";
    vector<string> vec = {"ted", "tex", "red", "tax", "tad", "den", "rex", "pee"};
    auto r = Solution().findLadders(w1, w2, vec);
    /* for (auto n : nums1)
        cout << n << " "; */
    cout << "ss" << endl;
    return 0;
}