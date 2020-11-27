/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-11-27 15:28:49
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-11-27 15:48:45
 */

/*
    回溯法:注意实现这个功能的结构,关键在于cnt这个参数

    在for循环里,i=cnt很关键,比如cnt=1,这样就可以跳过第一个元素,而for循环里的backtrack的函数里参数用i表示还是从当前位置往后遍历,除非不满足条件
    去break,表示都不用往后遍历当前这个情况的track数组的组合是不可能的了

*/
class Solution
{
public:
    vector<vector<int>> res;
    void backtrack(vector<int> &candidates, int target, vector<int> &track, int sum, int cnt)
    {
        if (sum == target)
        {
            res.push_back(track);
            return;
        }
        for (int i = cnt; i < candidates.size(); i++)
        {
            if (sum + candidates[i] <= target)
            {
                sum += candidates[i];
                track.push_back(candidates[i]);
                backtrack(candidates, target, track, sum, i);
                sum -= candidates[i];
                track.pop_back();
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> track;
        backtrack(candidates, target, track, 0, 0);
        return res;
    }
};

/**
 * @description: https://leetcode-cn.com/problems/combination-sum/solution/zu-he-zong-he-by-leetcode-solution/
 * @param {*}
 * @return {*}
 * @author: Mario Deng
 */
/*
    官方答案,
    回溯法最关键的还是去找到分叉点,官方的思想是,每次判断的时候,是否选用当前遍历到的第cnt个数字,可以是跳过,也可以是选用,如果选用则进行下一步判断

*/
class Solution
{
public:
    vector<vector<int>> res;
    void backtrack(vector<int> &candidates, int target, vector<int> &track, int cnt)
    {
        if (cnt == candidates.size())
            return;
        if (target == 0)
        {
            res.push_back(track);
            return;
        }

        backtrack(candidates, target, track, cnt + 1);

        if (target - candidates[cnt] >= 0)
        {
            track.push_back(candidates[cnt]);
            backtrack(candidates, target - candidates[cnt], track, cnt);
            track.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> track;
        backtrack(candidates, target, track, 0);
        return res;
    }
};