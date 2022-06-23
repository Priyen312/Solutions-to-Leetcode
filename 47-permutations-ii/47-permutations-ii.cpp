class Solution {
public:
    
    void generate_permutations(vector<int>& nums, vector<vector<int>> &permutations, int index)
    {
        if(index == nums.size())
        {
            permutations.push_back(nums);
            return;
        }
        
       unordered_set<int> s;
        
        for(int i = index; i < nums.size(); i++)
        {
            if(s.find(nums[i]) == s.end())// check if the number in the array has already been considered for the permutation
            {
                s.insert(nums[i]);
                
                swap(nums[index], nums[i]);
                generate_permutations(nums, permutations, index + 1);
                swap(nums[index], nums[i]);
                
                
            }
            
                       
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> permutations;
        
        generate_permutations(nums, permutations, 0);
        
        return permutations;
    }
};