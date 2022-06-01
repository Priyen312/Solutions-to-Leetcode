class Solution {
    public:
//      vector<int> sub;
//     vector<vector<int>> res;
//     void dfs(int i,vector<int> nums)
//     {
//         if( i >= nums.size() )
//         {
//             res.push_back(sub); return;
//         }
        
//         sub.push_back(nums[i]);
//         dfs(i+1,nums);
//         sub.pop_back(); 
//         dfs(i+1,nums);
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         dfs(0,nums);
//         return res;
//     }
    void generate_subsets(vector<int> &nums, vector<vector<int>> &power_set, vector<int> curr_set, int index)
    {
        if(index == nums.size())
        {
            power_set.push_back(curr_set);
            return;
        }
        
        
        curr_set.push_back(nums[index]);
        generate_subsets(nums, power_set, curr_set, index + 1);
        curr_set.pop_back();
        generate_subsets(nums, power_set, curr_set, index + 1);
        
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> power_set;
        vector<int> curr_set;
        
        generate_subsets(nums, power_set, curr_set, 0);
        
        return power_set;
    }
};

//          1                 _
//      12     1           2      _     
//   123 12  13  1      23   2   3  _