class Solution {
public:
    int get_money(vector<int>& nums, int index, int size, vector<int> &memo)
    {
        if(index >= size)
            return 0;
        
        if(memo[index] != -1)
            return memo[index];
        
        return memo[index] = max(nums[index] + get_money(nums, index + 2, size, memo), get_money(nums, index + 1, size, memo));
    }
    int rob(vector<int>& nums) {
        vector<int> memo1(nums.size(), -1);
        vector<int> memo2(nums.size(), -1);
        int n = nums.size();
        if(nums.size() == 1)
            return nums[0];
        
        int rob1 = get_money(nums, 0, n - 1, memo1);
        int rob2 = get_money(nums, 1, n, memo2);
        
        return max(rob1, rob2);
        
    }
};