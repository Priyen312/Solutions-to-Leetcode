class Solution {
public:
    
    int get_money(vector<int>& nums, int index, vector<int> &memo)
    {
        if(index >= nums.size())
            return 0;
        if(memo[index] != -1)
            return memo[index];
        
        int take = nums[index];
        take += get_money(nums, index + 2, memo);
        
        int dont_take = 0;
        dont_take += get_money(nums, index + 1, memo);
        
        
        return memo[index] = max(take, dont_take);
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return get_money(nums, 0, memo);
        
    }
};