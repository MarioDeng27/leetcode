/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-27 13:38:19
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-27 13:49:49
 */
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    vector<int> tmp(right - left + 1);
    int index = 0;
    while (i <= mid && j <= right)
    {
        tmp[index++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
    }
    while (i <= mid)
        tmp[index++] = nums[i++];
    while (j <= right)
        tmp[index++] = nums[j++];
    for (int i = 0; i < tmp.size(); i++)
    {
        nums[i + left] = tmp[i];
    }
}
void mergeSort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }
}
int main()
{

    vector<int> nums = {4, 3, 6, 1, 7, 8, 23, 2};
    mergeSort(nums, 0, nums.size() - 1);
    for (auto num : nums)
        cout << num << " ";
    return 0;
}