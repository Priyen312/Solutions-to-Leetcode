class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res= 1000000000;
        int n = nums.size();
        int l = 0;
        int r = n;
        
        for(int i = 0; i < n; i++)
        {
            
            
            l = i + 1;
            r = n - 1;
            
            while(l < r)
            {
                int sum = nums[l] + nums[r] + nums[i];
                int diff = abs(target - sum);
                
                if(sum == target)
                    return sum;
                else if(sum < target)
                {
                    l++;
                }
                else
                {
                    r--;
                }
                
                if(diff < abs(target - res))
                {
                    res = sum;
                }
            }
            
        }
        
        return res;
    }
};