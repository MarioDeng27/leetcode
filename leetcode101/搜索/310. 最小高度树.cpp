/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-07-12 13:53:59
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-12 15:15:34
 */
// BFS超时
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        unordered_map<int, set<int>> mp;
        for (auto edge : edges)
        {
            mp[edge[0]].insert(edge[1]);
            mp[edge[1]].insert(edge[0]);
        }
        unordered_map<int, vector<int>> recored;
        auto t_mp = mp;
        int level_min = n;
        for (auto item : t_mp)
        {
            int root = item.first;
            queue<int> que;
            int level = -1;
            que.push(root);
            while (!que.empty())
            {
                int size = que.size();
                for (int i = 0; i < size; i++)
                {
                    int node = que.front();
                    que.pop();
                    set<int> set = mp[node];
                    for (auto neibor : set)
                    {
                        que.push(neibor);
                        mp[node].erase(neibor);
                        mp[neibor].erase(node);
                    }
                }
                level++;
            }
            level_min = min(level_min, level);
            recored[level].push_back(root);
            mp = t_mp;
        }
        return recored[level_min];
    }
};
// DFS + 备忘录超时
class Solution
{
public:
    // node,parent
    map<pair<int, int>, int> mem;
    int dfs(unordered_map<int, set<int>> &mp, int node, int parent)
    {
        int res = 0;
        for (auto neibor : mp[node])
        {
            if (neibor == parent)
                continue;
            if (mem.find({neibor, node}) != mem.end())
            {
                res = max(mem[{neibor, node}] + 1, res);
            }
            else
            {
                res = max(dfs(mp, neibor, node) + 1, res);
            }
        }
        mem[{node, parent}] = res;
        return res;
    }
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        unordered_map<int, set<int>> mp;
        for (auto edge : edges)
        {
            mp[edge[0]].insert(edge[1]);
            mp[edge[1]].insert(edge[0]);
        }
        int level_min = n;
        unordered_map<int, vector<int>> recored;
        for (int i = 0; i < n; i++)
        {
            int level = dfs(mp, i, -1);
            level_min = min(level, level_min);
            recored[level].push_back(i);
        }
        return recored[level_min];
    }
};
// BFS,首先构图，并找出出度为1的node进队列，每遍历队列里的node就将node相邻点的node的出度减1，然后将出度为1的在继续放到队列里，直到最后剩下的出度为1的点就是答案
//数学的思想，其实就是让那些在图中越是靠中间的点作为根，高度越低
class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        if (n == 1)
            return {0};
        vector<int> degree(n, 0);
        vector<vector<int>> mp(n);
        for (auto edge : edges)
        {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        queue<int> que;
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
                que.push(i);
        }
        vector<int> res;
        while (!que.empty())
        {
            res.clear();
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                int node = que.front();
                que.pop();
                res.push_back(node);
                for (auto neibor : mp[node])
                {
                    degree[neibor]--;
                    if (degree[neibor] == 1)
                        que.push(neibor);
                }
            }
        }
        return res;
    }
};