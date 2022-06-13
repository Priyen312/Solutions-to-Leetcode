class Solution {
public:
    bool isvalid(vector<vector<char>> &sudoku, int r,int c, int n)
    {
        char digit = to_string(n).back();
        bool row_is_valid = true,column_is_valid = true;

        for(int i = 0; i < 9; i++)
        {
            if(sudoku[r][i] == digit)
            {
                row_is_valid = false;
                break;
            }
        }
        for(int i = 0; i < 9; i++)
        {
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
                if(sudoku[i][j] == digit)	
                    return false;

            }
        }

        return true;
    }

bool start_solving(vector<vector<char>> &sudoku, int r, int c)
{
	if(r==9)
		return true;
	else if(c==9)
		return start_solving(sudoku,r+1,0);
	else if(sudoku[r][c] != '.')
		return start_solving(sudoku, r, c + 1);
	
		for(int j = 1; j < 10; j++)
		{
			
			if(isvalid(sudoku,r,c,j))
			{
				sudoku[r][c] = to_string(j).back();
				if (start_solving(sudoku,r,c + 1))
					return true;
			}
		}
		
    sudoku[r][c] = '.';
    return false;
	
	
}
void solveSudoku(vector<vector<char>> &sudoku) {
	//add your logic here
	start_solving(sudoku,0,0);
	
    }
};