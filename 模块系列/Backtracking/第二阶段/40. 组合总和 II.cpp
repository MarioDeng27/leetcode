/*
 * @Description: 
 * @Version: 1.0
 * @Autor: Mario Deng
 * @Date: 2020-11-27 16:11:10
 * @LastEditors: Mario Deng
 * @LastEditTime: 2020-11-27 16:47:15
 */

/*
    具体思想和39题类似
    添加了一个hash表,用于记录原数组中,每个元素在数组中出现的次数,然后利用集合set将原数组去重复元素成nums
    当在backtrack那里用过一次nums中某个元素值,那么hash表对应元素的个数减一,如果小于等于0,代表当前元素不可用了,跳过该元素,遍历下一个元素
    当回溯之后又回复到原先的个数
*/
class Solution
{
public:
    vector<vector<int>> res;
    map<int, int> m;
    void backtrack(vector<int> &candidates, int target, vector<int> &track, int sum, int cnt)
    {
        if (sum == target)
        {
            res.push_back(track);
            return;
        }
        for (int i = cnt; i < candidates.size(); i++)
        {
            if (m[candidates[i]] <= 0)
                continue;
            if (sum + candidates[i] <= target)
            {
                sum += candidates[i];
                track.push_back(candidates[i]);
                m[candidates[i]]--;
                backtrack(candidates, target, track, sum, i);
                sum -= candidates[i];
                track.pop_back();
                m[candidates[i]]++;
            }
            else
            {
                break;
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        for (auto i : candidates)
        {
            ++m[i];
        }
        set<int> myset(candidates.begin(), candidates.end());
        vector<int> nums(myset.begin(), myset.end());
        sort(nums.begin(), nums.end());
        vector<int> track;
        backtrack(nums, target, track, 0, 0);
        return res;
    }
};

//具体思想和方法一类似,用一个字典记录每个元素使用的次数,什么时候使用该元素,也就是不从该元素跳过的时候,并且符合使用的条件使用后,次数减一,后来回溯加一
class Solution
{
public:
    vector<vector<int>> res;
    map<int, int> m;
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

        if (m[candidates[cnt]] > 0 && target - candidates[cnt] >= 0)
        {
            track.push_back(candidates[cnt]);
            m[candidates[cnt]]--;
            backtrack(candidates, target - candidates[cnt], track, cnt);
            track.pop_back();
            m[candidates[cnt]]++;
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        for (auto i : candidates)
        {
            ++m[i];
        }
        set<int> myset(candidates.begin(), candidates.end());
        vector<int> nums(myset.begin(), myset.end());
        sort(nums.begin(), nums.end());
        vector<int> track;
        backtrack(nums, target, track, 0);
        return res;
    }
};
/*
    自己的想法,不用hash表去记录个数,也不用去重复元素形成nums
    1. [cnt:作用是跳过之前的元素不使用]用了cnt表示:在for循环里,i=cnt很关键,比如cnt=1,这样就可以跳过第一个元素,而for循环里的backtrack的函数里参数用i表示还是从当前位置往后遍历,除非不满足条件
    去break,表示都不用往后遍历当前这个情况的track数组的组合是不可能的了
    2. 利用了visited[i]表示不使用之前已经使用过的元素,这个功能和cnt类似,但是
    if (i > 0 && visited[i - 1] == false && candidates[i] == candidates[i - 1])
    {
        continue;
    }
    这个作用是去除元素中相同元素的影响,相同的元素把第一次用这个元素的情况算到结果里去,第二次出现则不受影响
    3. 还要判断sum和target的情况
*/

class Solution
{
public:
    vector<vector<int>> res;
    map<int, int> m;
    void backtrack(vector<int> &candidates, int target, vector<int> &track, vector<bool> &visited, int sum, int cnt)
    {
        if (sum == target)
        {
            res.push_back(track);
            return;
        }
        for (int i = cnt; i < candidates.size(); i++)
        {
            if (i > 0 && visited[i - 1] == false && candidates[i] == candidates[i - 1])
            {
                continue;
            }
            if (visited[i] == false)
            {
                if (sum + candidates[i] <= target)
                {
                    sum += candidates[i];
                    track.push_back(candidates[i]);
                    visited[i] = true;
                    backtrack(candidates, target, track, visited, sum, i);
                    sum -= candidates[i];
                    track.pop_back();
                    visited[i] = false;
                }
                else
                {
                    break;
                }
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<bool> visited(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        vector<int> track;
        backtrack(candidates, target, track, visited, 0, 0);
        return res;
    }
};