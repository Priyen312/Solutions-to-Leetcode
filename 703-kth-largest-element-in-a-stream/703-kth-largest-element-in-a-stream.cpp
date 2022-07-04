class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int k;//form a min heap
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto I: nums)
        {
            min_heap.push(I);
        }
        // only keep k elements in heap.
        while(min_heap.size() > k)
            min_heap.pop();
    }// Now the heap has k elements which are largest in the stream as the lowest have been discarded
    
    int add(int val) {
        this->min_heap.push(val);// we push in without caring for if it is the new greater or no
        //int ans = -1;
        if(min_heap.size() > k)// maintain the size of heap to k
            min_heap.pop();
        
        return min_heap.top();// the heap top has the lowest in the heap but size is k so it is kth largest
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */