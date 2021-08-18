/*
 * @Description: https://leetcode-cn.com/problems/word-ladder/
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-07 15:51:58
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-07 15:52:52
 */

/*
    官方答案下的评论路人答案,挺容易理解的,不用构图

*/
class Solution
{
public:
    bool canchenged(const string &a, const string &b)
    {
        int len = a.size();
        int cnt = 0;
        for (int i = 0; i < len; i++)
        {
            if (a[i] != b[i])
                cnt++;
            if (cnt > 1) //如果>1直接返回
                return false;
        }
        return cnt == 1;
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> wordset(wordList.begin(), wordList.end());
        if (wordset.find(endWord) == wordset.end())
            return 0;
        queue<string> q;
        q.push(beginWord);
        string p;
        //必须消除已经是树节点的单词//不然会一直循环
        wordset.erase(beginWord);
        int distance = 1;
        while (!q.empty())
        {
            int cnt = q.size();

            for (int i = 0; i < cnt; i++)
            {
                vector<string> temp;
                p = q.front();
                q.pop();
                for (const string &str : wordset)
                {
                    if (canchenged(p, str))
                    {
                        if (str == endWord)
                            return distance + 1;
                        temp.push_back(str);
                        q.push(str);
                    }
                }
                //tmp中的单词已经是树中的节点,我们需要erase它使得后续的树节点不重复
                for (const string &str : temp)
                    wordset.erase(str);
            }
            distance++;
        }
        return 0;
    }
};