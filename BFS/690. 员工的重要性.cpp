#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
//#include <multimap>
#include <array>
#include <cctype>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;

// Definition for Employee.
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
};

/*
    BFS，利用队列，将每个符合要求的id都放到队列里去，
    然后一层一层的将id对应的员工信息读取出来
*/

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        queue<int> q;
        int res = 0;
        for (auto e : employees)
        {
            if (e->id == id)
            {
                res += e->importance;
                for (auto s : e->subordinates)
                    q.push(s);
                break;
            }
        }

        int p = 0;

        while (!q.empty())
        {
            p = q.front();
            q.pop();

            for (auto e : employees)
            {
                if (e->id == p)
                {
                    res += e->importance;
                    for (auto s : e->subordinates)
                        q.push(s);
                    break;
                }
            }
        }
        return res;
    }
};

/*
    BFS自己的想法：
    利用队列，将每个符合要求的员工信息即emp的结构体都放到队列里去，
    然后一层一层的读取重要度
    可以优化，因为每次subid都需要for循环从头开始找，可以利用一个map将id和emp结构体信息对应
    这样搜寻比较快
*/

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        queue<Employee *> q;
        int res = 0;
        for (auto e : employees)
        {
            if (e->id == id)
            {
                q.push(e);

                break;
            }
        }

        Employee *p = NULL;

        while (!q.empty())
        {
            p = q.front();
            q.pop();
            res += p->importance;
            for (auto s : p->subordinates)
            {
                for (auto e : employees)
                {
                    if (e->id == s)
                    {
                        q.push(e);
                    }
                }
            }
        }
        return res;
    }
};

/*
    BFS+hash map
    先将所有的emp对象都添加到map m中，第一个int代表e的id，第二个值代表e本身
    这样创建了映射关系，搜寻比较快
    其他的地方和前一种方法类似
*/

class Solution
{
public:
    int getImportance(vector<Employee *> employees, int id)
    {
        queue<Employee *> q;
        int res = 0;
        map<int, Employee *> m;
        for (auto e : employees)
        {
            m[e->id] = e;
        }
        q.push(m[id]);
        Employee *p = NULL;
        while (!q.empty())
        {
            p = q.front();
            q.pop();
            res += p->importance;
            for (auto s : p->subordinates)
            {
                q.push(m[s]);
            }
        }
        return res;
    }
};