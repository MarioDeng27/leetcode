class TrieNode
{
public:
    TrieNode *children[26];
    bool isend = false;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
    }
};

class MagicDictionary
{
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    MagicDictionary()
    {
        root = new TrieNode();
    }

    void buildDict(vector<string> dictionary)
    {
        for (auto word : dictionary)
        {
            insert(word);
        }
    }
    void insert(string word)
    {
        TrieNode *p = root;
        for (auto w : word)
        {
            int i = w - 'a';
            if (!p->children[i])
                p->children[i] = new TrieNode();
            p = p->children[i];
        }
        p->isend = true;
    }

    //递归实现
    //pos指将word中的下表索引为pos 的字符试图进行替换
    bool dfs(string word, int index, TrieNode *p, int pos)
    {
        //只要index到word的长度了,p是在第index的节点上,如果p指向的对象的isend属性是true,则返回true
        if (index == word.size())
        {
            return p->isend;
        }
        int j = word[index] - 'a';
        //当index等于pos时候,将当前节点的孩子们,不为NULL且不等于 j的循环递归,只要找到符合要求的word则就返回true,如果没有就返回false
        if (index == pos)
        {
            for (int i = 0; i < 26; i++)
            {
                if (p->children[i] != NULL && i != j)
                {
                    if (dfs(word, index + 1, p->children[i], pos))
                        return true;
                }
            }
            return false;
        }
        //如果index!=pos则就一直按正常情况下搜寻单词,如果发现字符不在当前节点的孩子域找到,则就返回false
        else
        {

            return p->children[j] != NULL && dfs(word, index + 1, p->children[j], pos);
        }
    }
    bool search(string searchWord)
    {
        for (int i = 0; i < searchWord.size(); i++)
        {
            if (dfs(searchWord, 0, root, i))
            {
                return true;
            }
        }
        return false;
    }
};