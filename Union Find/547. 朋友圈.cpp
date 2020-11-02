
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



class UnionFind
{
private:
    //表示岛屿的数量
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

/*
    方法二：简化版的并查集，用总人数去初始化并查集

*/
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