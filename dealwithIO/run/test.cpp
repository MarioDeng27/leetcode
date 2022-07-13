/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-13 13:00:05
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
    //前两个表示第几行第几列的块，如果第三个值为5，则表示5已经在方块里了
    bool block[3][3][10];
    //前一个表示第几列
    bool cols[9][10];
    //前一个表示第几行
    bool rows[9][10];
    vector<pair<int, int>> waits;
    bool res = false;
    void dfs(vector<vector<char>> &board, int index)
    {
        if (index == waits.size())
        {
            res = true;
            return;
        }
        auto [row, col] = waits[index];
        for (int i = 1; i <= 9; i++)
        {
            if (!block[row / 3][col / 3][i] && !rows[row][i] && !cols[col][i])
            {
                board[row][col] = '0' + i;
                block[row / 3][col / 3][i] = true;
                rows[row][i] = true;
                cols[col][i] = true;
                dfs(board, index + 1);
                if (res)
                    return;
                board[row][col] = '.';
                block[row / 3][col / 3][i] = false;
                rows[row][i] = false;
                cols[col][i] = false;
            }
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        memset(block, false, sizeof(block));
        memset(rows, false, sizeof(rows));
        memset(cols, false, sizeof(cols));
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char chr = board[i][j];
                if (chr != '.')
                {
                    int pos = chr - '0';
                    rows[i][pos] = true;
                    cols[j][pos] = true;
                    block[i / 3][j / 3][pos] = true;
                }
                else
                {
                    waits.push_back({i, j});
                }
            }
        }
        dfs(board, 0);
    }
};
void show(vector<vector<char>> &vec)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<char>> vec = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    show(vec);
    Solution()
        .solveSudoku(vec);
    cout << "----------------------------" << endl;
    show(vec);
    // cout << "ss" << endl;
    return 0;
}