class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {        
    vector<string> res;
    sort (words.begin(), words.end(), [](const string&a, const string&b){return a.length() < b.length();});
    unordered_set<string> preWords;
   
    for (int i=0; i<words.size(); i++)
    {
        vector<int> dp(words[i].length(), -1);
        if (dfs (preWords, words[i], 0, dp))
        {
            res.push_back(words[i]);
        }
        preWords.insert(words[i]);
    }
    
    return res;
}

bool dfs(unordered_set<string>& preWords, string word, int start, vector<int>& dp)
{
    if (preWords.empty())
    {
        return false;
    }
    
    if (start == word.length())
    {
        return true;
    }
    
    if (dp[start] != -1)
    {
        return dp[start];
    }
    
    for (int i=1; start+i<=word.length(); i++)
    {
        string subWord = word.substr(start, i);
        if (preWords.find(subWord) != preWords.end() && dfs(preWords, word, start+i, dp))
        {
            dp[start] = 1;
            return true;
        }
    }
    
    dp[start] = 0;
    return false;
}
    // use of trie gives the solution
//     bool search(string word, unordered_set<string> wordSet, unordered_map<string, bool> &memo)
//     {
//         if(memo.find(word) != memo.end())
//             return memo[word];
        
//         memo[word] = false;
        
//         for(int i = 1; i < word.size(); i++)
//         {
//             string pre = word.substr(0, i);
//             string suf = word.substr(i);
            
//             if(wordSet.find(pre) != wordSet.end() and wordSet.find(suf) != wordSet.end())
//                 return memo[word] = true;
            
//             if(wordSet.find(pre) != wordSet.end() and search(suf, wordSet, memo))
//                return memo[word] = true;
            
//             if(wordSet.find(suf) != wordSet.end() and search(pre, wordSet, memo))
//                return memo[word] = true;
//         }
               
//         return false;
//     }
//     vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        
//         //sort(words.begin(), words.end());
//         unordered_set<string> wordSet;
//         unordered_map<string, bool> memo;
//         for(auto word: words)
//         {
//             wordSet.insert(word);
//         }
        
//         vector<string> concatenated_words;
        
//         for(auto word: words)
//         {
//             if(search(word, wordSet, memo))
//                 concatenated_words.push_back(word);
//         }
        
//         return concatenated_words;
        
//     }
};