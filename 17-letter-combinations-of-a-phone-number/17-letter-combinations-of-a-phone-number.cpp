class Solution {
public:
     void helper(int i,string curr, string digits,vector<string> mappings, vector<string> &res)
       { 
         if(curr.size() == digits.size())
        {
            res.push_back(curr);
            return;
        }
        
        for(auto c : mappings[digits[i] - '0'])
        {
            
            helper(i + 1, curr + c ,digits,mappings, res);
        }
        
        
     }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0) return {};
        
        vector<string> mappings = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string curr;
        
        helper(0,curr,digits,mappings,res);
  
        return res;
    }
};