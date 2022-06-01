class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int index = abs(nums[i]) - 1;
            
            if(nums[index] > 0)
            {
                nums[index] *=-1;
            }
            else
                duplicates.push_back(abs(nums[i]));
        }
        return duplicates;
    }
};