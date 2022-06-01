class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        vector<int> v;
        for(auto x:nums)
        {       
            s.insert(x);
        }
        int length = 0;
        for(auto x:s)
        {   //means this is the first in the series
            if (s.count(x - 1) == 0)
            {
                int i = 0;
                while(s.count(x+i) == 1)
                {   
                    i++;
                    length = max(i,length);
                    
                }
            }
        }
        return length; 
        
    }
};