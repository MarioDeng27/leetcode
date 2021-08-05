/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-04 16:16:15
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-05 21:48:49
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

//后序遍历实现编码和解码
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
        string leftstr = serialize(root->left);
        string rightstr = serialize(root->right);
        string rootstr = to_string(root->val) + splitstr;
        return leftstr + rightstr + rootstr; //与前序遍历的区别
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
        string val = strlist.back();
        strlist.pop_back();
        if (val == "#")
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(val));
        root->right = deserializehelp(strlist); //与前序遍历的区别，这边先要处理好右孩子，因为strlist 根节点是放在这个列表的最后面，根节点前面的那部分是右子树，再是左子树
        root->left = deserializehelp(strlist);
        return root;
    }
};

//层序遍历，较复杂，要考虑空串的情况
class Codec
{
public:
    // Encodes a tree to a single string.
    string splitstr = ",";
    string nullstr = "#";
    string serialize(TreeNode *root)
    {
        if (root == nullptr)
            return "";
        queue<TreeNode *> que;
        que.push(root);
        string res = "";
        while (!que.empty())
        {
            TreeNode *p = que.front();
            que.pop();
            if (p == nullptr)
            {
                res += nullstr + splitstr;
                continue;
            }
            res += to_string(p->val) + splitstr;
            que.push(p->left);
            que.push(p->right);
        }
        return res;
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
        if (strlist.empty())
            return nullptr;
        queue<TreeNode *> que;
        TreeNode *root = new TreeNode(stoi(strlist.front()));
        strlist.pop_front();
        que.push(root);
        while (!strlist.empty())
        {
            TreeNode *parent = que.front(); //每次取出的都是父节点，然后根据当前的字符串来存放它的左右子节点
            que.pop();
            string left = strlist.front();
            strlist.pop_front();
            if (left != nullstr)
            {
                parent->left = new TreeNode(stoi(left));
                que.push(parent->left);
            }

            string right = strlist.front();
            strlist.pop_front();
            if (right != nullstr)
            {
                parent->right = new TreeNode(stoi(right));
                que.push(parent->right);
            }
        }
        return root;
    }
};