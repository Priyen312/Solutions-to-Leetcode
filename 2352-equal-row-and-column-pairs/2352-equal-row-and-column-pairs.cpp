class Solution {
public:
    void makeRows(vector<vector<int>>& grid, unordered_map<string, int> &rows)
    {
        for(auto &row: grid)
        {
            string r = "";
            for(auto i: row)
            {
                char c = i - '0';
                r += c + ' ';
            }
            
            rows[r]++;
        }
    }
    
    int makeCols(vector<vector<int>>& grid, unordered_map<string, int> &rows)
    {
        int n = grid.size();
        int m = grid[0].size();
        int s = 0;       
        for(int i = 0; i < n; i++)
        {
            string c = "";
            for(int j = 0; j < m; j++)
            {
                int ele = grid[j][i];
                char ch = ele - '0';
                c += ch + ' ';
            }
            
            if(rows.find(c) != rows.end())
                s += rows[c];
        }
        
        return s;
    }
    int equalPairs(vector<vector<int>>& grid) {
        
        unordered_map<string, int> rows;
        makeRows(grid, rows);
        return makeCols(grid, rows);
        
        
    }
};