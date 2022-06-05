class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(100, 0);
        int n = s.size();
        int l = 0;
        int res = 0;
        for(int r = 0; r < n; r++)
        {
            int index = s[r] - 'A';
            
            freq[index]++;
            
            
            while(r - l + 1 - *max_element(freq.begin(), freq.end()) > k)
            {
                
                
                freq[s[l++] - 'A']--;
                
            }
            
            res = max(res, r - l + 1);
            
        }
        
        
        return res;
        
    }
};