class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        unordered_map<int, int> map;
        
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(map.find(target - nums[i]) == map.end())
            {
                map[nums[i]] = i;
            }
            else
                return {i, map[target - nums[i]]};
        }
        
        return {-1, -1};
    }
};