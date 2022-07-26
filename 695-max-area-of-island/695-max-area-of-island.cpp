class Solution {
public:
    void dfs(vector<vector<int>> &grid, int r, int c, int &count)
    {
        if(r >= grid.size() or c >= grid[0].size() or r<0 or c < 0)
            return;
        if(grid[r][c] == 0)
            return;
        
        
        count++;
        grid[r][c] = 0;
        vector<int> x = {1, -1, 0, 0};//, 1, 1, -1, -1};
        vector<int> y = {0, 0, 1, -1};//,1, -1, 1, -1};
        for(int i = 0; i < x.size(); i++)
        {
            int R = r + x[i];
            int C = c + y[i];
            
            dfs(grid, R, C, count);
        }
        
        //return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maximum = 0;
        vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1 and visited[i][j] == 0)
                {
                    int c = 0;
                    dfs(grid, i, j, c);
                    visited[i][j] = 1;
                    maximum = max(maximum, c);
                }
            }
        }
        
        return maximum;
    }
//     int dfs(vector<vector<int>> &grid, int r, int c)
//     {
//         if(r >= grid.size() or c >= grid[0].size() or r<0 or c < 0)
//             return 0;
//         if(grid[r][c] == 0)
//             return 0;
        
        
//         int area = 1;
//         grid[r][c] = 0;
//         vector<int> x = {1, -1, 0, 0};//, 1, 1, -1, -1};
//         vector<int> y = {0, 0, 1, -1};//,1, -1, 1, -1};
//         for(int i = 0; i < x.size(); i++)
//         {
//             int R = r + x[i];
//             int C = c + y[i];
            
//             area += dfs(grid, R, C);
//         }
        
//         return area;
//     }
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
//         int maximum = 0;
//         vector<vector<int>> visited(grid.size(), vector<int> (grid[0].size(), 0));
//         for(int i = 0; i < grid.size(); i++)
//         {
//             for(int j = 0; j < grid[0].size(); j++)
//             {
//                 if(grid[i][j] == 1 and visited[i][j] == 0)
//                 {
//                     int c = dfs(grid, i, j);
//                     visited[i][j] = 1;
//                     maximum = max(maximum, c);
//                 }
//             }
//         }
        
//         return maximum;
//     }
};