/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Tree\第一阶段\938. 二叉搜索树的范围和.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-11-08 15:12:20
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-02-04 01:20:03
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/* 
	自己的想法，通过迭代法前序遍历树
	关键利用了stack栈　先进后出的特性，把先进取的Ｒight孩子放在最后面出去
 */
class Solution
{
public:
	int rangeSumBST(TreeNode *root, int L, int R)
	{
		if (root == NULL)
			return 0;
		stack<TreeNode *> st;
		st.push(root);
		TreeNode *p = NULL;
		int sum = 0;
		while (!st.empty())
		{
			p = st.top();
			st.pop();
			if (p->val >= L && p->val <= R)
			{
				sum += p->val;
			}
			if (p->right != NULL)
				st.push(p->right);
			if (p->left != NULL)
				st.push(p->left);
		}
		return sum;
	}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/* 
	利用递归前序遍历，逻辑非常简单易实现
	但是函数调用会耗费CPU的资源
 */
class Solution
{
public:
	int min;
	int max;
	int preOder(TreeNode *p, int sum)
	{
		if (p == NULL)
			return sum;
		if (p->val >= min && p->val <= max)
		{
			sum += p->val;
		}
		sum = preOder(p->left, sum);
		sum = preOder(p->right, sum);
		return sum;
	}
	int rangeSumBST(TreeNode *root, int L, int R)
	{
		TreeNode *p = root;
		min = L;
		max = R;
		return preOder(root, 0);
	}
};
/*
	方法三：利用二叉搜索树的特点，加上三个if可以增加速度，利用dfs

*/
class Solution
{
public:
	int sum = 0;
	void dfs(TreeNode *root, int low, int high)
	{
		if (root == nullptr)
			return;
		if (root->val >= low && root->val <= high)
			sum += root->val;
		if (low < root->val)
			dfs(root->left, low, high);
		if (root->val < high)
			dfs(root->right, low, high);
	}
	int rangeSumBST(TreeNode *root, int low, int high)
	{
		dfs(root, low, high);
		return sum;
	}
};