class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        
        sort(boxTypes.begin(), boxTypes.end(), [] (auto &a, auto &b) {
            return b[1] < a[1];
        });
        
        int total = 0;
        for(int i = 0; i < boxTypes.size(); i++) {
            int count = min(boxTypes[i][0], truckSize);
            total += count * boxTypes[i][1];
            truckSize -= count;
            
            if(truckSize <= 0)
                return total;
        }
        
        
        return total;
        
         
        
        
    }
};