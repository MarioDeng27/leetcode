/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-03 17:34:47
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-03 17:35:07
 */
class Solution
{
public:
    vector<vector<int>> res;
    int target;
    //找到1到n-1的路径
    void traverse(vector<vector<int>> &graph, int num, vector<int> path)
    {
        path.push_back(num);
        if (num == target)
        {
            res.push_back(path);
            return;
        }

        for (auto next : graph[num])
        {
            traverse(graph, next, path);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        target = graph.size() - 1;
        traverse(graph, 0, {});
        return res;
    }
};