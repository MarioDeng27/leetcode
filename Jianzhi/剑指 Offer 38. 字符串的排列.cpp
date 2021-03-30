/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-29 20:22:36
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-29 20:22:37
 */
/*
    回溯法+visited
*/

class Solution
{
public:
    vector<string> res;
    void backTrack(string s, vector<bool> visited, string track)
    {
        if (track.size() == s.size())
        {
            res.push_back(track);
            return;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (visited[i] == false)
            {
                if (i > 0 && s[i - 1] == s[i] && visited[i - 1] == false)
                    continue;
                visited[i] = true;
                track += s[i];
                backTrack(s, visited, track);
                visited[i] = false;
                track.pop_back();
            }
        }
    }
    vector<string> permutation(string s)
    {
        int size = s.size();
        sort(s.begin(), s.end());
        vector<bool> visited(size, false);
        backTrack(s, visited, "");
        return res;
    }
};
/*
    交换+set
*/

class Solution
{
public:
    vector<string> res;
    void dfs(string s, int start)
    {
        int n = s.size();
        if (start == n - 1)
            res.push_back(s);
        set<char> mySet;
        for (int i = start; i < n; i++)
        {
            if (mySet.count(s[i]) > 0)
                continue;
            mySet.insert(s[i]);
            swap(s[start], s[i]);
            dfs(s, start + 1);
            swap(s[start], s[i]);
        }
    }
    vector<string> permutation(string s)
    {
        int size = s.size();
        //sort(s.begin(), s.end());
        dfs(s, 0);
        return res;
    }
};