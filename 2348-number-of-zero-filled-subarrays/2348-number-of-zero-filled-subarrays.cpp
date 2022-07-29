class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        long long res = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != 0)
                j = i + 1;
            res += i - j + 1;
        }
        
        return res;
    }
};