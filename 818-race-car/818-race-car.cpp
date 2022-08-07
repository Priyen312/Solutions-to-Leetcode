class Solution {
public:

    int racecar(int target) {
        queue<pair<int, int>> q;
        
        set<pair<int, int>> visited;
        int position = 0, speed = 1;
        q.push( {position, speed} );
        
        visited.insert( {position, speed});
        int instructions = 0;
        
        
        while(q.empty() == false) {
            int size = q.size();
            
            while(size--) {
                auto [position, speed] = q.front(); 
                q.pop();
                
                if(position == target)
                    return instructions;
                
                int new_position = position + speed;
                int new_speed = speed * 2;
                
                if(new_position >= 0 and new_position < 2 * target and visited.find({new_position, new_speed}) == visited.end())
                {
                    q.push({new_position, new_speed});
                    visited.insert({new_position, new_speed});
                }
                
                new_position = position;
                new_speed = speed > 0 ? -1: 1;
                if(new_position >= 0 and new_position < 2 * target and visited.find({new_position, new_speed}) == visited.end())
                {
                    q.push({new_position, new_speed});
                    visited.insert({new_position, new_speed});
                }             
                
            }
            
            
            instructions++;
        }
        
        return 0;
    }
};