class Solution {
public:
void dfs(vector<vector<char>> &board, int i, int j, map<pair<int,int>,int> &visited)
    {//O(n^2) as each grid position gets visited once
        if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or  board[i][j] == '0' or visited[{i,j}] == 1)
            return;

        visited[{i,j}] = 1;
        
        dfs(board, i + 1, j, visited);
        dfs(board, i , j + 1, visited);
        dfs(board, i - 1, j, visited);
        dfs(board, i , j - 1, visited);
  
    }
  
void mark3(vector<vector<char>> &board, int i, int j)
{
    if(i < 0 or j < 0 or i >= board.size() or j >= board[0].size() or  board[i][j] != '1')
            return;

        
        board[i][j] = 3;
    
        mark3(board, i + 1, j);
        mark3(board, i , j + 1);
        mark3(board, i - 1, j);
        mark3(board, i , j - 1);
    
}
int numIslands(vector<vector<char>> &surface) {
    // add your logic here
	map<pair<int,int>, int> visited;
    int islands = 0;
    for(int i = 0; i < surface.size(); i++)
    {
        for(int j = 0; j < surface[0].size(); j++)
        {
            if(surface[i][j] == '1')
            {
                mark3(surface, i, j);
                islands++;
            }
        }
    }

    return islands;
}
};