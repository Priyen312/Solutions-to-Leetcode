class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        //we trim out the leaf nodes first, which are the farther away from the centroids. At each step, the nodes we trim out are closer to the centroids than the nodes in the previous step. At the end, the trimming process terminates at the centroids nodes.
        
        if(n < 2)
        {
            vector<int> centroids;
            
            for(int i = 0; i < n; i++)
                centroids.push_back(i);
            
            return centroids;
        }
        vector<vector<int>> adj(n);
        vector<int> degrees(n,0);
        for(auto i: edges)
        {
            adj[i[1]].push_back(i[0]);
            adj[i[0]].push_back(i[1]);
            degrees[i[0]]++;
            degrees[i[1]]++;
        }
        
               
        vector<int>res;
        
        queue<int>queue;
        for(int i = 0; i < n; i++)
        {
            if(degrees[i] == 1)         //adding all the leave nodes
                queue.push(i);
        }
        
        while(!queue.empty())
        {
            res.clear();// clear vector before we start traversing level by level.
            int size = queue.size();
            
            for(int i = 0; i < size; i++)
            {
                int cur = queue.front();
                queue.pop();
                
                res.push_back(cur);//adding nodes to vector.Goal is to get a vector of  just 1 or 2 nodes available.
                for(auto &neighbor:adj[cur])
                {
                    degrees[neighbor]--;//removing current leave nodes
                    if(degrees[neighbor]==1)//adding current leave nodes
                        queue.push(neighbor);
                }
            }
        }
        return res;
    
    }
};