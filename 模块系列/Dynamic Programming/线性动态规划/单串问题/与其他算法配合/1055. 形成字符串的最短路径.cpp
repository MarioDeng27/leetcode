/*
 * @FilePath: \Sorte:\DataStructures-Algorithms\DataStructures-Algorithms\leetcode\Dynamic Programming\线性动态规划\单串问题\与其他算法配合\1055. 形成字符串的最短路径.cpp
 * @Brief: 
 * @Version: 1.0
 * @Date: 2021-03-15 21:03:25
 * @Author: Mario Deng
 * @Copyright: your copyright description
 * @LastEditors: Mario Deng
 * @LastEditTime: 2021-03-15 21:04:14
 */

/*
对于任何字符串，我们可以通过删除其中一些字符（也可能不删除）来构造该字符串的子序列。

给定源字符串 source 和目标字符串 target，找出源字符串中能通过串联形成目标字符串的子序列的最小数量。如果无法通过串联源字符串中的子序列来构造目标字符串，则返回 -1。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shortest-way-to-form-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


输入：source = "xyz", target = "xzyxz"
输出：3
解释：目标字符串可以按如下方式构建： "xz" + "y" + "xz"。

*/
//利用双指针
class Solution
{
public:
    int shortestWay(string source, string target)
    {
        int count = 0;
        for (int i = 0; i < target.size();)
        {
            int k = i;
            for (int j = 0; j < source.size(); j++)
            {
                if (target[i] == source[j])
                {
                    i++;
                }
            }
            if (k == i)
                return -1;
            count++;
        }
        return count;
    }
};