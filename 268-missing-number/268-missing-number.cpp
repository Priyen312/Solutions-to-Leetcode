class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int number = 0, i = 0;
        for(i = 0; i < nums.size(); i++)
        {
            
                number = number ^ i ^ nums[i];
        }
        
        return number^i;
    }
};