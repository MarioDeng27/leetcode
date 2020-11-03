/*
    方法一：还是根据200提，将grid初始化并查集
*/

class UnionFind
{
private:
    //表示岛屿的数量
    int count;
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(vector<vector<int>> &grid)
    {
        //将grid网格里面每个元素都映射到了parent里面，如果是陆地则让parent[x] =x,表示第x的元素是陆地并且其根节点是自己
        //把二维平铺成一维
        count = 0;
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    //第i行第j列，平铺对应的下标为c * i + j，c是列宽
                    parent.push_back(c * i + j);
                    //不考虑周围陆地的情况，每发现1多记一次
                    count++;
                }
                else
                    parent.push_back(-1);
                rank.push_back(0);
            }
        }
    }
    //将同一颗树上的所有节点的父节点都设置为根节点，并且返回根节点
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    //合并x和y所在的树，谁归属的树的深度低，就让它挂在深度高的根节点下
    void unite(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            //始终让rootx为较大值(其作为根节点的深度比较大，也就是x和y所在树的深度为较大值的那颗树的根节点),也就是
            if (rank[rootx] < rank[rooty])
                swap(rootx, rooty);
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty])
                rank[rootx]++;
            //一旦发现符合条件的集合合并了，count就要少1
            count--;
        }
    }
    int getcnt()
    {
        return count;
    }
};

class Solution
{
public:
    int r;
    int c;

    void dfs(vector<vector<int>> &grid, int cur_r, int cur_c, UnionFind &u)
    {
        //先进行垂直方向的搜索，一旦发现符合条件的，令其为0.并且递归查找符合条件的朋友
        for (int i = 0; i < r && (grid[i][cur_c] == 1); i++)
        {
            grid[i][cur_c] = 0;
            u.unite(cur_r * c + cur_c, i * c + cur_c);
            dfs(grid, i, cur_c, u);
        }
        //垂直搜完再搜水平方向的，直到搜完位置
        for (int j = 0; j < c && (grid[cur_r][j] == 1); j++)
        {
            grid[cur_r][j] = 0;
            u.unite(cur_r * c + cur_c, cur_r * c + j);
            dfs(grid, cur_r, j, u);
        }
    }
    int findCircleNum(vector<vector<int>> &grid)
    {
        r = grid.size();
        if (r == 0)
            return 0;
        c = grid[0].size();
        UnionFind uf(grid);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 0;
                    dfs(grid, i, j, uf);
                }
            }
        }
        return uf.getcnt();
    }
};

/*
    方法二：简化版的并查集，用总人数去初始化并查集
*/
class UnionFind
{
private:
    int count;
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int num_friend)
    {
        //num_friend 就是最大的子集数，每个人是一个单独的朋友圈
        count = num_friend;
        rank = vector<int>(count, 0);
        for (int i = 0; i < count; i++)
        {
            parent.push_back(i);
        }
    }
    //将同一颗树上的所有节点的父节点都设置为根节点，并且返回根节点
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    //合并x和y所在的树，谁归属的树的深度低，就让它挂在深度高的根节点下
    void unite(int x, int y)
    {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty)
        {
            //始终让rootx为较大值(其作为根节点的深度比较大，也就是x和y所在树的深度为较大值的那颗树的根节点),也就是
            if (rank[rootx] < rank[rooty])
                swap(rootx, rooty);
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty])
                rank[rootx]++;
            //一旦发现符合条件的集合合并了，count就要少1
            count--;
        }
    }
    int getcnt()
    {
        return count;
    }
};

class Solution
{
public:
    int r;
    int c;

    int findCircleNum(vector<vector<int>> &M)
    {
        r = M.size();
        if (r == 0)
            return 0;
        c = M[0].size();
        UnionFind uf(r);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                //这边不加i!=j也是可以，但是会多调用一次函数调用，浪费时间，因为同一节点与自己当然不用再合并
                if (M[i][j] == 1 && i != j)
                {
                    uf.unite(i, j);
                }
            }
        }
        return uf.getcnt();
    }
};

//方法三：DFS(官方答案)
class Solution
{
public:
    void dfs(vector<vector<int>> &M, int i, vector<bool> &visited)
    {
        for (int j = 0; j < M.size(); j++)
        {
            if (M[i][j] == 1 && visited[j] == false)
            {
                visited[j] = true;
                dfs(M, j, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &M)
    {
        int count = 0;
        int n = M.size();
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                dfs(M, i, visited);
                count++;
            }
        }
        return count;
    }
};

/*
    方法四:自认为方法三dfs的简化版本
    就是改变了visited = true的顺序，以及省区了i=j的情况

    因为是矩阵，行和列一样，假定以垂直方向的行作为N名不同的学生
    然后第i行的i同学，如果和j是同学，那么M[i][j] =1
    每一行的列表示其他的同学，如果为1，则二者为朋友，除了和自己本身的情况，就是i=j
*/
class Solution
{
public:
    void dfs(vector<vector<int>> &M, int i, vector<bool> &visited)
    {
        //直到当前i同学所在的朋友圈所有的学生都被搜寻过后并且没有朋友关系的同学出现才结束。
        for (int j = 0; j < M.size(); j++)
        {
            //M[i][j] == 1：i和j是朋友；visited[j] == false：j同学的朋友圈子还没搜索过；i != j：忽略i同学和自己本身是朋友的情况
            if (M[i][j] == 1 && visited[j] == false && i != j)
            {
                //同理如果j是i的朋友，那么将继续搜寻j的朋友圈
                visited[j] = true;
                dfs(M, j, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &M)
    {
        int count = 0;
        int n = M.size();
        //表示n个学生是否进行搜索过他们各自的朋友
        vector<bool> visited(n, false);
        //遍历n次，表示搜寻n个学生
        for (int i = 0; i < n; i++)
        {
            //如果这个学生没被搜寻过则他所在的朋友圈必定属于一个朋友圈，接着去搜寻他的朋友
            //在主函数里，有几次dfs那么就有几个朋友圈
            if (visited[i] == false)
            {
                //表示i学生马上要开始搜索了，表示以及搜索完毕
                visited[i] = true;
                dfs(M, i, visited);
                count++;
            }
        }
        return count;
    }
};

/*
    方法五:BFS实现
*/
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &M)
    {
        int n = M.size();
        int count = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == false)
            {
                count++;
                queue<int> q;
                q.push(i);
                int p;
                while (!q.empty())
                {
                    p = q.front();
                    q.pop();
                    visited[p] = true;
                    for (int j = 0; j < n; j++)
                    {
                        if (M[p][j] == 1 && visited[j] == false)
                        {
                            q.push(j);
                        }
                    }
                }
            }
        }
        return count;
    }
};