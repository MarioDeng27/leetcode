class Solution
{
public:
    vector<string> res;
    vector<vector<int>> paths;
    void dfs(TreeNode *root, vector<int> path)
    {
        if (!root->left && !root->right)
        {
            paths.push_back(path);
            return;
        }
        if (root->left)
        {
            path.push_back(root->left->val);
            dfs(root->left, path);
            path.pop_back();
        }
        if (root->right)
        {
            path.push_back(root->right->val);
            dfs(root->right, path);
            path.pop_back();
        }
    }
    vector<string> binaryTreePaths(TreeNode *root)
    {
        if (!root)
            return res;
        vector<int> path = {root->val};
        dfs(root, path);
        for (int i = 0; i < paths.size(); i++)
        {
            string str = "";
            for (int j = 0; j < paths[i].size(); j++)
            {
                if (j == paths[i].size() - 1)
                {
                    str += to_string(paths[i][j]);
                }
                else
                {
                    str += (to_string(paths[i][j]) + "->");
                }
            }
            res.push_back(str);
        }
        return res;
    }
};