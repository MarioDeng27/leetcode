/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-02-28 20:50:43
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-02-28 21:19:44
 */

/*
    方法1，先排序
*/
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                return nums[i];
        }
        return nums[0];
    }
};
/*
    方法二：利用哈希表来判断是否出现两次的元素

*/
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        set<int> s;
        for (int i = 0; i < nums.size(); i++)
        {
            if (s.find(nums[i]) != s.end())
                return nums[i];
            else
            {
                s.insert(nums[i]);
            }
        }
        return 0;
    }
};

class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i)
            {
                if (nums[i] == nums[nums[i]])
                {
                    return nums[i];
                }
                else
                {
                    int temp = nums[i];
                    nums[i] = nums[nums[i]];
                    nums[temp] = temp;
                }
            }
        }
        return 0;
    }
};