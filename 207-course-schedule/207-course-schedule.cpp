class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        
        for(auto i: prerequisites)
        {
            indegree[i[0]]++;// [a,b] b->a
            adj[i[1]].push_back(i[0]);
        }
        
        vector<int> visited(numCourses, 0);
        
        queue<int> q;
        int count = 0;
        for(int i = 0; i < indegree.size(); i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                visited[i] = 1;
                count++;
            }
        }
        
        while(q.size())
        {
            int t = q.front();
            q.pop();
            
            for(auto n: adj[t])
            {
                if(visited[n] == 0)
                {
                    indegree[n]--;
                    if(indegree[n] == 0)// all the prerequisites for the course is met 
                    {
                        q.push(n);
                        visited[n] = 1;
                        count++;
                    }
                    
                }
                
                
            }
        }
        
        return (count == numCourses);
             
    }
};