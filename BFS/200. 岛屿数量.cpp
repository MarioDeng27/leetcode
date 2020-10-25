#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
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