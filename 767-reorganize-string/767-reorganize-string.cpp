class Solution {
public:
    

    string reorganizeString(string s) {
        
        vector<int> freq(26);
        //calculating the frequency of each character
        int max_freq = 0;
        
        for(auto c: s)
        {
            freq[c - 'a']++;
            if(freq[c - 'a'] > freq[max_freq])
            {
                max_freq = c - 'a';
                
            }
        }
        
        
        if(freq[max_freq]*2 - 1 > s.size())// if even a single character has a frequency greater than half the length of the string then the string cannot be organised because the length would now exceed og length after reorganisation
            return "";
        int index = 0;
        // position the maximum freq char in the even positions first all the while reducing it's freq to zero
        while(freq[max_freq])
        {
            s[index] = 'a' + max_freq;
            index += 2;
            freq[max_freq]--;
        }
        
        for(int i = 0; i < 26; i++)
        {
            
            while(freq[i])
            {
                if(index >= s.size())
                {
                    index = 1;
                }
                
                s[index] = 'a' + i;
                index += 2;
                freq[i]--;
            }
        }
        
        
        
        return s;
        
    }
        
    
};