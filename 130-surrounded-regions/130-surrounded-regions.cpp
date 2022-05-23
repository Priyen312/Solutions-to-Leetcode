class Solution {
public:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or  board[i][j] != '-')
            return;
        
        board[i][j] = 'O';
        dfs(board, i + 1, j);
        dfs(board, i , j + 1);
        dfs(board, i - 1, j);
        dfs(board, i , j - 1);
        
        
    }
    void solve(vector<vector<char>>& board) {
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == 'O')
                {
                    board[i][j] = '-';
                }
            }
        }
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(i == 0 or j == 0 or i == board.size() - 1 or j == board[0].size() - 1)
                {
                    if(board[i][j] == '-')
                    {
                        dfs(board, i , j);
                    }
                }
            }
        }
        
        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(board[i][j] == '-')
                {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};