class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max_product = 1;
        int min_product = 1;
        int ans = INT_MIN;
        for(int i = 0; i < nums.size(); i++)
        {   
            if(nums[i] >= 0)
            {
                max_product = max(max_product * nums[i], nums[i]);// the case is used so that an earlier multiplication with zero leads us to start with the current number
                min_product = min(min_product * nums[i], nums[i]);
            }
            else{
                int tmp = max_product*nums[i];
                max_product = max(min_product*nums[i],nums[i]);
                min_product = min(tmp, nums[i]);
            }
            
          
            ans = max(max_product,ans);
        }
        
        return ans;
    }
};