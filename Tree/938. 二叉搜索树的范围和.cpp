#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
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