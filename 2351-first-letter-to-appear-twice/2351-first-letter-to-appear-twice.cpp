class Solution {
public:
    char repeatedCharacter(string s) {
        
        int n = s.size();
        char freq[26] = {0};
        int index = 0;
        for(int i = 0; i < n; i++)
        {
            index = s[i] - 'a';
            
            freq[index]++;
            if(freq[index] == 2)
                return s[i];
        }
        
        return s[0];
    }
};