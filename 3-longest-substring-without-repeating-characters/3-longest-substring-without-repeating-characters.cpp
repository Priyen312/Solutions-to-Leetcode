class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<int,int> chars;
        int left = 0;
        int res = 0;
        
        int m = s.size();
        for(int r = 0; r < m; r++)
        {
          
            chars[s[r]]++;
            
            while(chars[s[r]] > 1)
            {
                chars[s[left++]]--;
                
            }
            res = max(res,r-left +1);

        }
        
        return res;
    }
};