#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <cmath>
#include <set>
using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> m;
        for (auto str : strs)
        {
            string temp = str;
            sort(str.begin(), str.end());
            m[str].push_back(temp);
        }
        vector<vector<string>> res;
        for (auto i : m)
        {
            res.push_back(i.second);
        }
        return res;
    }
};