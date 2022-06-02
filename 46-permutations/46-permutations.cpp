class Solution {
public:
    void find_permutations(vector<int>& nums, vector<vector<int>> &permutations, int index)
    {
        if(index == nums.size())
        {
            permutations.push_back(nums);
            return;
        }
        
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            
            find_permutations(nums, permutations, index + 1);
            
            swap(nums[index], nums[i]);
        }
        
        
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> permutations;
        
        
        find_permutations(nums, permutations, 0);
        
        return permutations;
    }
};