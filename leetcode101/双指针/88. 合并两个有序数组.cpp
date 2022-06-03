/*
 * @Description:
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2022-06-03 17:54:15
 * @LastEditors: Mario Deng
 * @LastEditTime: 2022-06-03 17:55:09
 */
//双指针从右开始遍历，能避免nums1[]已排完序的数组还保持有效
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int pos = m + n - 1;
        m--;
        n--;
        while (m >= 0 && n >= 0)
        {
            if (nums1[m] <= nums2[n])
            {
                nums1[pos] = nums2[n];
                n--;
            }
            else
            {
                nums1[pos] = nums1[m];
                m--;
            }
            pos--;
        }
        while (n >= 0)
        {
            nums1[pos] = nums2[n];
            pos--;
            n--;
        }
    }
};