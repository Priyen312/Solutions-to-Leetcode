class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;
        
        vector<int> output;
        
        int r = 0; // the window
        //the queue will have the values in decreasing order thus the front will always be greater one in window
        for(r = 0; r < k; r++)
        {
            while(queue.size() and nums[queue.back()] <= nums[r])// make sure that no smaller values exist in the queue, just pop all the smaller values before pushing the current value
                
                queue.pop_back();
            
            
            queue.push_back(r);
        }
        while(r < nums.size())
        {
            output.push_back(nums[queue.front()]);
            
            
            // if leftmost value in the queue is out of bounds of the window meaning it is lesser than left index then remove it from the queue because the window has moved on and the left most value which is the maximum is not related to the current window
            while(queue.size() and queue.front() <= r - k)
                queue.pop_front();
            
            
            while(queue.size() and nums[queue.back()] <= nums[r])// make sure that no smaller values exist in the queue, just pop all the smaller values before pushing the current value
                
                queue.pop_back();
            
            
            queue.push_back(r);
            
            r++;
        }
        output.push_back(nums[queue.front()]);
        return output;
    }
};