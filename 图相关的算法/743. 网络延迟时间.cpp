/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-13 21:01:33
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-13 22:50:41
 */
//floyd算法实现，实现整个网图各节点之间的最短距离
class Solution
{
public:
    vector<vector<int>> edges;
    void buildMap(vector<int> time)
    {
        int u = time[0] - 1;
        int v = time[1] - 1;
        int w = time[2];
        edges[u][v] = w;
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        edges = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < times.size(); i++)
        {
            buildMap(times[i]);
        }
        for (int i = 0; i < n; i++)
        {
            edges[i][i] = 0;
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (edges[i][k] != INT_MAX && edges[k][j] != INT_MAX)
                        edges[i][j] = min(edges[i][j], edges[i][k] + edges[k][j]);
                }
            }
        }
        int sumOfTime = 0;
        for (int i = 0; i < n; i++)
        {
            if (edges[k - 1][i] == INT_MAX)
                return -1;
            sumOfTime = max(sumOfTime, edges[k - 1][i]);
        }
        return sumOfTime;
    }
};
//dijstra算法，实现单个节点到各个节点的最短距离计算
class Solution
{
public:
    vector<vector<int>> edges;
    void buildMap(vector<int> time)
    {
        int u = time[0] - 1;
        int v = time[1] - 1;
        int w = time[2];
        edges[u][v] = w;
    }
    vector<int> dijstra(vector<vector<int>> &edges, int source, int n)
    {
        //存放source到各节点最短距离的汇总，初始值为INT_MAX，表示都到不了
        vector<int> shortest(n, INT_MAX);
        //存放source到哪些节点的最短距离已求出
        vector<bool> visited(n, false);
        //source到自己定义为0
        shortest[source] = 0;
        //visited[i]表示该节点已经求得最短距离
        visited[source] = true;
        //因为已经找到一个节点（source自身），所以只要进行n-1次就好
        for (int i = 1; i < n; i++)
        {
            int minVal = INT_MAX;
            int index = -1;
            //每次循环遍历n次，目的是寻找那些还没找到最短距离的节点，从source出发离最近的那个节点
            for (int j = 0; j < n; j++)
            {
                if (visited[j] == false && edges[source][j] < minVal)
                {
                    minVal = edges[source][j];
                    index = j;
                }
            }
            //防止在剩下节点中有节点怎么也不能通过已经被选中的这些S集合里的节点到达，所以这个时候直接返回就行
            if (index == -1)
                return shortest;
            //记录这个目前是剩下待选节点中最短的节点，记录它到源节点的距离以及把它归入到已找到最短节点里
            shortest[index] = minVal;
            visited[index] = true;
            //
            for (int m = 0; m < n; m++)
            {
                //防止int溢出，一旦出现INT_MAX，表示这个节点不可达，所以根本不用判断
                if (edges[source][index] == INT_MAX || edges[index][m] == INT_MAX)
                    continue;
                //如果原先源节点到该节点m的距离大于通过刚找到index节点再到m的距离，则更新
                if (visited[m] == false && edges[source][m] > edges[source][index] + edges[index][m])
                    edges[source][m] = edges[source][index] + edges[index][m];
            }
        }
        return shortest;
    }
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        edges = vector<vector<int>>(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < times.size(); i++)
        {
            buildMap(times[i]);
        }
        for (int i = 0; i < n; i++)
        {
            edges[i][i] = 0;
        }
        vector<int> shortest = dijstra(edges, k - 1, n);
        int res = *max_element(shortest.begin(), shortest.end());
        if (res == INT_MAX)
            return -1;
        return res;
    }
};