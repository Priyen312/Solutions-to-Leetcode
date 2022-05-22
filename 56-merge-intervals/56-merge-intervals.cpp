class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
        vector<vector <int>> mer; vector <int> temp;
        if(!intervals.size() || intervals.size() == 1){
              return intervals; 
        }
        
        sort(intervals.begin(),intervals.end());
        temp = intervals[0];
        for(int i = 1; i<intervals.size();i++)
        {
            if(temp[1] >= intervals[i][0])
            {
                temp[1] = max(temp[1],intervals[i][1]);
               
            }
            else
            {
                 mer.push_back(temp);
                temp = intervals[i];
            }
            
            
        }
        mer.push_back(temp);
        return mer;
        
    }
};