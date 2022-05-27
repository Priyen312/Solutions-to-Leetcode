class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0;
        int start = 0;
        int end = 0;
        int z = 0;
        int size = 0;
        while(r < nums.size())
        {
            if(z <= k)
            {
                if(nums[r] == 0)
                    z++;
                
                r++;
            }
            
            if(z > k)
            {
                if(nums[l] == 0)
                {
                    z--;
                }
                
                l++;
            }
            
            if(size < r - l and z <= k)
            {
                size = r - l;
                start = l;
                end = r;
            }
        }
        
        return abs(start - end);
    }
};