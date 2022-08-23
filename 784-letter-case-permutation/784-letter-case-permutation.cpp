class Solution {
public:
    
    char newChar(string s, int i)
    {
        if(s[i] >= 'a' and s[i] <= 'z')
        {
            return toupper(s[i]);
        }
        else if(s[i] >= 'A' and s[i] <= 'Z')
        {
            return tolower(s[i]);
        }
        else
            return s[i];
    }
    void combine(int i, string &s, vector<string> &combinations)
    {
        if(i == s.size())
        {
            combinations.push_back(s);
            return;
        }
        char og = s[i];
        char ch = newChar(s, i);
        
        combine(i + 1, s, combinations);
        
        
        if(og != ch)
        {
            s[i] = ch;
            combine(i + 1, s, combinations);
            
        }
        
        
    }
    
    vector<string> letterCasePermutation(string s) {
        
        vector<string> combinations;
        
        combine(0, s, combinations);
        
        return combinations;
    }
};