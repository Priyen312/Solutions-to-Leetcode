class Solution {
public:
   
    bool bSearch(vector<int>& nums, int target, int l, int r, int &index)
    {
        while(l <= r)
        {
            int mid = (r + l) / 2;
            
            if(nums[mid] == target)
            {
                index = mid;
                return true;
            }
            
            else if(nums[mid] > target)
                r = mid - 1;
            else
                l = mid + 1;
                
        }
        
        return false;
    }
    int search(vector<int>& nums, int target) {
        int ans = -1;
        
        if(nums.size()==1 && nums[0] == target)
            ans =  0;
        
        else if(nums.size()==1 && nums[0] != target)
            ans = -1;
        
      
        int l = 0, r = nums.size() - 1;
        
        while(l < r) // find the minimum
        {
            int mid = (l + r)/2;
            
            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        cout<<l<<" "<<r;
        int index = -1;
        if(bSearch(nums, target, 0, l - 1, index))
            return index;
        else
        {
            if(bSearch(nums, target, l, nums.size() - 1, index))
                return index;
        }
        
        return index;
    }   
};