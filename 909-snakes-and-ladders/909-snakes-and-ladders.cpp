class Solution {
public:
    pair<int,int> position(int square, int n)
    {
        int r = (square - 1) / n;
        int c = (square - 1) % n;
        
        if(r % 2)
            c = n - 1 - c;
        
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        reverse(board.begin(), board.end());
        queue<pair<int, int>> q;//[square, moves]
        q.push({1, 0});
        set<int> visited;
        
        while(q.size())
        {
            int square = q.front().first;
            int moves = q.front().second;
            q.pop();
            
            for(int i = 1 ; i <= 6; i++) {
                
                int nextSquare = square + i;
                pair<int,int> rc = position(nextSquare, board.size());
                int r = rc.first;
                int c = rc.second;
                
                if(board[r][c] != -1)
                {
                    nextSquare = board[r][c];
                }
                if(nextSquare == board.size() * board.size())
                    return moves + 1;
                
                if(visited.find(nextSquare) == visited.end())
                {
                    q.push({nextSquare, moves + 1});
                    visited.insert(nextSquare);
                }
                
            }
        }
        
        return -1;
        
    }
};