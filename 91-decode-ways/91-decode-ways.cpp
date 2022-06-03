class Solution {
public:
    // recursion is O(2n)
    int decode(string s, int i, vector<int> &memo)
    {//O(n)
        if(i == s.size())
            return 1;
        if(s[i] == '0')
            return 0;
        if(memo[i] != -1)
            return memo[i];
        
        int res = decode(s, i + 1, memo);
        if(i + 1 < s.size() and (s[i] == '1' or (s[i] == '2' and s[i+1] <='6')))
            res +=  decode(s, i + 2, memo);
                                 
        return memo[i] = res;
                                 
        
    }
    int numDecodings(string s) {
        
//     unordered_map<string,string> m;
//     int i = 1;
    
//     for(char c = 'a'; c <= 'z'; c++)
//     {
//         m[to_string(i)] = c;
//         i++;
        
//     }
        vector<int> memo(s.size() + 1, -1);
        return decode(s, 0, memo);
    }
};