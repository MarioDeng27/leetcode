/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-07-09 12:56:49
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-09 16:15:44
 */
//单向BFS+回溯，部分对，会超出时间限制
class Solution
{
public:
    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> dict;
        for (auto word : wordList)
        {
            dict.insert(word);
        }
        if (dict.find(endWord) == dict.end())
            return ans;
        dict.erase(beginWord);
        dict.erase(endWord);
        queue<string> q1;
        q1.push(beginWord);
        unordered_map<string, vector<string>> next;
        bool isfound = false;
        while (!q1.empty())
        {
            unordered_set<string> remove;
            int size = q1.size();
            for (int k = 0; k < size; k++)
            {
                string w = q1.front();
                q1.pop();
                string s = w;
                for (int i = 0; i < s.size(); i++)
                {
                    char chr = s[i];
                    for (int j = 0; j < 26; j++)
                    {
                        s[i] = 'a' + j;
                        if (endWord == s)
                        {
                            next[w].push_back(s);
                            isfound = true;
                        }
                        if (dict.find(s) != dict.end())
                        {
                            next[w].push_back(s);
                            if (remove.find(s) == remove.end())
                            {
                                q1.push(s);
                                remove.insert(s);
                            }
                        }
                    }
                    s[i] = chr;
                }
            }

            if (isfound)
            {
                break;
            }
            for (auto word : remove)
            {
                dict.erase(word);
            }
        }
        if (isfound)
        {
            vector<string> path;
            path.push_back(beginWord);
            backtrack(beginWord, endWord, next, path);
        }
        return ans;
    }
    void backtrack(string beginWord, string endWord, unordered_map<string, vector<string>> &next, vector<string> &path)
    {
        if (beginWord == endWord)
        {
            ans.push_back(path);
            return;
        }
        for (auto &word : next[beginWord])
        {
            path.push_back(word);
            backtrack(word, endWord, next, path);
            path.pop_back();
        }
    }
};

//双向BFS+回溯，部分对，会超出时间限制
class Solution
{
public:
    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        //保存单词列表中还未与队头和队尾连接起来的单词集合
        unordered_set<string> dict;
        for (auto word : wordList)
        {
            dict.insert(word);
        }
        if (dict.find(endWord) == dict.end())
            return ans;
        //删去队头和队尾
        dict.erase(beginWord);
        dict.erase(endWord);
        //双向的队列，q1的长度（节点数）始终会比q2少
        unordered_set<string> q1 = {beginWord};
        unordered_set<string> q2 = {endWord};
        //构建图的结构体，key为string，value为vector<string>
        unordered_map<string, vector<string>> next;
        //判断q1是正向还是逆向
        bool reversed = false, isfound = false;
        while (!q1.empty())
        {
            //用来存放BFS遍历的结果，即以q1为上一层，q2为下一层的队列
            unordered_set<string> q;
            //取q1每个单词，他们都是同一层
            for (auto &w : q1)
            {
                string s = w;
                //每个单词每个位置
                for (int i = 0; i < s.size(); i++)
                {
                    char chr = s[i];
                    //每个位置可以更换26个字母
                    for (int j = 0; j < 26; j++)
                    {
                        s[i] = 'a' + j;
                        //如果在q2中发现，则正面两边已走通，是其中一个通路答案（注意：q1或q2中有的单词，dict必定没有）
                        if (q2.find(s) != q2.end())
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            isfound = true;
                        }
                        //若dict中有，则建立起图，将该单词放入q中
                        if (dict.find(s) != dict.end())
                        {
                            reversed ? next[s].push_back(w) : next[w].push_back(s);
                            q.insert(s);
                        }
                    }
                    //回归原型
                    s[i] = chr;
                }
            }
            if (isfound)
            {
                break;
            }
            //从dict中删去q中已经通过bfs遍历到的单词
            for (auto w : q)
            {
                dict.erase(w);
            }
            //保持q1最短的情况，但需要区分正向还是逆向
            if (q.size() <= q2.size())
            {
                q1 = q;
            }
            else
            {
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
        }

        if (isfound)
        {
            //回溯通过DFS找到答案
            vector<string> path;
            path.push_back(beginWord);
            backtrack(beginWord, endWord, next, path);
        }
        return ans;
    }
    void backtrack(string beginWord, string endWord, unordered_map<string, vector<string>> &next, vector<string> &path)
    {
        if (beginWord == endWord)
        {
            ans.push_back(path);
            return;
        }
        for (auto &word : next[beginWord])
        {
            path.push_back(word);
            backtrack(word, endWord, next, path);
            path.pop_back();
        }
    }
};
//用*方法来构建图，用单向BFS和回溯，超出时间限制
class Solution
{
public:
    unordered_map<string, int> m;
    unordered_map<int, string> backm;
    int numOfWord = 0;
    vector<unordered_set<int>> edges;
    int addWord(string word)
    {
        if (m.count(word) == 0)
        {
            backm[numOfWord] = word;
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
            edges[id0].insert(id1);
            edges[id1].insert(id0);
            chr = tmp;
        }
    }

    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        buildMap(beginWord);
        for (auto word : wordList)
        {
            buildMap(word);
        }
        if (m.count(endWord) == 0)
            return ans;
        queue<int> q;
        bool isfound = false;
        q.push(m[beginWord]);
        vector<vector<int>> next(numOfWord, vector<int>());
        while (!q.empty())
        {
            int size = q.size();
            unordered_set<int> mem;
            for (int i = 0; i < size; i++)
            {
                int src = q.front();
                q.pop();
                auto set = edges[src];
                for (int dst : set)
                {
                    next[src].push_back(dst);
                    if (dst == m[endWord])
                    {
                        isfound = true;
                    }
                    if (mem.count(dst) == 0)
                    {
                        q.push(dst);
                        mem.insert(dst);
                    }
                    edges[src].erase(dst);
                    edges[dst].erase(src);
                }
            }
            if (isfound)
                break;
        }
        if (isfound)
        {
            vector<string> path = {beginWord};
            backtrack(m[beginWord], m[endWord], next, path);
        }
        return ans;
    }
    void backtrack(int src, int dst, vector<vector<int>> &next, vector<string> &path)
    {
        if (src == dst)
        {
            ans.push_back(path);
            return;
        }
        for (auto &index : next[src])
        {
            if (backm[index].find('*') == string::npos)
                path.push_back(backm[index]);
            backtrack(index, dst, next, path);
            if (backm[index].find('*') == string::npos)
                path.pop_back();
        }
    }
};
//用*方法来构建图，用双向BFS和回溯，超出时间限制
class Solution
{
public:
    unordered_map<string, int> m;
    unordered_map<int, string> backm;
    int numOfWord = 0;
    vector<unordered_set<int>> edges;
    int addWord(string word)
    {
        if (m.count(word) == 0)
        {
            backm[numOfWord] = word;
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
            edges[id0].insert(id1);
            edges[id1].insert(id0);
            chr = tmp;
        }
    }

    vector<vector<string>> ans;
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        buildMap(beginWord);
        for (auto word : wordList)
        {
            buildMap(word);
        }
        if (m.count(endWord) == 0)
            return ans;
        unordered_set<int> q1 = {m[beginWord]};
        unordered_set<int> q2 = {m[endWord]};
        bool isfound = false, reversed = false;
        vector<vector<int>> next(numOfWord, vector<int>());
        while (!q1.empty())
        {
            unordered_set<int> q;
            for (auto src : q1)
            {
                auto set = edges[src];
                for (int dst : set)
                {
                    reversed ? next[dst].push_back(src) : next[src].push_back(dst);
                    if (q2.count(dst))
                    {
                        isfound = true;
                    }
                    q.insert(dst);
                    edges[src].erase(dst);
                    edges[dst].erase(src);
                }
            }
            if (isfound)
                break;
            if (q.size() < q2.size())
            {
                q1 = q;
            }
            else
            {
                reversed = !reversed;
                q1 = q2;
                q2 = q;
            }
        }
        if (isfound)
        {
            vector<string> path = {beginWord};
            backtrack(m[beginWord], m[endWord], next, path);
        }
        return ans;
    }
    void backtrack(int src, int dst, vector<vector<int>> &next, vector<string> &path)
    {
        if (src == dst)
        {
            ans.push_back(path);
            return;
        }
        for (auto &index : next[src])
        {
            if (backm[index].find('*') == string::npos)
                path.push_back(backm[index]);
            backtrack(index, dst, next, path);
            if (backm[index].find('*') == string::npos)
                path.pop_back();
        }
    }
};
//能通过
class Solution
{
public:
    unordered_set<string> S;                           //对单词列表进行去重
    unordered_map<string, int> dist;                   //记录单词的最短路径
    queue<string> q;                                   // bfs用的队列
    vector<vector<string>> ans;                        //存放ans
    vector<string> path;                               //存放单条路径
    unordered_map<string, unordered_set<string>> from; //建立字符串之间的有向图
    string beginWord;                                  //存放beginwords用于dfs使用，减少参数传递

    vector<vector<string>> findLadders(string _beginWord, string endWord, vector<string> &wordList)
    {
        for (const auto &x : wordList)
            S.insert(x);
        beginWord = _beginWord;
        dist[beginWord] = 0;
        q.push(beginWord);

        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            string r = t;
            for (int i = 0; i < t.size(); ++i)
            {
                t = r;
                for (char c = 'a'; c <= 'z'; ++c)
                {
                    t[i] = c;
                    //如果t存在于S中且是(第一次访问到t或者t的距离等于rd的距离+1)，则建立对应的有向图[第一次访问到肯定是距离最短的，肯定能建立图。然后如果t距离已存在，则肯定是最短，如果当前的路径能到达t且值与之前相等，则也是最短路径之一，所以也能剪建立图]
                    if (S.count(t) && (dist.count(t) == 0 || dist[t] == dist[r] + 1))
                        from[t].insert(r);

                    ////bfs第一次遍历到的点一定是最短路径
                    //如果集合中存在t且是第一次遍历到该点
                    if (S.count(t) && dist.count(t) == 0)
                    {
                        dist[t] = dist[r] + 1;
                        if (t == endWord)
                            break;
                        q.push(t);
                    }
                }
            }
        }
        if (dist.count(endWord) == 0)
            return ans;
        path.emplace_back(endWord);
        dfs(endWord);
        return ans;
    }

    void dfs(string t)
    {
        if (t == beginWord)
        {
            ans.push_back({path.rbegin(), path.rend()});
            return;
        }

        for (const auto &x : from[t]) //遍历t的源点
        {
            path.emplace_back(x);
            dfs(x);
            path.pop_back();
        }
    }
};
