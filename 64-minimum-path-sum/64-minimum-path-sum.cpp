class Solution {
public:
    int minimumpath(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
    {
        if(i == grid.size() - 1 and j == grid[0].size() - 1)
            return grid[grid.size() - 1][grid[0].size() - 1];
        
        if(i >= grid.size() or j >= grid[0].size())
            return 1000;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = minimumpath( grid, i, j + 1, dp);
        int down = minimumpath(grid, i + 1, j, dp);
        
        
        int value = grid[i][j] + min(down, right);
        return dp[i][j] = value;
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        return minimumpath(grid, 0, 0, dp);
    }
};