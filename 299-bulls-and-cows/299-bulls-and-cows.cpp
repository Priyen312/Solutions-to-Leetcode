class Solution {
public:
    string getHint(string secret, string guess) {
        
        int bulls = 0;
        int cows = 0;
        int i = 0;
        int j = 0;
        unordered_map<int,int> m;
        
        for(int i = 0; i < secret.size(); i++)
        {
            if(secret[i] == guess[i])
            {
                bulls++;
            }
            else
            {
                if(m[secret[i]] < 0)// basically saying that the character has already been guessed
                {
                    cows++;
                }
                if(m[guess[i]] > 0)
                {
                    cows++;
                }
                m[secret[i]]++;
                m[guess[i]]--;
                
                
                
            }
        }
        
        
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
        
    }
};