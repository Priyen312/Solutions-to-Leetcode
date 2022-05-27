class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> queue;
        
        vector<int> output;
        
        int l=0;
        int r =0; // the window
        //the queue will have the valeus in decreasing order thus the front will always be greater one in window
        
        while(r<nums.size())
        {
            while(queue.size() and nums[queue.back()] < nums[r])// make sure that no smaller values exist in the queue, just pop all the smaller values before pushing the current value
                
                queue.pop_back();
            
            
            queue.push_back(r);
            
            
            // if leftmost value in the queue is out of bounds of the window meaning it is lesser than left index then remove it from the queue because the window has moved on and the left most value which is the maximum is not related to the current window
            if(queue.front() < l)
            {
                queue.pop_front();
            }
            
            // using this condition before entering the value because we want that the window is smaller than the array itself before we enter any element
            if((1+r)>=k)
            {
                output.push_back(nums[queue.front()]);
                l++;
            }
            
            r++;
        }return output;
    }
};