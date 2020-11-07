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
using namespace std;
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] == nums[i + 1])
                return nums[i];
        }
        return 0;
    }
};

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        multiset<int> s(nums.begin(), nums.end());
        for (auto i : nums)
        {
            if (s.count(i) > 1)
                return i;
        }
        return 0;
    }
};

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        set<int> s;
        for (auto i : nums)
        {
            if (s.find(i) == s.end())
                s.insert(i);
            else
                return i;
        }
        return 0;
    }
};
//双指针slow和fast，快慢指针，Floyd 判圈算法（又称龟兔赛跑算法）
/*
    写在印象笔记上:
    https://app.yinxiang.com/Home.action?login=true#n=1c564e6b-8d7b-40d9-815b-7a939771f821&s=s67&b=a36205f8-ab97-4fe1-9f83-62e9fde631fc&ses=4&sh=1&sds=2&

*/
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {

        int fast = 0, slow = 0;
        while (true)
        {
            fast = nums[nums[fast]];
            slow = nums[slow];
            if (fast == slow)
                break;
        }
        int finder = 0;
        while (true)
        {
            finder = nums[finder];
            slow = nums[slow];
            if (slow == finder)
                break;
        }
        return slow;
    }
};