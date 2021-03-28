/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-28 14:13:17
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-28 14:13:19
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res = "";
        if (root == nullptr)
            return res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p != nullptr)
                {
                    res += to_string(p->val) + ",";
                    q.push(p->left);
                    q.push(p->right);
                }
                else
                {
                    res += "#,";
                }
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
            return nullptr;
        vector<string> vec;
        string tmp = "";
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == ',')
            {
                vec.push_back(tmp);
                tmp = "";
            }
            else
                tmp += data[i];
        }
        TreeNode *root = new TreeNode(stoi(vec[0]));
        queue<TreeNode *> q;
        q.push(root);
        int index = 1;
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *p = q.front();
                q.pop();
                if (index < vec.size() && vec[index] != "#")
                {
                    p->left = new TreeNode(stoi(vec[index]));
                    q.push(p->left);
                }
                index++;
                if (index < vec.size() && vec[index] != "#")
                {
                    p->right = new TreeNode(stoi(vec[index]));
                    q.push(p->right);
                }
                index++;
            }
        }
        return root;
    }
};