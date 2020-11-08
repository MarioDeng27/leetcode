#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>
//#include <multimap>
#include <array>
#include <cmath>
using namespace std;

/*
    自己的想法，首先如果出现L上的值满足val且R上的值不满足val则交换两个元素的值
    如果不满足上述条件且L上的值不满足val则向右移动左边的索引号
    如果不满足上述两个条件且R上的值满足val则向左移动右边的索引号
    当中若是R向左移动可能会出现小于0 的情况，为避免数组的索引为负数，则加入一个判断R是否小于0，若小于0则跳出循环。此时整个数组已经判断完成了
*/
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int L = 0;
        int R = nums.size() - 1;
        int temp;
        while (L <= R)
        {
            if (nums[L] == val && nums[R] != val)
            {
                temp = nums[L];
                nums[L] = nums[R];
                nums[R] = temp;
            }
            else if (nums[L] != val)
            {
                L++;
            }
            else if (nums[R] == val)
            {
                R--;
            }
            if (R < 0)
                break;
        }
        return L;
    }
};

/*
    不用考虑nums有数据丢失的情况，若做指针指向的元素值符合val直接将左指针指向的元素覆盖为右指针的元素
    并且右指针向左移动一位，因为符合val的我们要剔除，所以本题数组中绝不出现val的元素也是OK的，而还未移动前的右指针指向的元素已被保存到
    左指针的位置，在进行判断。只要符合val就剔除，换成右指针。
    弊端：若题目需要不改变nums数组中的值，只是更改顺序，这道题就不能这么解。用方法一比较好
*/
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int n = nums.size();
        while (i < n)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            }
            else
            {
                i++;
            }
        }
        return n;
    }
};