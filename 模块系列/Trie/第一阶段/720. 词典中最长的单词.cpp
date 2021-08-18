#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
using namespace std;
class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end(), comp);
        set<string> s;
        string res;
        for (auto word : words)
        {
            int len = word.size();
            bool flag = true;
            for (int k = 1; k < len; k++)
            {
                if (s.find(word.substr(0, k)) == s.end())
                {
                    flag = false;
                    break;
                }
            }
            if (len == 1 || flag)
            {
                if (len > res.size())
                {
                    res = word;
                }
            }
        }

        return res;
    }
    static bool comp(string &a, string &b)
    {
        if (a.size() != b.size())
            return a.size() < b.size();
        else
            return a < b;
    }
};
//--------------------------------------------
/*
	利用字典树实现1：
*/
class TrieNode
{
public:
    //比如child[i]不是NULL，当前节点的孩子序列中表示第i个节点有以他开头的字符串，即'a' + i
    TrieNode *child[26];
    bool isend = false;
    TrieNode()
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
/*
	//or:
class TrieNode
{
public:
	//比如child[i]不是NULL，　当前节点的孩子序列中表示第i个节点有以他开头的字符串，即'a' + i
	vector<TrieNode *> child;
	bool isend = false;
	TrieNode()
	{
		child = vector<TrieNode *>(26, NULL);
	}
};

*/

//构建Ｔrie的工具，insert
class Trie
{
public:
    TrieNode *root;
    Trie() { root = new TrieNode(); }
    //往字典树中添加一个单词
    void insert(string word)
    {
        TrieNode *p = root;
        for (auto w : word)
        {
            //每一个单词中的字符，在当前节点的孩子序列中的位置是: w-'a'，如果在对应孩子序列中没有出现这个字符，即p->child[i] == NULL
            //实例化该节点的第i个孩子，如果有的话则跳过，当成功加完该单词，p已遍历到最后一个节点了，最后一个节点的isend　设置　true,表示该单词添加完毕，它是一个单词
            //不过还有可能有单词以它为前缀，在最后一个节点后面继续添加字符，组成新的单词
            int i = w - 'a';
            if (p->child[i] == NULL)
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isend = true;
    }
    bool searchevery(string word)
    {
        TrieNode *p = root;
        for (auto w : word)
        {
            //如果当前节点的第i个孩子没有实例化，则说明不存在该单词，又或者，以ｗ为结尾的单词不存在在字典书中，都不满足要求
            int i = w - 'a';
            if (p->child[i] == NULL || p->child[i]->isend == false)
                return false;
            p = p->child[i];
        }
        return true;
    }
};

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        string res;
        Trie trie;
        for (auto word : words)
        {
            trie.insert(word);
        }
        for (auto word : words)
        {
            if (trie.searchevery(word) && (word.size() > res.size() || (word.size() == res.size() && word < res)))
                res = word;
        }
        return res;
    }
};
//--------------------------------------------
/*
	利用字典树实现2：
*/
class TrieNode
{
public:
    //比如child[i]不是NULL，当前节点的孩子序列中表示第i个节点有以他开头的字符串，即'a' + i
    map<char, TrieNode *> children;
    bool isend = false;
};

class Trie
{
public:
    TrieNode *root;
    Trie() { root = new TrieNode(); }
    //往字典树中添加一个单词
    void insert(string word)
    {
        TrieNode *p = root;
        for (auto w : word)
        {
            if (p->children.count(w) == 0)
            {
                p->children[w] = new TrieNode();
            }
            p = p->children[w];
        }
        p->isend = true;
    }
    bool searchevery(string word)
    {
        TrieNode *p = root;
        for (auto w : word)
        {
            //如果当前节点的第i个孩子没有实例化，则说明不存在该单词，又或者，以ｗ为结尾的单词不存在在字典书中，都不满足要求
            if (p->children.count(w) == 0 || p->children[w]->isend == false)
                return false;
            p = p->children[w];
        }
        return true;
    }
};

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        string res;
        Trie trie;
        for (auto word : words)
        {
            trie.insert(word);
        }
        for (auto word : words)
        {
            if (trie.searchevery(word) && (word.size() > res.size() || (word.size() == res.size() && word < res)))
                res = word;
        }
        return res;
    }
};
