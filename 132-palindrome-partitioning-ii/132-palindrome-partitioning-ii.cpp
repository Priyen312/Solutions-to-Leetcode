class Solution {
public:
//     int minCut(string s) {
//    int n = s.size();
//         vector<int> cut(n+1, 0);  // number of cuts for the first k characters
//         for (int i = 0; i <= n; i++) cut[i] = i-1;
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
//                 cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

//             for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
//                 cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
//         }
//         return cut[n];
//     }
    bool is_palindrome(string &t, int s, int e)
    {
        while(s<e)
        {
            if(t[s++]!=t[e--])
                return false;
        }
        
        return true;
    }
    int partition(string &s, int i, int n, vector<int> &dp)
    {
        
        if(i == n)// reaching the end
            return 0;
        if(dp[i] != -1)
            return dp[i];
        
        int min_cost = INT_MAX;
        
        
        for(int j = i; j<n; j++)
        {
            if(is_palindrome(s, i, j)){//this is a string from i...j
                
                int cost = 1 + partition(s, j + 1, n, dp);// make a partition here since it is a palindrome and call the function from the next index
            min_cost = min(min_cost, cost);
            }
        }
        
        return dp[i] = min_cost;
    }
    int minCut(string s){
        vector<int> dp(s.size(), - 1);
        return partition(s, 0, s.size(), dp) - 1;
        
    }
};