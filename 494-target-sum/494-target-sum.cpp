class Solution {
public:
    
    int find_ways_to_target(vector<int>& nums, int target, int i , int sum, map<pair<int,int>, int> &memo)
    {
        if(sum == target and i == nums.size())
           return 1;
        if(sum != target and i >= nums.size())
            return 0;
        if(memo.find({i,sum}) != memo.end())
            return memo[{i, sum}];
        
        return memo[{i,sum}] = 
            find_ways_to_target(nums, target, i + 1, sum + nums[i], memo) + find_ways_to_target(nums, target, i + 1, sum - nums[i], memo);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        
        for(auto i: nums)
        {
            total += i;
        }
        map<pair<int,int>, int> memo;

        return find_ways_to_target(nums, target, 0, 0, memo);
        
    }
};