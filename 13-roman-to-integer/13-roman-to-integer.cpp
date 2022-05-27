class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> symbols;
        
        symbols['I'] = 1;
        
        symbols['V'] = 5;
        
        symbols['X'] = 10;
        
        symbols['L'] = 50;
        
        symbols['C'] = 100;
        
        symbols['D'] = 500;
        
        symbols['M'] = 1000;
        
        int integer_val = 0;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(i+1 < s.size() and symbols[s[i]] < symbols[s[i + 1]])
                integer_val -= symbols[s[i]];
            else
                integer_val += symbols[s[i]];
        }
        
        
        
        return integer_val;
    }
};