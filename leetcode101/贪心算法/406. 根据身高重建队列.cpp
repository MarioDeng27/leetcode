/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-02 17:32:45
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-02 17:35:35
 */
//自己想：通过对k从小到大优先排序，然后再根据身高，主要就是看前面到底有多少个高于本身的人，通过k--
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(),
             [](auto &a, auto &b)
             {
                 if (a[1] != b[1])
                     return a[1] < b[1];
                 else
                     return a[0] < b[0];
             });
        for (int i = 0; i < people.size(); i++)
        {
            int h = people[i][0];
            int k = people[i][1];
            for (int j = 0; j < i; j++)
            {
                if (k == 0 && people[j][0] > h)
                {
                    for (int n = i; n > j; n--)
                    {
                        swap(people[n][0], people[n - 1][0]);
                        swap(people[n][1], people[n - 1][1]);
                    }
                    break;
                }
                if (people[j][0] >= h)
                {
                    k--;
                }
            }
        }
        return people;
    }
};
//身高从小到大排序，位置数从大到小（避免身高相同对算法产生影响）
//第i个人，只要找到第k+1个空位就行，因为在i前面都是比他矮，对他没影响
class Solution
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
    {
        sort(people.begin(), people.end(), [](const vector<int> &u, const vector<int> &v)
             { return u[0] < v[0] || (u[0] == v[0] && u[1] > v[1]); });
        int n = people.size();
        vector<vector<int>> ans(n);
        for (const vector<int> &person : people)
        {
            int spaces = person[1] + 1;
            for (int i = 0; i < n; ++i)
            {
                if (ans[i].empty())
                {
                    --spaces;
                    if (!spaces)
                    {
                        ans[i] = person;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
