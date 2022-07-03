class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<int,int> chars;
        int l = 0;
        int res = 0;
        
        int m = s.size();
        for(int r = 0; r < m; r++)
        {
          
            chars[s[r]]++;
            
            while(chars[s[r]] > 1)
            {
                chars[s[l++]]--;
                
            }
            res = max(res,r - l + 1);

        }
        
        return res;
    }
};