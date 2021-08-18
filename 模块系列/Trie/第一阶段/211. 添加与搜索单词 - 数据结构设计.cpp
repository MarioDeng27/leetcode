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
class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary() { root = new TrieNode(); }
    //往字典树中添加一个单词
    void addWord(string word)
    {
        TrieNode *p = root;
        for (auto w : word)
        {
            int i = w - 'a';
            if (p->child[i] == NULL)
                p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isend = true;
    }
    //递归实现
    bool dfs(string word, int index, TrieNode *p)
    {
        //当index = word的size的时候,p也就指向了字典树中符合word的最后一个字符节点,如果这个节点的isend是true表示它的确是个单词
        //则就表示当前已搜寻到该单词
        if (index == word.size())
        {
            return p->isend;
        }
        //如果给定word中此时index 的位置的字符不是'.'则判断当前节点的孩子数组中是否存在着对应的字符word[index],判断条件就是,当前节点的对应的孩子child[j]
        //是否被实例化.如果被实例化,恭喜进入下一次的遍历,即index+1,且再下一次的dfs中,p为child[j]
        if (word[index] != '.')
        {
            int j = word[index] - 'a';
            return p->child[j] != NULL && dfs(word, index + 1, p->child[j]);
        }
        //如果给定word中此时index 的位置的字符是'.',则打算讲当前节点的所有孩子中被实例化的节点都遍历一遍(直到首次找到符合条件的一条支路,返回true),每次遍历就相当于这个孩子节点符合要求,只要继续判断下下个孩子是否符合
        //word的下一个字符就行.
        else
        {
            for (int k = 0; k < 26; k++)
            {
                if (p->child[k] != NULL)
                {
                    if (dfs(word, index + 1, p->child[k]))
                        return true;
                }
            }
            return false;
        }
    }

    bool search(string word)
    {
        TrieNode *p = root;
        return dfs(word, 0, p);
    }
};