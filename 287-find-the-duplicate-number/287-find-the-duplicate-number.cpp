class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int duplicate = 0;
        for(int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0)                   //[-1, -4]
            {
                nums[index] *= -1;
            }
            else
                duplicate = nums[i];               //[4]
                
        }
        
        return abs(duplicate);
    }
};