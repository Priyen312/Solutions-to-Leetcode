class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //We could keep 2 pointer,one for the start and another for the end of the current subarray, and make optimal moves so as to keep the sum greater than ss as well as maintain the lowest size possible.
        int l = 0;
        int sum = 0;
        int res = INT_MAX;
        
        for(int r = 0; r< nums.size(); r++)
        {
            sum += nums[r];
            
            while(sum>=target)
            {
                res = min(res, r + 1 - l);
                sum -= nums[l++];
            }
        }
        
        return ((res!= INT_MAX) ? res : 0);
    }
};