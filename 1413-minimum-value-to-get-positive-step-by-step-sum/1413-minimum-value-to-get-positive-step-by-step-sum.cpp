class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int minimum = INT_MIN;
        for(auto i : nums) {
            sum += i;
            minimum = max(abs(sum), minimum);
        }
        int l = 1;
        int r = (minimum) + 1;
        
        while(l < r) {
            int mid = (l + r) / 2;
            bool isValid = true;
            int sum = 0;
            for(auto i: nums) {
                sum += i;
                if(sum <= -1 * mid) {
                    isValid = false;
                    break;
                }
            }
            
            
            if(isValid) {
                r = mid;
            }
            else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};