class Solution {
public:
  
      int memo[1000][1000] = {};
    int helper(int i,int j,string &s)
    {
        if(i > j) return 0;
        if( i == j) return 1;// base case when size == 1
        
        
        if(memo[i][j]!=0) return memo[i][j/*ij*/];
        if(s[i] == s[j])
        memo[i][j] = 2 + helper(i+1,j-1,s);
            else memo[i][j] = max(helper(i,j-1,s),helper(i+1,j,s));
       return memo[i][j];
    }
    int minInsertions(string s) {
        return s.size() - helper(0,s.size()-1,s);
        
        
    }
};