class Solution {
public:
    
    bool isSafe(vector<vector<char>> &sudoku, int r,int c, char digit)
    {
        
        bool row_is_valid = true,column_is_valid = true;

        for(int i = 0; i < 9; i++)
        {
            if(i == c)
                continue;
            if(sudoku[r][i] == digit)
            {
                row_is_valid = false;
                break;
            }
        }
        for(int i = 0; i < 9; i++)
        {
            if(i == r)
                continue;
            if(sudoku[i][c] == digit)
            {
                column_is_valid = false;
                break;

            }	
        }
        if(row_is_valid == false or column_is_valid == false)
        {
            return false;
        }
        for(int i = r/3*3; i < (r/3*3) + 3; i++)
        {
             
            
            for(int j = c/3*3; j < (c/3*3) + 3; j++)
            {
                if(i == r || j == c)
                    continue;
                
                if(sudoku[i][j] == digit)	
                    return false;

            }
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] != '.')
                {
                    if(!isSafe(board, i, j, board[i][j]))
                        return false;
                }
            }
        }
        
        return true;
    }
};