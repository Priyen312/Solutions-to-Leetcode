class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        int l = 0, r = n - 1;
        
        if(nums[r] > nums[0])
            return nums[0];
        
        while(r >= l)
        {
            int mid = l + (r - l) / 2;
            
            if(nums[mid] > nums[mid + 1])
            {
                return nums[mid + 1];
            }
            
            if(nums[mid] < nums[mid - 1])
            {
                return nums[mid];
            }
            
            
            if(nums[mid] > nums[0])
                l = mid + 1;
            else
            {
                r = mid - 1;
            }
        }
        
        
        return INT_MAX;
    }
};