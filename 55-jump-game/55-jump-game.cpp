class Solution {
public:
    
    bool canJump(vector<int>& nums) {
        
        int safe_jump = nums.size() - 1;
        
        for(int i = nums.size() - 1; i>=0; i--)
        {
            
                if(i + nums[i] >= safe_jump)
                {
                    safe_jump = i;
                }
             
            }
        
        
        
        return safe_jump == 0;
        
        
    }
};