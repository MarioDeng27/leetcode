/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-07-04 16:15:15
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-07-04 16:34:30
 */
//用栈实现DFS
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int m = isConnected.size();
        if (m == 0)
            return 0;
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    res++;
                    isConnected[i][j] = 0;
                    isConnected[j][i] = 0;
                    stack<int> st;
                    st.push(j);
                    while (!st.empty())
                    {
                        int t = st.top();
                        st.pop();
                        for (int k = 0; k < m; k++)
                        {
                            if (isConnected[t][k] == 1)
                            {
                                isConnected[t][k] = 0;
                                isConnected[k][t] = 0;
                                st.push(k);
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};
//用递归实现DFS
class Solution
{
public:
    int m;
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        m = isConnected.size();
        if (m == 0)
            return 0;
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    res++;
                    isConnected[i][j] = 0;
                    isConnected[j][i] = 0;
                    dfs(isConnected, j);
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &isConnected, int t)
    {
        for (int i = 0; i < m; i++)
        {
            if (isConnected[t][i] == 1)
            {
                isConnected[t][i] = 0;
                isConnected[i][t] = 0;
                dfs(isConnected, i);
            }
        }
    }
};

//用递归实现DFS，并添加标记
class Solution
{
public:
    int m;
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        m = isConnected.size();
        if (m == 0)
            return 0;
        int res = 0;
        vector<bool> visited(m, false);
        for (int i = 0; i < m; i++)
        {
            if (!visited[i])
            {
                res++;
                dfs(isConnected, i, visited);
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &isConnected, int t, vector<bool> &visited)
    {
        visited[t] = true;
        for (int i = 0; i < m; i++)
        {
            if (isConnected[t][i] == 1 && !visited[i])
                dfs(isConnected, i, visited);
        }
    }
};
//用栈实现DFS，以及添加标记
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int m = isConnected.size();
        if (m == 0)
            return 0;
        int res = 0;
        vector<bool> visited(m, false);
        for (int i = 0; i < m; i++)
        {
            if (!visited[i])
            {
                res++;
                visited[i] = true;
                stack<int> st;
                st.push(i);
                while (!st.empty())
                {
                    int t = st.top();
                    st.pop();
                    visited[t] = true;
                    for (int k = 0; k < m; k++)
                    {
                        if (isConnected[t][k] == 1 && !visited[k])
                        {
                            st.push(k);
                        }
                    }
                }
            }
        }
        return res;
    }
};