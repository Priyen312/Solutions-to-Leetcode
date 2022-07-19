class Solution {
public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
        
//         unordered_map<int, int> m;
//         for(auto i: nums)
//         {
//             m[i]++;
//         }
        
//         vector<int> res;
        
//         priority_queue<pair<int, int>> maxHeap;
//         for(auto i: m)
//         {
//             pair<int, int> entry = {i.second, i.first};
            
            
//                 maxHeap.push(entry);
            
            
//             if(maxHeap.size() > m.size() - k)
//             {
//                 res.push_back(maxHeap.top().second);
//                 maxHeap.pop();
                
//             }
//         }
        
        
//         return res;
        
        
//     }
    struct cmp
	{
		bool operator()(pair<int, int> n1, pair<int, int> n2)
		{
			return n1.first > n2.first;
		}
	};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto i: nums)
        {
            m[i]++;
        }
        
        vector<int> res;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> minHeap;
        
        for(auto [value, freq]: m)
        {
            pair<int, int> entry = {freq, value};
            if(minHeap.size() < k)
                minHeap.push(entry);
            else if(minHeap.top().first < freq)
            {
                minHeap.pop();
                minHeap.push(entry);
            }
        }
        
        
        while(minHeap.empty() == false)
        {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        
        return res;
    }
};