class Solution
{
public:
	int climbStairs(int n)
	{
		vector<int> vec;
		vec.push_back(0);
		vec.push_back(1);
		vec.push_back(2);
		for (int i = 3; i <= n; i++)
		{
			vec.push_back(vec[i - 1] + vec[i - 2]);
		}
		return vec[n];
	}
};

class Solution
{
public:
	int climbStairs(int n)
	{
		map<int, int> m;
		m[1] = 1;
		m[2] = 2;

		for (int i = 3; i <= n; i++)
		{
			m[i] = m[i - 1] + m[i - 2];
		}
		return m[n];
	}
};