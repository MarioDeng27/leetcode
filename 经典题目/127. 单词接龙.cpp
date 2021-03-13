/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-13 15:42:13
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-13 15:42:34
 */
class Solution
{
public:
    unordered_map<string, int> m;
    int numOfWord = 0;
    vector<vector<int>> edges;
    int addWord(string word)
    {
        if (m.count(word) == 0)
        {
            m[word] = numOfWord++;
            edges.push_back({});
            return numOfWord - 1;
        }
        return m[word];
    }
    void buildMap(string &word)
    {
        int id0 = addWord(word);
        for (auto &chr : word)
        {
            char tmp = chr;
            chr = '*';
            int id1 = addWord(word);
            edges[id0].push_back(id1);
            edges[id1].push_back(id0);
            chr = tmp;
        }
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        for (auto word : wordList)
        {
            buildMap(word);
        }
        buildMap(beginWord);
        if (m.count(endWord) == 0)
            return 0;
        //定义了dis，表示dis[id] = x, beginWord到id对应的单词需要走x条边。如果找到一条通向endWord的路径，则会返回dis[targetID] = y， 则总共花了y个边，然后因为由于添加了虚拟节点，所以这个边比原来大了一倍。答案是返回需要经过的单词数，所以答案为，y/2 + 1
        vector<int> dis(numOfWord, INT_MAX);
        int targetId = m[endWord];
        int startId = m[beginWord];
        dis[startId] = 0;
        queue<int> q;
        q.push(startId);
        while (!q.empty())
        {
            int currId = q.front();
            q.pop();
            for (int i = 0; i < edges[currId].size(); i++)
            {
                int tmpId = edges[currId][i];
                if (dis[tmpId] != INT_MAX)
                    continue;
                dis[tmpId] = dis[currId] + 1;
                if (tmpId == targetId)
                    return dis[tmpId] / 2 + 1;
                q.push(tmpId);
            }
        }
        return 0;
    }
};