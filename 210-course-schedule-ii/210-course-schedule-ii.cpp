class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses, vector<int> ());
        for(auto course : prerequisites)
        {
            indegree[course[0]]++;
            
            adj[course[1]].push_back(course[0]);
        }
        
        
        queue<int> q;
        int count = 0;
        
        vector<int> visited(numCourses, 0);
        
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                count++;
                visited[i] = 1;
            }
        }
        
        vector<int> order_of_courses;
        while(q.empty() == false)
        {
            int course = q.front();
            
            order_of_courses.push_back(course);
            q.pop();
            
            for(auto neighbours : adj[course])
            {
                
                if(visited[neighbours] == 0) {
                    
                    indegree[neighbours]--;
                
                    if(indegree[neighbours] == 0)
                    {
                        q.push(neighbours);
                        count++;
                        visited[neighbours] = 1;
                    }
                    
                }
                
            }
            
        }
        
        
        if(count != numCourses)
            return {};
        
        return order_of_courses;
        
    }
};