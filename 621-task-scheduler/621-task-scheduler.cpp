class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<int> maxHeap;
        
        queue<pair<int, int>> q;
        
        int m = tasks.size();
        unordered_map<char, int> f;
        for(int i = 0; i < m; i++)
        {
            f[tasks[i]]++;
        }
        
        
        for(auto i: f)
        {
            maxHeap.push(i.second);
        }
        
        
        int time = 0;
        
        while(maxHeap.size() or q.size())
        {
            time += 1;
            if(maxHeap.size())
            {
                int task_rem = maxHeap.top();
                maxHeap.pop();
                task_rem -= 1;
                
                if(task_rem > 0)
                    q.push({task_rem, time + n});
            }
            
            if(q.size() and q.front().second == time)
            {
                maxHeap.push(q.front().first);
                q.pop();
            }
            
            
            
            
        }
        
        
        return time;
    }
};