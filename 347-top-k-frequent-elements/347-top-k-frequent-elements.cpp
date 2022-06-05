class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> m;
        for(auto i: nums)
        {
            m[i]++;
        }
        
        vector<int> res;
        
        priority_queue<pair<int, int>> maxHeap;
        for(auto i: m)
        {
            pair<int, int> entry = {i.second, i.first};
            
            
                maxHeap.push(entry);
            
            
            if(maxHeap.size() > m.size() - k)
            {
                res.push_back(maxHeap.top().second);
                maxHeap.pop();
                
            }
        }
        
        
        return res;
        
        
    }
};