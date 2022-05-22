class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        map<int,int> chars;
        int left,r = 0;
        int ans = 0;
        while(r<s.size())
        {
          
            chars[s[r]]++;
            
            while(chars[s[r]] > 1)
            {
                
                chars[s[left]]--;
                left++;
            }
            ans = max(ans,r-left +1);
            r++;
        }
        
        return ans;
    }
};