class Solution {
public:
    int move(int m, int n, vector<vector<int>> &dp)
{
	if(m == 1 or n == 1)
		return 1;
        
	if(dp[m][n] != -1)
		return dp[m][n];
	
	return dp[m][n] = move(m-1, n, dp) + move(m, n - 1, dp);
}

int uniquePaths(int m, int n) {
    // add you logic here
	
	vector<vector<int>> dp(m + 1, vector<int> (n + 1 , -1));
	
	return move(m, n, dp);
}
};