/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-08-07 16:32:45
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-08-07 16:51:24
 */
class Solution
{
public:
    string turnOn(string str, int pos)
    {
        if (str[pos] == '9')
            str[pos] = '0';
        else
            str[pos]++;
        return str;
    }
    string turnDown(string str, int pos)
    {
        if (str[pos] == '0')
            str[pos] = '9';
        else
            str[pos]--;
        return str;
    }
    int openLock(vector<string> &deadends, string target)
    {
        queue<string> que;
        que.push("0000");
        set<string> visits;
        visits.insert("0000");
        for (auto str : deadends)
        {
            if (str == "0000")
                return -1;
            visits.insert(str);
        }

        int step = 0;
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                string cur = que.front();
                que.pop();
                if (cur == target)
                    return step;
                for (int j = 0; j < 4; j++)
                {
                    string on = turnOn(cur, j);
                    if (visits.count(on) == 0)
                    {
                        visits.insert(on);
                        que.push(on);
                    }
                    string down = turnDown(cur, j);
                    if (visits.count(down) == 0)
                    {
                        visits.insert(down);
                        que.push(down);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
//双向搜索BFS
class Solution
{
public:
    string turnOn(string str, int pos)
    {
        if (str[pos] == '9')
            str[pos] = '0';
        else
            str[pos]++;
        return str;
    }
    string turnDown(string str, int pos)
    {
        if (str[pos] == '0')
            str[pos] = '9';
        else
            str[pos]--;
        return str;
    }
    int openLock(vector<string> &deadends, string target)
    {
        set<string> q1, q2;
        q1.insert("0000");
        q2.insert(target);
        set<string> visits;
        visits.insert("0000");
        for (auto str : deadends)
        {
            if (str == "0000")
                return -1;
            visits.insert(str);
        }

        int step = 0;
        //只要q1和q2有一个空了，就表示搜寻结束，并且没找到答案
        while (!q1.empty() && !q2.empty())
        {
            //一切遍历都是以q1的内容开始一个个遍历，但是q1会在本次遍历结束后替换成q2的内容，q2保存着的是q1遍历的结果也就是q1各个元素的邻居
            set<string> temp;
            for (auto cur : q1)
            {
                if (q2.count(cur) == 1)
                    return step;
                //注意这个visits要加在从Que弹出的时候，这样才算访问好，如果加入在位置1处，见下面。则会导致双向搜索失效。因为双向搜索在遍历的过程中必定遍历同一个点两次，如果直接用visits会让第二次遍历失效。只有将他们保存在各自的q里，在出队列的初次，visit才有用，只可意会~，
                //反正BFS真正访问的时间将其设置会弹出q的时候就好
                visits.insert(cur);
                for (int j = 0; j < 4; j++)
                {
                    string on = turnOn(cur, j);
                    if (visits.count(on) == 0)
                    {
                        //位置1： visits.insert(on);
                        temp.insert(on);
                    }
                    string down = turnDown(cur, j);
                    if (visits.count(down) == 0)
                    {
                        temp.insert(down);
                    }
                }
            }
            step++;
            q1 = q2;
            q2 = temp;
        }
        return -1;
    }
};