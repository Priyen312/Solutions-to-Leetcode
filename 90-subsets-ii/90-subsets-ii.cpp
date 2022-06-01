class Solution {
public:
    
    void generate_power_set_with_dup(vector<int>& nums, vector<vector<int>> &power_set, vector<int> curr_set, int index)
    {
        if(index == nums.size())
        {
            power_set.push_back(curr_set);
            return;
        }
        // [[1,2,2],[1,2],[1,2],[1],[2,2],[2],[2],[]] the output if redundant elements are not ignored
        curr_set.push_back(nums[index]);
        generate_power_set_with_dup(nums, power_set, curr_set, index + 1);
        
        while(index + 1< nums.size() and nums[index] == nums[index + 1])
            index++;
        
        curr_set.pop_back();
        generate_power_set_with_dup(nums, power_set, curr_set, index + 1);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // [4,4,4,1,4] sort because the while loop wouldn't encounter 4 at the end and the power_set would be messed
        sort(nums.begin(), nums.end());
        vector<vector<int>> power_set;
        vector<int> curr_set;
        
        generate_power_set_with_dup(nums, power_set, curr_set, 0);
        
        return power_set;
        
    }
};