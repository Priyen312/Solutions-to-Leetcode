class Solution {
public:
    
//     vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            //O(nlogn), O(n)
        
//             sort(points.begin(), points.end(), [] (vector<int> &a, vector<int> &b)
//             {
//                 return sqrt(a[0]*a[0] + a[1]*a[1]) < sqrt(b[0]*b[0] + b[1]*b[1]);
//             });
        
//             return vector<vector<int>> (points.begin(), points.begin() + k);
        
//     }
    int distance(int x, int y)
    {
        return (x*x + y*y);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // O(N⋅logk), O(k)
        priority_queue<pair<int, int>> maxHeap;
        
        int n = points.size();
        
        for(int i = 0; i < n; i++)
        {
            int d = distance(points[i][0], points[i][1]);
            pair<int, int> entry = {d, i};
            
            if(maxHeap.size() < k)
            {
                maxHeap.push(entry);
            }
            else if(d < maxHeap.top().first)
            {
                maxHeap.pop();
                maxHeap.push(entry);
            }
              
        }
        
        vector<vector<int>> ans;
        while(maxHeap.empty() == false)
        {
            pair<int, int> p = maxHeap.top();
            maxHeap.pop();
            int index = p.second;
            ans.push_back(points[index]);
        }
        return ans;
    }
};