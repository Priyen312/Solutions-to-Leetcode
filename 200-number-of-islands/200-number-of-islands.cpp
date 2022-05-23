class Solution {
public:
void dfs(vector<vector<char>> &board, int i, int j, map<pair<int,int>,int> &visited)
    {
        if(i<0 or j<0 or i>=board.size() or j>=board[0].size() or  board[i][j] != '1' or visited[{i,j}] == 1)
            return;

        visited[{i,j}] = 1;
        
    
        dfs(board, i + 1, j, visited);
        dfs(board, i , j + 1, visited);
        dfs(board, i - 1, j, visited);
        dfs(board, i , j - 1, visited);

        
        
    }
  

int numIslands(vector<vector<char>> &surface) {
    // add your logic here
	map<pair<int,int>, int> visited;
    int islands = 0;
    for(int i = 0; i < surface.size(); i++)
    {
        for(int j = 0; j < surface[0].size(); j++)
        {
            if(surface[i][j] == '1' && visited.find({i,j}) == visited.end())
            {
                dfs(surface, i, j, visited);
                islands++;
            }
        }
    }

    return islands;
}
};