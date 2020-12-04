/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-04 21:14:20
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-04 21:15:08
 */
/*
    自己的想法,
    参考了第211和720中的方法,但是search的时候会不一样,感觉这个版本的更好一点
*/
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
class Trie
{
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        TrieNode *p = root;
        for (auto ch : word)
        {
            if (p->children[ch - 'a'] == NULL)
            {
                p->children[ch - 'a'] = new TrieNode();
            }
            p = p->children[ch - 'a'];
        }
        p->isend = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        TrieNode *p = root;
        for (auto ch : word)
        {
            if (p->children[ch - 'a'] == NULL)
                return false;
            p = p->children[ch - 'a'];
        }
        return p->isend;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        TrieNode *p = root;
        for (auto ch : prefix)
        {
            if (p->children[ch - 'a'] == NULL)
                return false;
            p = p->children[ch - 'a'];
        }
        return true;
    }
};