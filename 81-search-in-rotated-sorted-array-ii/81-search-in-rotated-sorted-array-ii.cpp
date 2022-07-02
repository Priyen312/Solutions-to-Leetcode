class Solution {
public:

    int search(vector<int>& nums, int target) {
        int ans = -1;
        
        if(nums.size()==1 && nums[0] == target)
            ans =  0;
        
        else if(nums.size()==1 && nums[0] != target)
            ans = -1;
        
      
        int l = 0, r = nums.size() - 1;
        
        while(l <= r) // find the minimum
        {
            while(l < r and nums[l] == nums[l + 1])
                l++;
            
            while(l < r and nums[r] == nums[r - 1])
                r--;
            
           
            int mid = (r + l) / 2;
            
            if(nums[mid] == target)
            {
                return true;
            }
            
            if(nums[mid] >= nums[l])
            {
                if(target >= nums[l] and target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if(target <= nums[r] and target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            
            
        }
        
        return false;
    }   
};