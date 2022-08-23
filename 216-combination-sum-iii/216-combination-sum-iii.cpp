class Solution {
public:
    void combine(int i, vector<int> &nums, vector<int> &entry, int k, int n, vector<vector<int>> &combinations)
    {
        
        if(k == entry.size() and n == 0)
        {
            combinations.push_back(entry);
            return;
        }
        
        else if(n < 0 or i == nums.size())
        {
            return;
        }
        
        else
        {
            entry.push_back(nums[i]);
            combine(i + 1, nums, entry, k, n - nums[i], combinations);
            entry.pop_back();
            combine(i + 1, nums, entry, k, n, combinations);
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        vector<int> entry;
        vector<vector<int>> combinations;
        
        combine(0, nums, entry, k, n, combinations);
        return combinations;
    }
};