/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Backtracking\第二阶段\60. 排列序列.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2020-11-26 19:02:51
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-11-26 19:06:47
 */
/*
    
*/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> fac;
        vector<bool> visited(n + 1, false);
        fac.push_back(1);
        //生成对应的阶乘fac[3]就是3! = 6
        for (int i = 1; i <= n; i++)
        {
            fac.push_back(fac.back() * i);
        }
        int div;
        int mod;
        //k--,让k减1表示 如果一开始这个k和n！相等的时候则，div = 0.反正应该就是为了去迎合下标是从0开始的那么个意思
        k--;
        string res;
        for (int j = n; j >= 1; j--)
        {
            div = k / fac[j - 1];
            mod = k % fac[j - 1];
            k = mod;
            //这个while循环是，找到除了已经在res里面的那几个数子除外，从剩下的数字里从最小的开始一直找到第div+1个数子
            int r = div + 1;
            int i = 0;
            //i表示循环结束找到了对应的那个数字
            while (r > 0)
            {
                i++;
                if (visited[i] == false)
                    r--;
            }
            res += to_string(i);
            visited[i] = true;
        }
        return res;
    }
};

/*
    官方给的答案，迪康托展开，关键在于k--那一步
*/

class Solution
{
public:
    // 逆康托展开
    string getPermutation(int n, int k)
    {
        static constexpr int FAC[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; // 阶乘

        vector<int> rest; // 存放当前可选数，有序
        for (int i = 1; i <= n; i++)
            rest.push_back(i);

        k--; //要先 -1 才是其康托展开的值
        string ans = "";
        ans.reserve(n);

        for (int i = n; i >= 1; i--)
        {
            int r = k % FAC[i - 1];
            int t = k / FAC[i - 1];
            k = r;
            ans += to_string(rest[t]);    // 剩余数里第t+1个数为当前位
            rest.erase(rest.begin() + t); // 移除选做当前位的数
        }

        return ans;
    }
};
