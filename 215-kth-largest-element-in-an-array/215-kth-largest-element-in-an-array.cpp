class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int> maxHeap;
        
        for(auto i: nums)
        {
            if(maxHeap.size() < k)
            {
                maxHeap.push(-1 * i);
            }
            
            else if(maxHeap.top() > -1 * i)
            {
                maxHeap.pop();
                maxHeap.push(-1 * i);
            }
        }
        
        return  -1 * (maxHeap.top());
        
    }
};