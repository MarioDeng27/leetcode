#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <sstream>
#include <climits>

using namespace std;
/*
    方法１：基于堆排序的选择方法
    基本上就是实现一个堆的算法，主要看maxHeapify和buildMaxheap两个函数方法
    每次对数组进行堆实现，就能让数组第一个元素变成这个数组中的最大元素
    然后每次将第一个也就是最大的元素和最后一个元素的交换，相当于去除了最大元素然后让进行堆的最大长度减１
    一共进行k次
    就能找到第k大的元素，就是k次进行堆实现的一个元素，因为这个findKthLargest函数里，循环前已经进行里一次堆实现，所以循环里只要k-1次就行了
*/

class Solution
{
public:
    //让每个节点及其子节点都变成大顶堆
    void maxHeapify(vector<int> &nums, int i, int heapsize)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largestIndex = i;
        if (left < heapsize && nums[left] > nums[largestIndex])
            largestIndex = left;
        if (right < heapsize && nums[right] > nums[largestIndex])
            largestIndex = right;
        if (largestIndex != i)
        {
            swap(nums, largestIndex, i);
            //交换过后,i的值是这三个值中最大的,largestIndex对应的已经被替换了,它有可能会对它作为根节点的局部大顶堆有影响,所以得递归检查,怕破坏之前整理好的大顶堆
            maxHeapify(nums, largestIndex, heapsize);
        }
    }

    void buildMaxHeap(vector<int> &nums, int heapsize)
    {
        //让这个数组变成大顶堆，从倒数第floor(heapsize / 2) - 1开始，自减
        for (int i = floor(heapsize / 2) - 1; i >= 0; --i)
        {
            maxHeapify(nums, i, heapsize);
        }
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        int heapsize = nums.size();
        buildMaxHeap(nums, heapsize);
        for (int i = nums.size() - 1; i >= nums.size() - k + 1; i--)
        {
            swap(nums, 0, i);
            heapsize--;
            maxHeapify(nums, 0, heapsize);
            //buildMaxHeap(nums, heapsize); //这边为什么不用build,因为太低效了,相当于会可能改变原有已经是大顶堆的情况,而从上往下,只需改变部分就行了,一条支路也许是.
        }
        return nums[0];
    }
    void swap(vector<int> &nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};
/* 
利用快速排序ＱuickSort，每次分区都能让一个元素找到正确位置，只要返回的位置是倒数第Ｋ的位置那就成功了，所以每次选这个pivot的索引需要随机性
 */
class Solution
{
public:
    void swap(vector<int> &nums, int a, int b)
    {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }

    int partition(vector<int> &nums, int left, int right)
    {
        int randomindex = rand() % (right - left + 1) + left;
        swap(nums, left, randomindex);
        int pivot = nums[left];
        while (left < right)
        {
            while (left < right && nums[right] >= pivot)
                right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot)
                left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }
    int findKthLargest(vector<int> &nums, int k)
    {
        int size = nums.size();
        int target = size - k;
        int left = 0;
        int right = size - 1;
        while (true)
        {
            int p = partition(nums, left, right);
            if (p == target)
                return nums[p];
            else if (target < p)
                right = p - 1;
            else
                left = p + 1;
        }
        return 0;
    }
};

/*
    利用ＳＴＬ容器中的堆实现，就是优先队列
*/
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        while (pq.size() > k)
        {
            pq.pop();
        }
        return pq.top();
    }
};