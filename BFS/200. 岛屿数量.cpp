#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
/*
    DFS:
    判断是否符合得先调用函数之后才知道，这会浪费调用时间，可以进行优化
    关键在于，访问完一个点之后要把它设置成水，如果这些连续的点都被访问完了，则整块岛屿就访问完了．
*/
class Solution
{
public:
    char I = '1';
    char W = '0';
    void dfs(vector<vector<char>> &grid, int cur_r, int cur_c)
    {
        //判断当前点是否为有效点（是否在范围内）以及是否是水，如果不是，将其边为水，并且按照上下左右的顺序取遍历它的周围
        if (cur_r < 0 || cur_c < 0 || cur_r == grid.size() || cur_c == grid[0].size() || grid[cur_r][cur_c] == W)
            return;
        grid[cur_r][cur_c] = W;
        dfs(grid, cur_r - 1, cur_c); //shang
        dfs(grid, cur_r + 1, cur_c); //xia
        dfs(grid, cur_r, cur_c - 1); //zuo
        dfs(grid, cur_r, cur_c + 1); //you
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int island_cnt = 0;
        int row = grid.size();
        int col = grid[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == I)
                {
                    island_cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return island_cnt;
    }
};
/*
    DFS:
    优化第一个方法，在函数调用前判断其节点是否符合要求
    能被访问的点一定是有效点
*/

class Solution
{
public:
    char I = '1';
    char W = '0';
    int row;
    int col;
    void dfs(vector<vector<char>> &grid, int cur_r, int cur_c)
    {
        grid[cur_r][cur_c] = W;
        if (cur_r - 1 >= 0 && grid[cur_r - 1][cur_c] == I) //shang
            dfs(grid, cur_r - 1, cur_c);
        if (cur_r + 1 < row && grid[cur_r + 1][cur_c] == I) //xia
            dfs(grid, cur_r + 1, cur_c);
        if (cur_c - 1 >= 0 && grid[cur_r][cur_c - 1] == I) //zuo
            dfs(grid, cur_r, cur_c - 1);
        if (cur_c + 1 < col && grid[cur_r][cur_c + 1] == I) //you
            dfs(grid, cur_r, cur_c + 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int island_cnt = 0;
        row = grid.size();
        col = grid[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == I)
                {
                    island_cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return island_cnt;
    }
};

/*
    BFS:
    关键在于，访问完一个点之后要把它设置成水，如果这些连续的点都被访问完了，则整块岛屿就访问完了．
    创建了一个队列用于存放符合条件的点，即是陆地１，　第一个int指ｒ纵坐标，第二个int指ｃ横坐标
    也并不是真正的ＢＦＳ，其实就是仿照了ＢＦＳ的模板进行来该的，访问节点的顺序，可以先把左右两边加入到队列里，也可以将上下两边先加入到队列里
    注意，再添加到队列里后，将节点转化为水０
*/
class Solution
{
public:
    char I = '1';
    char W = '0';
    int row;
    int col;
    int numIslands(vector<vector<char>> &grid)
    {

        int island_cnt = 0;
        row = grid.size();
        col = grid[0].size();

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == I)
                {
                    island_cnt++;
                    grid[i][j] = W;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    pair<int, int> p = {};
                    while (!q.empty())
                    {
                        p = q.front();
                        q.pop();
                        int cur_r = p.first;
                        int cur_c = p.second;
                        grid[cur_r][cur_c] = W;
                        if (cur_r - 1 >= 0 && grid[cur_r - 1][cur_c] == I)
                        {
                            q.push({cur_r - 1, cur_c});
                            grid[cur_r - 1][cur_c] = W;
                        }
                        if (cur_r + 1 < row && grid[cur_r + 1][cur_c] == I) //xia
                        {
                            q.push({cur_r + 1, cur_c});
                            grid[cur_r + 1][cur_c] = W;
                        }

                        if (cur_c - 1 >= 0 && grid[cur_r][cur_c - 1] == I) //zuo
                        {
                            q.push({cur_r, cur_c - 1});
                            grid[cur_r][cur_c - 1] = W;
                        }

                        if (cur_c + 1 < col && grid[cur_r][cur_c + 1] == I) //you
                        {
                            q.push({cur_r, cur_c + 1});
                            grid[cur_r][cur_c + 1] = W;
                        }
                    }
                }
            }
        }
        return island_cnt;
    }
};

/*
    方法三：UnionFind 并查集实现
    https://www.jianshu.com/p/fc17847b0a31
    并查集是一种树型的数据结构，用于处理一些不相交集合（disjoint sets）的合并及查询问题
*/
class UnionFind
{
private:
    //表示岛屿的数量
    int count;
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(vector<vector<char>> &grid)
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
                if (grid[i][j] == '1')
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
    void solve(vector<vector<char>> &board)
    {
    }
};

int main()
{

    return 0;
}