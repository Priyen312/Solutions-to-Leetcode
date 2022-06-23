class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);// O(s.size() * max_size in array)
        dp[s.size()] = true;
        for(int i = s.size() - 1; i>=0; i--)
        {
            for(auto w: wordDict)
            {
                if((i + w.size() <= s.size()) && s.substr(i,w.size()) == w)
                {
                    dp[i] = dp[i + w.size()];// this is done because we know that we have a word from the current position in the dictionery but that is not the end since we also need the entire word to be in the dictionery we check if the remaining part is also able to be true, as we are working backwards we know the state of the remaining from that point onwards.
                    
                    if(dp[i] == true)// since we found a way to word break from current we don't need to look through others in the dictionary
                    break;
                }
                
                
            }
        }
        
        
        return dp[0];
    }
    
    //"leetcode", wordDict = ["leet","code"]
    //word_length = 8
    //dp[8] = T
    //dp[7] = dp[6] = F
    //dp[5] = F
    //dp[4] = dp[4 + 4] = T
    //dp[3] = dp[2] = F
    //dp[1] = F
    //dp[0] = T because we have dp[0 + 4] = T
    //thus a word from dp[0] leads to dp[4] which is also possible and leads to dp[8] the end
};