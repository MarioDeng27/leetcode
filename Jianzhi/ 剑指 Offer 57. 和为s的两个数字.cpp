class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        set<int>mySet;
        for(auto num:nums)
        {
            if(mySet.count(target-num)!=0)
                     return {target-num,num};
            mySet.insert(num);
        }
        return {};
    }
};


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        for(int i = 0 ; i < nums.size();i++)
        {
            for(int j = nums.size()-1; j > i;j--)
            {
                if(nums[i]+nums[j]==target)
                    return {nums[i],nums[j]};
                else if(nums[i]+nums[j]>target)
                    continue;
                else
                    break;
            }
        }
        return {};
    }
};