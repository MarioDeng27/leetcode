/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-04-11 16:42:14
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-04-11 16:42:35
 */
class Solution
{
public:
    string minNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), compair);
        string res;
        for (auto num : nums)
        {
            res += to_string(num);
        }
        return res;
    }
    static bool compair(int num1, int num2)
    {
        string str1 = to_string(num1);
        string str2 = to_string(num2);
        return (str1 + str2) < (str2 + str1);
    }
};