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

//     void find_cycle(vector<int> &indegree, int course, vector<vector<int>> adj, vector<int> &order)
//     {
//         order.push_back(course);
//         indegree[course] = -1;
//         for(int nei: adj[course])
//         {
//             indegree[nei]--;
//             if(indegree[nei] == 0)
//                 find_cycle(indegree, nei, adj, order);
           
//         }

//     }
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
//     {
//         vector<vector<int>> adj(numCourses, vector<int> ());
//         vector<int> indegree(numCourses, 0);
//         for(auto course : prerequisites)
//         {
//             indegree[course[0]]++;
//             adj[course[1]].push_back(course[0]);
//         }
        
//         vector<int> order;
        
//         for(int i = 0; i < numCourses; i++)
//         {
//             if(indegree[i] == 0)
//                 find_cycle(indegree, i, adj, order);
//         }
//         if(order.size() == numCourses) return order;
        
//         return {};

//     }

};