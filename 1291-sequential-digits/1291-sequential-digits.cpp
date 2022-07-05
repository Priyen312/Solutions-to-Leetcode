class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        
        for(int i = 1; i <= 9; i++) {
            q.push(i);
        }
        
        vector<int> ret;
        
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            
            if(top <= high && top >= low) {
                ret.push_back(top);
            }
            
            if(top > high)
                break;
            
            int last_digit = top % 10;
            if(last_digit < 9) {
                q.push(top * 10 + (last_digit + 1));
            }
        }
        return ret;
    }
};