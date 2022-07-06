class Solution {
public:
    //Find the mid element of the array.

// If mid element > first element of array this means that we need to look for the inflection point on the right of mid.

// If mid element < first element of array this that we need to look for the inflection point on the left of mid.
//     int findMin(vector<int>& nums) {
//         int n = nums.size();
//         if(n == 1)
//             return nums[0];
        
//         int l = 0, r = n - 1;
        
//         if(nums[r] > nums[0])
//             return nums[0];
        
//         while(r >= l)
//         {
//             int mid = l + (r - l) / 2;
            
//             if(nums[mid] > nums[mid + 1])
//             {
//                 return nums[mid + 1];
//             }
            
//             if(nums[mid] < nums[mid - 1])
//             {
//                 return nums[mid];
//             }
            
            
//             if(nums[mid] > nums[0])
//                 l = mid + 1;
//             else
//             {
//                 r = mid - 1;
//             }
//         }
        
        
//         return INT_MAX;
//     }
    
    int findMin(vector<int>& nums)
    {
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
        
        return nums[l];
    }
};