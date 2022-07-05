class Solution {
private:
    vector<string> combine(string word, vector<string> prev){
        
        for(int i = 0; i < prev.size(); i++) {
            prev[i] += " " + word;
        }
        return prev;
    }
/*
lets take an example. s="catsand" and wordDict = ["cat", "cats", "and", "sand"].

// The solution starts by taking the string S( "catsand") initially finding whether whole string is present or not . IN this case it is not present in the dict.

// Now breaking the string and then finding
// s.substr( i) gives the substring from ith index till the end. so string word goes as

// atsand // not present
// tsand // not present

// sand //present then the remainder is calculated which is cat in this case and recursive function is called and same thing is done with cat which will return cat and also store the result in the unordered map . Now comes the combine part where both the string are combined and the pushed in the result " cat sand".

and // then comes and which is present so now again wordbreak called on remainder which is cats now and this will return cats. Now both strings are combined and inserted into result . result = {. "cat sand", "cats and"}; Now after the loop ending the result is returned and also stored in map.
    
*/
public:
    unordered_map<string, vector<string>> memo;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
       
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        return formString(s, wordSet);
        
        
    }
    
    vector<string> formString(string s, unordered_set<string>& wordSet) {
        if(memo.find(s) != memo.end())
            return memo[s];
        int n = s.size();
        vector<string> result;
        
        
        if(wordSet.find(s) != wordSet.end())
            result.push_back(s);
        
        for(int i = 1; i < n; i++)
        {
            string new_s = s.substr(i);
            if(wordSet.find(new_s) != wordSet.end())
            {
                string pre = s.substr(0, i);
                vector<string> prev = combine(new_s, formString(pre, wordSet));
                result.insert(result.end(),prev.begin(), prev.end());
            }
        }       
        
        return memo[s] = result;
    }
    
};