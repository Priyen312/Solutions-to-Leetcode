class Solution {
public:
    
    bool cycle(int &course, vector<vector<int>> &adj, vector<int> &vis)
    {
        if(vis[course] == 1)
            return true;
        if(vis[course] == 0)
        {    
            vis[course] = 1;
            for(auto edge: adj[course])
            {

                if(cycle(edge, adj, vis))
                    return true;
            }
        }
        
        vis[course] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> adj(numCourses);
        for(auto i: prerequisites)
        {
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(numCourses, 0);
        
        for(int course = 0; course < numCourses; course++)
        {
            if(cycle(course, adj, vis))
                return false;
        }
        
        return true;
    }
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<vector<int>> adj(numCourses, vector<int>());
//         vector<int> indegree(numCourses, 0);
        
//         for(auto i: prerequisites)
//         {
//             indegree[i[0]]++;// [a,b] b->a a++
//             adj[i[1]].push_back(i[0]);
//         }
        
//         vector<int> visited(numCourses, 0);
        
//         queue<int> q;
//         int count = 0;
//         for(int i = 0; i < indegree.size(); i++)
//         {
//             if(indegree[i] == 0)
//             {
//                 q.push(i);// starting node
//                 visited[i] = 1;
//                 count++;
//             }
//         }
        
//         while(q.size())
//         {
//             int t = q.front();
//             q.pop();
            
//             for(auto n: adj[t])
//             {
//                 if(visited[n] == 0)
//                 {
//                     indegree[n]--;
//                     if(indegree[n] == 0)// all the prerequisites for the course is met 
//                     {
//                         q.push(n);
//                         visited[n] = 1;
//                         count++;
//                     }
                    
//                 }
                
                
//             }
//         }
        
//         return (count == numCourses);
             
//     }
};