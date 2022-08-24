class Solution {
public:
    void isPalin(string &s, int l, int r, int &count)
    {
        while(l >= 0 and r < s.size() and s[l--] == s[r++])
        {
                count++;
        }
        
    }
    
    
    int countSubstrings(string s) {
        
        
        int n = s.size();
        if(s.size() <= 1)
            return n;
        int count = 0;
        for(int i = 0; i < n; i++)
        {
            isPalin(s, i, i, count);
            isPalin(s, i, i + 1, count);
        }
        
        
        return count;
    }
};