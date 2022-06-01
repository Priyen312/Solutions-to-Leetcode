class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix[n], postfix[n];
        int product = 1;
        for(int i = 0; i < nums.size(); i++)
        {
            product *= nums[i];
            prefix[i] = product;                        // [1, 2, 6, 24]
        }
        product = 1;
        for(int i = nums.size() - 1; i >= 0; i--)
        {
            product *= nums[i];
            postfix[i] = product;                       // [24, 24, 12, 4]
        }
        
        vector<int> res;
        for(int i = 0; i < nums.size(); i++)
        {
            if(i == 0 and i + 1 < nums.size())
            {
                res.push_back(postfix[i + 1]);
                
            }
            if(i == n - 1 and i - 1 >= 0)
            {
                res.push_back(prefix[i - 1]);
                
            }
            
            if(i > 0 and i < nums.size() - 1)
            {
                int m = prefix[i - 1] * postfix[i + 1];
                res.push_back(m);
            }  
            
        }
       
        return res;
    }
};