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

/*
    双指针
    利用i相当于快指针，来判断当前元素是否和val相等，如果不等的话，则当前元素肯定是可以保留的，将其保存到
    j慢指针对应的元素，并且j+1。此后一旦出现要保留（不等于val）的元素就保存到j上。[相当于等于val就跳过，这个位置未来可能要被存保留的值]
    最后呢，相当于[0,j-1]（j因为在循环里加了1）的前面这部分元素的值都是要保留的，就是不符合val的元素。则j就是要的答案。

*/
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int j = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};
/*
    双指针
    从L左指针开始，如果发现L对应的元素的值等于val代表，发现了一个不符合要求的元素，那么我们要删除该元素
    那么我们让第R-1的元素覆盖掉第L个元素，并且让原本的元素的长度减少1，表示删除，并且将原本最后的R-1的元素的值复制到了
    L的位置用作保留。重新再次判断L的位置的元素。依次进行下去，如果L对应的元素值不是val那么就跳过当前元素

*/
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int L = 0;
        int R = nums.size();
        while (L < R)
        {
            if (nums[L] == val)
            {
                nums[L] = nums[R - 1];
                R--;
            }

            else
                L++;
        }
        return L;
    }
};