/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2021-03-01 16:39:35
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-22 17:48:51
 */
class Solution
{
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int Partition2(vector<int> &nums, int start, int end)
    {
        int pivot = nums[start];
        int l = start;
        int r = end;
        while (l < r)
        {
            while (pivot <= nums[r] && l < r)
                r--;
            if (l < r)
            {
                nums[l] = nums[r];
                l++;
            }
            while (pivot > nums[l] && l < r)
                l++;
            if (l < r)
            {
                nums[r] = nums[l];
                r--;
            }
        }
        nums[l] = pivot;
        return l;
    }

    int Partition(vector<int> &nums, int start, int end)
    {
        int index = (end - start) / 2 + start;
        swap(nums[end], nums[index]);
        int small = start - 1;
        for (index = start; index < end; index++)
        {
            if (nums[index] < nums[end])
            {
                small++;
                if (small != index)
                    swap(nums[small], nums[index]);
            }
        }
        small++;
        swap(nums[small], nums[end]);
        return small;
    }
    void QuickSort(vector<int> &nums, int start, int end)
    {
        if (start == end)
        {
            return;
        }
        int index = Partition2(nums, start, end);
        if (index > start)
            QuickSort(nums, start, index - 1);
        if (index < end)
            QuickSort(nums, index + 1, end);
    }
};

//非递归，用栈来模拟
void quickSort2(vector<int> &nums, int l, int r)
{
    stack<int> st;
    st.push(l);
    st.push(r);

    while (!st.empty())
    {
        int right = st.top();
        st.pop();
        int left = st.top();
        st.pop();
        int m = partition(nums, left, right);
        if (m + 1 < right)
        {
            st.push(m + 1);
            st.push(right);
        }
        if (m - 1 > left)
        {
            st.push(left);
            st.push(m - 1);
        }
    }
}
//这个记住，因为它直接处理了边界的情况
int partition1(vector<int> &nums, int lo, int hi)
{
    if (lo == hi)
        return lo;
    int pivot = nums[lo];
    int i = lo;
    int j = hi;

    while (i < j)
    {
        while (i < j && nums[j] >= pivot)
            j--;
        if (i < j)
        {
            nums[i] = nums[j];
            i++;
        }
        while (i < j && nums[i] <= pivot)
            i++;
        if (i < j)
        {
            nums[j] = nums[i];
            j--;
        }
    }
    nums[i] = pivot;
    return i;
}