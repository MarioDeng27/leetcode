
/*
    BFS实现

*/

class Solution
{
public:
    vector<vector<int>> edges;
    vector<int> indeg;
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        indeg.resize(numCourses);
        for (auto p : prerequisites)
        {
            edges[p[1]].push_back(p[0]);
            ++indeg[p[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indeg[i] == 0)
                q.push(i);
        }
        vector<int> res;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (auto v : edges[u])
            {
                --indeg[v];
                if (indeg[v] == 0)
                    q.push(v);
            }
        }
        if (res.size() == numCourses)
            return res;
        else
            return {};
    }
};

/*
    DFS实现


*/

class Solution
{
public:
    vector<vector<int>> edges;
    vector<int> visited;
    bool valid = true;
    vector<int> res;
    void dfs(int u)
    {
        visited[u] = 1;
        for (auto v : edges[u])
        {
            if (valid)
            {
                if (visited[v] == 0)
                    dfs(v);
                else if (visited[v] == 1)
                {
                    valid = false;
                    return;
                }
            }
        }
        visited[u] = 2;
        res.push_back(u);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        edges.resize(numCourses);
        visited.resize(numCourses);
        for (auto p : prerequisites)
        {
            edges[p[1]].push_back(p[0]);
        }

        for (int i = 0; i < numCourses && valid; i++)
        {
            if (visited[i] == 0)
            {
                dfs(i);
            }
        }

        if (valid)
            return vector<int>(res.rbegin(), res.rend());
        else
            return {};
    }
};

class Solution
{
public:
    vector<int> vistied;
    vector<vector<int>> edges;
    bool valid = true;
    vector<int> res;
    void dfs(int u)
    {
        vistied[u] = 1;
        for (int i = 0; i < edges[u].size(); i++)
        {
            int v = edges[u][i];
            if (vistied[v] == 0)
            {
                dfs(v);
            }
            else if (vistied[v] == 1)
            {
                valid = false;
                return;
            }
            if (!valid)
                return;
        }
        vistied[u] = 2;
        res.push_back(u);
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vistied.resize(numCourses, false);
        edges.resize(numCourses);
        for (auto p : prerequisites)
        {
            edges[p[1]].push_back(p[0]);
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (vistied[i] == 0)
                dfs(i);
        }
        if (!valid)
            return {};
        reverse(res.begin(), res.end());
        return res;
    }
};