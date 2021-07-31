/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-07-26 18:31:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-07-26 18:32:03
 */
//解题思路：https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247487527&idx=1&sn=9cf2b0d8608ba26ea7c6a5c9b41d05a1&scene=21#wechat_redirect
class Solution
{
public:
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "#";
        string left = serialize(root->left);
        string right = serialize(root->right);
        return left + "," + right + "," + to_string(root->val);
    }

    map<string, int> mp;
    vector<TreeNode *> res;
    string traverse(TreeNode *root)
    {
        if (root == nullptr)
            return "#";
        string left = traverse(root->left);
        string right = traverse(root->right);
        string key = left + "," + right + "," + to_string(root->val);
        if (mp.count(key) != 0 && mp[key] == 1)
            res.push_back(root);
        mp[key]++;
        return key;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        traverse(root);
        return res;
    }
};