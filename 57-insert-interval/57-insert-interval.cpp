class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& interval, vector<int>& newInterval) {
        
        vector<vector<int>> combined;
        for(int i = 0; i < interval.size(); i++)
        {
            int start = newInterval[0];
            int end = newInterval[1];
            
            if(end < interval[i][0])
            {
                combined.push_back(newInterval);
                newInterval = interval[i];
            }
            
            else if(start > interval[i][1])
            {
                combined.push_back(interval[i]);
            }
            
            else
            {
                newInterval = {min(start, interval[i][0]), max(end, interval[i][1])};
            }
        }
            
            combined.push_back(newInterval);
            
            
            return combined;
            
    }
};