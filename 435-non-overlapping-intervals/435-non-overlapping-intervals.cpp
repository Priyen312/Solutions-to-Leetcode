class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        // O(nlogn) Greedy
        sort(intervals.begin(), intervals.end(), [] (vector<int> &a, vector <int> &b) {
            //The heuristic is: always pick the interval with the earliest end time. Then you can get the maximal number of non-overlapping intervals. (or minimal number to remove).
// This is because, the interval with the earliest end time produces the maximal capacity to hold rest intervals.
// E.g. Suppose current earliest end time of the rest intervals is x. Then available time slot left for other intervals is [x:]. If we choose another interval with end time y, then available time slot would be [y:]. Since x ≤ y, there is no way [y:] can hold more intervals then [x:]. Thus, the heuristic holds.
            return a[1] < b[1];
        });
        
        int n = intervals.size();
        if(n <= 1) return 0;
        
        int end = intervals[0][1];
        
        int non_overlapping = 1;
        for(int i = 1; i < n; i++)
        {
            int start = intervals[i][0];
            if(end <= start)
            {
                non_overlapping++;
                end = intervals[i][1];
            }
        }
        
        
        return n - non_overlapping;
    }
};