class Solution {
public:
    void flow_water(vector<vector<int>>& heights, int r, int c, set <pair<int, int>> &visit, int prev_Height)
    {
        int rows = heights.size();
        int cols = heights[0].size();
        if(r < 0 or c < 0 or r >= rows or c >= cols) 
            return;
        if(heights[r][c] < prev_Height or visit.find({r, c}) != visit.end())
            return;
        
        int X[] = {1, 0, -1, 0},
            Y[] = {0, 1, 0, -1};
        
        visit.insert({r, c});
        for(int i = 0; i < 4; i++)
        {
            int new_r = r + X[i];
            int new_c = c + Y[i];
            
            flow_water(heights, new_r, new_c, visit, heights[r][c]);
            
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        set <pair<int, int>> pfc;
        set <pair<int, int>> atl;
        
        int r = heights.size(), c = heights[0].size();
        
        for(int col = 0; col < c; col++)
        {
            flow_water(heights, 0, col, pfc, heights[0][col]);
            flow_water(heights, r - 1, col, atl, heights[r - 1][col]);
        }
        
        for(int row = 0; row < r; row++)
        {
            flow_water(heights, row, 0, pfc, heights[row][0]);
            flow_water(heights, row, c - 1, atl, heights[row][c - 1]);
        }
        
        
        vector<vector<int>> coordinates;
        
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                if(pfc.find({i,j}) != pfc.end() and atl.find({i,j}) != atl.end())
                    coordinates.push_back({i, j});
            }
        }
        
        return coordinates;
        
    }
};