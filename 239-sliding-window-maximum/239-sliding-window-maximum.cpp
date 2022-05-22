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
            while(queue.size() and nums[queue.back()] < nums[r])
                queue.pop_back();
            queue.push_back(r);
            
            if(l > queue.front())
            {
                queue.pop_front();
            }
            
            if((1+r )>=k)
            {
                output.push_back(nums[queue.front()]);
                l++;
            }
            
            r++;
        }return output;
    }
};