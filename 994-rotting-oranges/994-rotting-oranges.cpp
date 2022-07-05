class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
  
        queue<pair<int,int>> q;
        vector <int> d = {1,0,-1,0,1};
        int fresh = 0;
        
        for(int i = 0 ; i < grid.size(); i++)
        {
            for(int j = 0 ; j < grid[0].size(); j++) 
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                    fresh = fresh + 1;
            }
        }
        
        int time = -1;
        
        while(q.size())
        {
            int size = q.size();
            while(size--)
            {
                pair<int,int> p = q.front();
                q.pop();
                
                for(int a = 0; a<d.size()- 1;a++)
                {
                    int row = p.first + d[a];
                    int col = p.second + d[a+1];
                    
                    if(row < grid.size() && row > -1 && col < grid[0].size() && col > -1)
                    {
                        if(grid[row][col] == 1)
                        {
                            grid[row][col] = 2;
                            fresh--;
                            q.push({row,col});
                        }
                    }
                }
            }
            
            time++;
        }
        if(fresh > 0) return -1;
        if(time == -1) return 0;
        return time;
        }
};