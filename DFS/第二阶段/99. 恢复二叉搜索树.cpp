/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-08 18:42:37
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-08 20:13:10
 */

/*
    DFS:
    因为二叉搜索树如果用中序遍历得到的数组肯定是递增的,而如果互换位置发生的错误那么得到的该数组一定会是如:
    163527 或者 1324567这两种
    如果是第一种(交换元素不相邻),那么交换位置后有两处会出现 a[i]>a[i+1] 和 a[j]>a[j+1]出现递减的情况,令 x = a[i], y = a[j+1];
    如果是第二种(交换元素相邻),那么交换位置后有一处会出现a[i]>a[i+1], 那么x =a[i], y = a[i+1]
    只要将书中值为x和y的两处节点的值互换就行
*/
class Solution
{
public:
    vector<int> track;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        dfs(root->left);
        track.push_back(root->val);
        dfs(root->right);
    }
    void recover(TreeNode *root, int &count, int x, int y)
    {
        if (root == nullptr || count == 0)
            return;
        if (root->val == x || root->val == y)
        {
            if (root->val == x)
            {
                root->val = y;
            }
            else
            {
                root->val = x;
            }
            count--;
        }
        recover(root->left, count, x, y);
        recover(root->right, count, x, y);
    }

    void recoverTree(TreeNode *root)
    {
        dfs(root);
        int x = -1, y = -1;
        int temp = track[0];
        int cnt = 0;
        for (int i = 0; i < track.size(); i++)
        {
            if (temp > track[i] && cnt == 0)
            {
                x = track[i - 1];
                y = track[i];
                cnt++;
            }
            else if (temp > track[i] && cnt == 1)
            {
                y = track[i];
                cnt++;
            }
            if (cnt == 2)
                break;
            temp = track[i];
        }
        int m = 2;
        recover(root, m, x, y);
        return;
    }
};
/*
    直接在树的中序遍历中就把x和y确定了
*/
class Solution
{
public:
    vector<int> track;
    int x = -1;
    int y = -1;
    int cnt = 0;
    void dfs(TreeNode *root, int &prev)
    {
        if (root == NULL || cnt == 2)
            return;
        dfs(root->left, prev);
        if (prev > root->val && cnt == 0)
        {
            x = prev;
            y = root->val;
            cnt++;
        }
        else if (prev > root->val && cnt == 1)
        {
            y = root->val;
            cnt++;
        }
        prev = root->val;
        dfs(root->right, prev);
    }
    void recover(TreeNode *root, int &count, int x, int y)
    {
        if (root == nullptr || count == 0)
            return;
        if (root->val == x || root->val == y)
        {
            if (root->val == x)
            {
                root->val = y;
            }
            else
            {
                root->val = x;
            }
            count--;
        }
        recover(root->left, count, x, y);
        recover(root->right, count, x, y);
    }

    void recoverTree(TreeNode *root)
    {
        if (root == NULL)
            return;
        int prev = INT_MIN;
        dfs(root, prev);
        int m = 2;
        recover(root, m, x, y);
        return;
    }
};