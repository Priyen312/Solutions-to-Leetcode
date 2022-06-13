class Solution {
public:
    
    void create_chess(int n, vector<string> &grid)
    {
        string row = "";
        for(int i = 0; i < n; i++)
        {
            row = "";
            for(int j = 0; j < n; j++)
            {
                row = row + '.';
            }
            
            grid.push_back(row);
        }
        
    }
    bool isSafe(int r, int c, vector<string> &grid)
    {
        
        int n = grid.size();
        int left = c;
        int right = c;
        while(r >= 0)
        {
            if(grid[r][c] == 'Q' ||
               (left >= 0 and grid[r][left] == 'Q') || 
               (right < n and grid[r][right] == 'Q')
              )
                
                return false;
            
            r--;
            left--;
            right++;
        }
        
        
        return true;
    }
    
    bool print_solutions(int n, int r, vector<string> &grid, vector<vector<string>> &all_possibilities)
    {
        if(r == n)
            all_possibilities.push_back(grid);
        
        
        else{
            
            for(int i = 0; i < n; i++)
            {
                if(isSafe(r, i, grid))
                {
                    grid[r][i] = 'Q';

                    bool check_for_current = print_solutions(n, r + 1, grid, all_possibilities);
                    if(check_for_current)
                    {
                        return true;
                    }

                    grid[r][i] = '.';

                }
            }
            }
        
        return false;
    }

    vector<vector<string>> solveNQueens(int n) {
        
        
        vector<string> grid;
        vector<vector<string>> chess_board;
        
        create_chess(n, grid);
        
        print_solutions(n, 0, grid, chess_board);
        
        return chess_board;
    }
};