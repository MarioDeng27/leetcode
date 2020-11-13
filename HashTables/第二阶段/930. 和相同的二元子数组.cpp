class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        int n = A.size();
        if (S > n)
            return 0;
        int res = 0;
        //set<vector<int>> s;
        for (int i = S; i <= n; i++)
        {
            if (i == 0)
                continue;
            for (int j = 0; j <= n - i; j++)
            {
                int sum = 0;
                for (int k = j; k <= j + i - 1; k++)
                {
                    sum += A[k];
                }
                if (sum == S)
                    res++;
                //s.insert(vector<int>(A.begin()+j,A.begin()+j+i-1));
            }
        }
        return res;
        /* for(auto item : s)
		{
			int sum = 0;
			for()
		} */
    }
};
/*
    方法2:破题目
    前缀和实现,
    用p[i]表示 从p[0]到p[i-1]的和
    如果存在 j<i且 p[i] = p[j] + S,即 p[i] - p [j]
    则表示 A[j] + A[j+1] + ... A[i-1] = S
    只要找到满足j<i且 p[i] = p[j] + S的个数,就是OK了
*/

class Solution
{
public:
    int numSubarraysWithSum(vector<int> &A, int S)
    {
        int n = A.size();
        vector<int> p(A.size() + 1);
        for (int i = 0; i < A.size(); i++)
        {
            p[i + 1] = A[i] + p[i];
        }
        int res = 0;
        map<int, int> m;
        for (int i = 0; i < p.size(); i++)
        {
            if (m.find(p[i]) != m.end())
                res += m[p[i]];
            ++m[p[i] + S];
        }
        return res;
    }
};