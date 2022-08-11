class Solution {
public:
    string minWindow(string s, string t) {
        
        if(t == "")
            return "";
        unordered_map<char, int> countT, window;
        int n = s.size();
        for(auto c: t)
        {
            countT[c]++;
        }
        
        
        int l = 0, r = 0;
        
        int minimum_window = INT_MAX;
        
        int have = 0, need = countT.size();
        int left = -1, right = -1;
        for(;r < n; r++)
        {
            char c = s[r];
            
            window[c]++;
            
            if(countT.find(c) != countT.end() and window[c] == countT[c])
            {
                have++;
            }
            
            while(have == need)
            {
                if(r - l + 1 <= minimum_window)
                {
                    minimum_window = r - l + 1;
                    left = l;
                    right = r;
                }
                
                char exclude = s[l];
                window[s[l++]]--;
                
                if(countT.find(exclude) != countT.end() and window[exclude] < countT[exclude])
                {
                    have--;
                }
                
                
            }
            
            
        }
        
        if(minimum_window != INT_MAX)
            return s.substr(left, minimum_window);
        
        else
            return "";

    }
    
    bool checkInclusion(string s1, string s2) {
        
        string perm = minWindow(s2 ,s1);
        
        return perm.size() == s1.size();
        
    }
};