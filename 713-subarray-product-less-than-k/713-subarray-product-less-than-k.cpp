class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(k <= 1)
            return 0;
        
        int ans = 0;
        int l = 0;
        
        
        int product = 1;
        
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            product *= nums[i];
            
            while(product >= k)
            {
                product /= nums[l++];//close the window
            }
            
            ans += i - l + 1;
            
        }
        
        return ans;
    }
};