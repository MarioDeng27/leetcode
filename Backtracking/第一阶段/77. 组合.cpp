#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
using namespace std;
//自己的想法

class Solution
{
public:
    vector<vector<int>> res;
    int n;
    int k;
    void backtrack(int cnt, int start, vector<int> track)
    {
        if (cnt == k)
        {
            res.push_back(track);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            track.push_back(i);
            cnt++;
            backtrack(cnt, i + 1, track);
            track.pop_back();
            cnt--;
        }
    }
    vector<vector<int>> combine(int n, int k)
    {
        this->n = n;
        this->k = k;
        backtrack(0, 1, {});
        return res;
    }
};