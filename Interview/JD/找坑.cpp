/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Interview\JD\找坑.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-28 18:43:35
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-28 18:43:35
 */
//京东找坑题目答案

bool isKeng(vector<vector<int>> &A, int i, int j)
{
    int val = A[i][j];
    return (val < A[i][j - 1]) && (val < A[i][j + 1]) && (val < A[i - 1][j]) && (val < A[i + 1][j]);
}
int getAns(vector<vector<int>> &A)
{
    int R = A.size();
    if (R == 0)
        return 0;
    int C = A[0].size();
    queue<pair<int, int>> q;
    int cnt = 0;
    for (int i = 1; i < R - 1; i++)
    {
        for (int j = 1; j < C - 1; j++)
        {
            if (A[i][j] != INT_MAX && isKeng(A, i, j))
            {
                cnt++;
                q.push({i, j});
                A[i][j] = INT_MAX;
                while (!q.empty())
                {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

                    if (r + 1 < R - 1 && A[r + 1][c] != INT_MAX && isKeng(A, r + 1, c))
                    {
                        q.push({r + 1, c});
                        A[r + 1][c] = INT_MAX;
                    }
                    if (r - 1 > 0 && A[r - 1][c] != INT_MAX && isKeng(A, r - 1, c))
                    {
                        q.push({r - 1, c});
                        A[r - 1][c] = INT_MAX;
                    }
                    if (c + 1 < C - 1 && A[r][c + 1] != INT_MAX && isKeng(A, r, c + 1))
                    {
                        q.push({r, c + 1});
                        A[r][c + 1] = INT_MAX;
                    }
                    if (c - 1 > 0 && A[r][c - 1] != INT_MAX && isKeng(A, r, c - 1))
                    {
                        q.push({r, c - 1});
                        A[r][c - 1] = INT_MAX;
                    }
                }
            }
        }
    }
    return cnt;
}