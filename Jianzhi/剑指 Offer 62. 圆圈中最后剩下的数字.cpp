/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-11 14:37:30
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-11 14:44:16
 */
//有动态规划的味道，后一个状态的值与前一个状态的值有联系
//递归方式
class Solution
{
public:
    //findAnswer(n,m) 表示长度大小为n，从第0个元素开始，每次向后删除第m个元素，最后留下的唯一元素是第几个元素，每次删除对应元素后，从它后一个元素开始
    //当长度为1时，满足条件只剩唯一元素，那么在当前情况它的位置必定在第0个。
    int findAnswer(int n, int m)
    {
        if (n == 1)
            return 0;
        //算出当n-1长度时，要删除的元素在当前序列的第x个
        int x = findAnswer(n - 1, m);
        //相当于答案在n长度时，是从m%n开始的第x个元素，（因为是从0开始的，所以删除的是(m-1)%x），为了避免溢出采用%n
        return (m + x) % n;
    }
    int lastRemaining(int n, int m)
    {
        return findAnswer(n, m);
    }
};
//非递归方式
class Solution
{
public:
    //f(n,m) =
    //n = 1时，0
    //n > 1时， (f(n-1,m) + m)%n
    int lastRemaining(int n, int m)
    {
        int x = 0;
        for (int i = 2; i <= n; i++)
        {
            x = (m + x) % i;
        }
        return x;
    }
};
//超出要求的时间复杂度，按照正常的逻辑的话
class Solution
{
public:
    int lastRemaining(int n, int m)
    {
        list<int> circle;
        for (int i = 0; i < n; i++)
            circle.push_back(i);
        list<int>::iterator curr = circle.begin();
        while (circle.size() > 1)
        {
            //int step = m % circle.size();
            for (int i = 1; i < m; i++)
            {
                curr++;
                if (curr == circle.end())
                    curr = circle.begin();
            }
            list<int>::iterator next = ++curr;
            if (next == circle.end())
                next = circle.begin();
            curr--;
            circle.erase(curr);
            curr = next;
        }
        return *(curr);
    }
};