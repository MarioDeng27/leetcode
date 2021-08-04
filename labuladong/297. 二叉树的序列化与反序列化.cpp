/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-04 16:16:15
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-04 16:16:35
 */
//前序遍历实现编码和解码，后面要实现中序和后续以及层级遍历

class Codec
{
public:
    // Encodes a tree to a single string.
    string splitstr = ",";
    string nullstr = "#";
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return nullstr + splitstr;
        string rootstr = to_string(root->val) + splitstr;
        string leftstr = serialize(root->left);
        string rightstr = serialize(root->right);
        return rootstr + leftstr + rightstr;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        list<string> strlist;
        string temp = "";
        for (auto chr : data)
        {
            if (chr == ',')
            {
                strlist.push_back(temp);
                temp = "";
            }
            else
                temp += chr;
        }
        return deserializehelp(strlist);
    }
    TreeNode *deserializehelp(list<string> &strlist)
    {
        string val = strlist.front();
        strlist.pop_front();
        if (val == "#")
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserializehelp(strlist);
        root->right = deserializehelp(strlist);
        return root;
    }
};