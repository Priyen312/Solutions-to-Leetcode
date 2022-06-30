class Solution {
public:
    vector<int> order;
    bool cycle(int &course, vector<vector<int>> &adj, vector<int> &vis)
    {//We just have to find if our graph contains cycle or not because if graph contains cycle then all tnodes in cycle are interdependent and 1 course cannot be completed because its prerequisite is dependent on other course and it goes on .
// We used coloring algorithm to find if there is cycle in graph or not.

// Coloring Algorithm
// vis[id]=0 is used for node which is not yet visited, vis[id]=1 is used for the node which is visited and currently its child nodes are being visited and vis[id]=2 done when all the child nodes of a node ("id") are visited and the function returns to parent node of node ("id"). So at that time it is marked as 2 because this node does not require any further traversing.
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
        order.push_back(course);
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
            if(vis[course] == 0 and cycle(course, adj, vis))
                return false;
        }
        
        if(order.size() == numCourses)
        {
            for(auto course: order)
                cout<< course<< " ";
            
            cout<<endl;
        }
        else cout<< "";
        
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