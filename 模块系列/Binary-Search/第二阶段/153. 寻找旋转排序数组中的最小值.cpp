/*
    数组中元素都是唯一的
	例子: 4567123
	只要找到变化点就是答案,因为
	比如这边的1就是变化点
	变化点的左侧都是大于变化点的值且是递增的(只要判断某个值是否小于首元素的值)
	变化点的右侧都是大于变化点且包含变化点都是递增的,那么变化点肯定是最小的,并且变化点右侧的值都是小于首元素的值

	如果算出mid不出现这两种情况则就表示还没找到变化点,即,mid前一个元素大于mid,则mid就是变化点
												mid后一个元素小于mid,则mid+1就是变化点
	如果都不满足则如果nums[0]<nums[mid]则 最小值必定出现在mid右侧
	如果nums[0]>nums[mid] 则,最小值必定出现在mid右侧,因为通过之前的判断,mid是不可能作为变化点了
*/
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int left = 0, right = n - 1, mid;
        if (nums[left] < nums[right])
        {
            return nums[left];
        }
        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if (nums[mid - 1] > nums[mid])
                return nums[mid];
            if (nums[0] < nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }
};

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int left = 0, right = n - 1, mid;
        if (nums[left] < nums[right])
        {
            return nums[left];
        }
        while (left < right)
        {
            mid = left + ((right - left) >> 1);
            //若出现这个情况,则表示包含mid的元素的左边的范围才会出现最小值,也有可能是nums[mid]
            if (nums[mid] < nums[right])
            {
                right = mid;
            }
            else //如果nums[mid] > nums[right]因为元素唯一所以不是大于就是小于
            {
                left = mid + 1; //mid必定不会是最小的元素,所以除了首元素就是最小值那么最小元素必定在mid右侧
            }
            //最终循环会执行到left+1 = right的时候,mid  = left,则不管怎么样经过这最后一次循环,left一定会等于right,并且判断出
            //最小元素是当前mid还是mid + 1
        }
        return -1;
    }
};