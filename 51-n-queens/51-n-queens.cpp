class Solution {
public:
    
    
bool is_safe(vector<string> &matrix, int row, int col) {
	
    int n = matrix.size();
	int col_left = col;
	int col_right = col;
	
	while(row >=0)
	{
		if((col_left >=0 && matrix[row][col_left] == 'Q') || matrix[row][col]
			== 'Q'		|| (col_right < n && matrix[row][col_right] == 'Q'))
		   return false;
		
		   row--;
		   col_left--;
		   col_right++;
	}

	return true;
}
bool solveNqueens(vector<string> &matrix, int n, int row, vector<vector<string>> &result) {
	
	if(row == n)
	{
		result.push_back(matrix);
	}
	else
	{
		for(int i = 0; i< n; i++)
		{
			if(is_safe(matrix,row,i))
			{
				matrix[row][i] = 'Q';
				bool b = solveNqueens(matrix,n,row + 1, result);
				if (b)
				{
					return true;
				}
				
				matrix[row][i] = '.'; //backtracking
			}
		}
	}
	
	return false;
	
}

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> result;
        vector<string> matrix;
        string row = "";
        for (int i = 0; i < n; i++) 
        {
            row = "";
            for (int j = 0; j < n; j++) 
            {
                row += '.';
            }
            matrix.push_back(row);
        }
        solveNqueens(matrix, n, 0, result);
        return result;
        
    }
        
};