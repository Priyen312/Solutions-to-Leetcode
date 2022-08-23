class Solution {
public:
    struct cell{
        int x;
        int y;
        int k;
        int moves;
        
        cell(int _x, int _y, int _k, int _moves){
            x = _x;
            y = _y;
            k = _k;
            moves = _moves;
        }
    };
    
    int shortestPath(vector<vector<int>>& grid, int k) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        if(grid[0][0] == 1 or grid[n - 1][m - 1] == 1)
            return -1;
              
        //vector<vector<vector<int>>> vis(n, vector<vector<int>>(m,vector<int>(k+1,0)));

        vector<vector<vector<int>>> vis(n, vector<vector<int>> (m, vector<int> (k + 1, 0)));
        
        queue<cell> q;
        cell entry(0, 0, k, 0);
        vis[0][0][k] = 1;
        
        q.push(entry);
        int newRC[] = {-1, 0, 1, 0, -1};
        
        
        
        while(q.empty() == false)
        {
            cell posn = q.front();
            q.pop();
            
            int r = posn.x;
            int c = posn.y;
            int bal = posn.k;
            int steps = posn.moves;
            if(r == n - 1 and c == m - 1)
                return steps;
           
            
            
            for(int i = 0; i < 4; i++)
            {
                int R = r + newRC[i];
                int C = c + newRC[i + 1];
                
                if(R == n - 1 and C == m - 1)
                    return steps + 1;
            
                if(R >= 0 and R < n and C >= 0 and C < m and vis[R][C][bal] == 0)
                {
                    
                     
                        if(grid[R][C] == 1)
                        {
                            if(bal > 0){
                                cell entry(R, C, bal - 1, steps + 1);
                                vis[R][C][bal] = 1;
                                q.push(entry);
                            }
                            
                        }
                        else
                        {
                            cell entry(R, C, bal, steps + 1);
                            vis[R][C][bal] = 1;

                            q.push(entry);
                        }
                }
            
            }
            
        }
            
        return -1;
        
    }
};