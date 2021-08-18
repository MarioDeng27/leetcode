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
    方法１: 二分查找
    １．先把一个矩形的短边shorter找出来,这是要循环的次数
    ２．每次循环先进行行方向的二分查找，再进行列方向的二分查找．开始以start作为左界，分别以行方向的最长边　列方向的最长边作为右界
*/
class Solution
{
public:
    bool binarysearch(vector<vector<int>> &matrix, int start, int target, bool vertical)
    {
        int low = start;
        int high = vertical ? matrix.size() - 1 : matrix[0].size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (vertical)
            {
                if (matrix[mid][start] == target)
                    return true;
                else if (matrix[mid][start] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
            {
                if (matrix[start][mid] == target)
                    return true;
                else if (matrix[start][mid] < target)
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        int shorter = min(matrix.size(), matrix[0].size());

        for (int i = 0; i < shorter; i++)
        {
            bool verticalFound = binarysearch(matrix, i, target, true);
            bool horizontalFound = binarysearch(matrix, i, target, false);
            if (verticalFound || horizontalFound)
                return true;
        }

        return false;
    }
};
/*
    方法２：　分而治之
    可以把一个矩阵分为四个小矩阵怎么分呢，就从中间列开始，从上往下遍历，一旦出现元素a大于target或者等于target(直接返回true)，
    就可以判断包含a的右下角矩阵肯定大于target排除掉，a上面的元素为b则，包含b的左上角矩阵肯定小于target可以排除掉．

    答案只可能从左下角矩阵和右上角矩阵查找


*/
class Solution
{
public:
    bool searchrec(vector<vector<int>> &matrix, int target, int x1, int y1, int x2, int y2)
    {
        if (x1 > x2 || y1 > y2)
            return false;
        if (target < matrix[y1][x1] || target > matrix[y2][x2])
            return false;

        int midx = (x1 + x2) / 2;
        //用y来记录出现首个元素不满足小于等于target的纵坐标，如果相等，则就返回true，如果大于，则记录y开始搜寻左下和右上，缩小了范围．
        int y = y1;
        while (y <= y2 && matrix[y][midx] <= target)
        {
            if (matrix[y][midx] == target)
                return true;
            y++;
        }
        return searchrec(matrix, target, x1, y, midx - 1, y2) || searchrec(matrix, target, midx + 1, y1, x2, y - 1);
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        if (matrix[0].size() == 0)
            return false;
        return searchrec(matrix, target, 0, 0, matrix[0].size() - 1, matrix.size() - 1);
    }
};

//分而治之新的注释:
class Solution
{
public:
    //为了缩小范围,从大的矩阵缩小到两个小矩阵,左下角一个,右上角一个.如何表示要搜索的矩阵,通过两个点(左上角的点和右下角的点)
    bool searchrec(vector<vector<int>> &matrix, int target, int x1, int y1, int x2, int y2)
    {
        if (x1 > x2 || y1 > y2)
            return false;
        if (target < matrix[y1][x1] || target > matrix[y2][x2])
            return false;
        int mid_x = x1 + (x2 - x1) / 2;
        int y = y1;
        while (y <= y2 && matrix[y][mid_x] <= target)
        {
            if (matrix[y][mid_x] == target)
                return true;
            y++;
        }
        //循环出来的y肯定是不满足循环条件的y,其实找到了P点(mid_x,y-1)这个点就是在mid_x这列情况下,满足小于target的最大值了,它的行号为y-1,当然也有可能整以列都小于target
        //可以肯定的是,P点右下方,包含P点所处列的P下面的部分都是大于target的
        //P的左上方都是小于target的,除去这些范围,对剩下的范围进行搜索
        return searchrec(matrix, target, x1, y, mid_x - 1, y2) || searchrec(matrix, target, mid_x + 1, y1, x2, y - 1);
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.size() == 0)
            return false;
        return searchrec(matrix, target, 0, 0, matrix[0].size() - 1, matrix.size() - 1);
    }
};