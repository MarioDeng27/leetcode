/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-02 00:44:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-14 21:18:46
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
    TreeNode *buildCore(vector<int> &preorder, int p_left, int p_right, vector<int> &inorder, int i_left, int i_right)
    {
        if (p_right < p_left || i_right < i_left)
            return nullptr;
        TreeNode *root = new TreeNode(0);
        root->val = preorder[p_left];
        int index = i_left;
        for (int i = i_left; i <= i_right; i++)
        {
            if (preorder[p_left] == inorder[i])
                index = i;
        }
        root->left = buildCore(preorder, p_left + 1, p_left + index - i_left, inorder, i_left, index - 1);
        root->right = buildCore(preorder, p_left + index - i_left + 1, p_right, inorder, index + 1, i_right);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildCore(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};

int main()
{
    /* vector<int> vec1 = {1, 2, 3, 0};
    vector<int> vec2 = {4, 5, 6, 0};
    vector<int> vec3 = {7, 8, 9, 0};
    vector<int> vec4 = {10, 11, 12, 0};
    vector<vector<int>> A = {vec1, vec2, vec3, vec4};
    func(A); */
    cout << (new Solution())->sumNums(3);
    return 0;
}
