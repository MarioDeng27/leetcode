/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-17 21:58:35
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-17 21:58:55
 */
class Solution
{
public:
    bool dfs(vector<int> &postorder, int start, int end)
    {
        if (start >= end)
            return true;
        int root = postorder[end];
        int index = start;
        while (postorder[index] < root)
            index++;
        int leftRoot = index - 1;
        while (postorder[index] > root)
            index++;
        return index == end && dfs(postorder, start, leftRoot) && dfs(postorder, leftRoot + 1, end - 1);
    }
    bool verifyPostorder(vector<int> &postorder)
    {
        return dfs(postorder, 0, postorder.size() - 1);
    }
};