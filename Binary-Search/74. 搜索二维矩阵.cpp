#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>
using namespace std;
/*
    把m*n平铺成　一维数组，然后再二分法
*/
class Solution
{
public:
    int binarysearch(vector<int> nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else if (nums[mid] > target)
                r = mid - 1;
            else
                return mid;
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        vector<int> vec;
        for (auto i : matrix)
        {
            for (auto j : i)
            {
                vec.push_back(j);
            }
        }
        int flag = binarysearch(vec, target);
        if (flag != -1)
            return true;
        return false;
    }
};

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        int row = matrix.size();
        int col = matrix[0].size();
        int size = row * col;
        int l = 0;
        int r = size - 1;
        int mid;
        int rtemp;
        int ctemp;
        while (l <= r)
        {
            mid = (l + r) / 2;
            rtemp = mid / col;
            ctemp = mid % col;
            if (matrix[rtemp][ctemp] < target)
                l = mid + 1;
            else if (matrix[rtemp][ctemp] > target)
                r = mid - 1;
            else
                return true;
        }
        return false;
    }
};