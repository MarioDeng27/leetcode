class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1, mid;

        while (left < right)
        {
            mid = left + ((right - left) >> 1);
            if (arr[mid] < arr[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

class Solution
{
public:
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1, mid;

        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            if (mid > 0 && mid + 1 < n && arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;
            if (mid + 1 < n && arr[mid] < arr[mid + 1])
                left = mid + 1;
            else if (mid + 1 < n)
                right = mid - 1;
        }
        return -1;
    }
};