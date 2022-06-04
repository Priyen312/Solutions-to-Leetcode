class Solution {
public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         // O(n * m * logk)
//         priority_queue<int> maxHeap;
        
        
//         for(int r = 0; r < matrix.size(); r++)
//         {
//             for(int c = 0; c < matrix[0].size(); c++)
//             {
//                 maxHeap.push(matrix[r][c]);
                
//                 if(maxHeap.size() > k)
//                     maxHeap.pop();
//             }
//         }
        
        
//         return maxHeap.top();
        
//     }
     
        int count_k(vector<vector<int>> &matrix, int &mid)
        {//O(M+N)
            int less_than_mid = 0;
            int n = matrix.size(), j = matrix[0].size() - 1;
            
            
            for(int i = 0; i < n; i++)
            {
                while(j >= 0 and matrix[i][j] > mid)
                    --j;
                less_than_mid += j + 1;
            }
            
            return less_than_mid;
        }
        int kthSmallest(vector<vector<int>>& matrix, int k) {
        
            int n = matrix.size(), m = matrix[0].size();
            int minimum = matrix[0][0];
            int maximum = matrix[n - 1][m - 1];
            
            int element = -1;
            
            while(minimum <= maximum)
            {
                int mid = (maximum + minimum) / 2;
                
                if(count_k(matrix, mid) >= k)
                {
                    element = mid;
                    maximum = mid - 1;
                }
                
                else
                {
                    minimum = mid + 1;
                }
                
            }
            
            return element;
        }
};