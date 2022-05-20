class Solution {
public:
    int minimumpath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
    {
        if(i == 0 and j== 0)
            return grid[0][0];
        
        if(i<0 or j<0)
            return 1000;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(grid[i][j] + minimumpath(grid, i - 1, j, dp),grid[i][j] + minimumpath( grid, i, j - 1, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return minimumpath(grid, grid.size() - 1, grid[0].size()-1, dp);
    }
};