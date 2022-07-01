class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();
        int t1 = (n + m) / 2;
        int t2 = -1;
        bool isji = true;
        if ((n + m) % 2 == 0)
        {
            isji = false;
            t2 = t1 - 1;
        }
        int index = 0;
        int i = 0, j = 0;
        double ans = 0;

        while (i < n && j < m)
        {
            int val = 0;
            if (nums1[i] < nums2[j])
            {
                val = nums1[i];
                i++;
            }
            else
            {
                val = nums2[j];
                j++;
            }
            if (i + j - 1 == t2)
            {
                ans += val;
            }
            if (i + j - 1 == t1)
            {
                ans += val;
                if (isji)
                {
                    return ans;
                }
                else
                {
                    return ans / 2;
                }
            }
        }
        while (i < n)
        {
            int val = nums1[i];
            i++;
            if (i + j - 1 == t2)
            {
                ans += val;
            }
            if (i + j - 1 == t1)
            {
                ans += val;
                if (isji)
                {
                    return ans;
                }
                else
                {
                    return ans / 2;
                }
            }
        }
        while (j < m)
        {
            int val = nums2[j];
            j++;
            if (i + j - 1 == t2)
            {
                ans += val;
            }
            if (i + j - 1 == t1)
            {
                ans += val;
                if (isji)
                {
                    return ans;
                }
                else
                {
                    return ans / 2;
                }
            }
        }
        return ans;
    }
};