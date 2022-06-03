class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        vector<int> dp(nums.size(), 1);
        vector<int> count(nums.size(), 1);
        
        int lis = 1, nlis = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    if(dp[j] + 1 > dp[i]) // strinctly increasing
                    {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }   
                    else if(dp[j] + 1 == dp[i]) // found the same increasing sequence again
                    {
                        count[i] += count[j];
                    }
                }
                
            }
            
            lis = max(lis, dp[i]);
        }
        
        
        
        for(int i = 0; i < dp.size(); i++)
        {
            if(dp[i] == lis)
                nlis += count[i];
        }
        return nlis;
    }
};