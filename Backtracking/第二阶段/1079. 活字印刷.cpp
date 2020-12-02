/*
 * @Description: https://leetcode-cn.com/problems/letter-tile-possibilities/
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-12-02 16:03:39
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-12-02 16:07:36
 */
/*
	先找title里的子集,相当于从tiltle所有字符中找长度为1,2...title.size()长度的组合(唯一的,顺序无关)
	重要:然后根据 组合中的元素计算他们一共有的排列方式比如  AAAB,其排列大小为4 = (4!)/3!/1!,长度的阶乘/各个元素出现的次数的阶乘
*/

class Solution
{
public:
	vector<vector<char>> res;
	void backtrack(string str, vector<char> &track, vector<bool> &visited, int cnt)
	{
		//除去0长度的子集
		if (track.size() > 0)
			res.push_back(track);
		for (int i = cnt; i < str.size(); i++)
		{
			//visited去重复
			if (i > 0 && str[i] == str[i - 1] && visited[i - 1] == false)
				continue;
			visited[i] = true;
			track.push_back(str[i]);
			backtrack(str, track, visited, i + 1);
			visited[i] = false;
			track.pop_back();
		}
	}
	int numTilePossibilities(string tiles)
	{
		sort(tiles.begin(), tiles.end());
		vector<bool> visited(tiles.size(), false);
		vector<char> track;
		vector<int> jc;
		jc.push_back(1);
		for (int i = 1; i <= tiles.size(); i++)
		{
			jc.push_back(jc[i - 1] * i);
		}

		backtrack(tiles, track, visited, 0);

		map<char, int> m;
		int ans = 0;
		for (int i = 0; i < res.size(); i++)
		{
			m.clear();
			for (int j = 0; j < res[i].size(); j++)
			{
				++m[res[i][j]];
			}
			int temp = jc[res[i].size()];
			for (auto item : m)
			{
				temp /= jc[item.second];
			}
			ans += temp;
		}
		return ans;
	}
};