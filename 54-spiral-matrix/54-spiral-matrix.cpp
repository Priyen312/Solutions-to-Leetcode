class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        
        int left =0,r=matrix[0].size()-1,t = 0,b = matrix.size()-1;
        int rows = matrix.size(); int column = matrix[0].size();
      
        cout<<matrix[0].size()*matrix.size()<<endl;
        while (result.size() < rows * column) {
            // Traverse from left to right.
            for (int col = left; col <= r; col++) {
                result.push_back(matrix[t][col]);
            }
            // Traverse downwards.
            for (int row = t + 1; row <= b; row++) {
                result.push_back(matrix[row][r]);
            }
            // Make sure we are now on a different row.
            if (t != b) {
                // Traverse from right to left.
                for (int col = r - 1; col >= left; col--) {
                    result.push_back(matrix[b][col]);
                }
            }
            // Make sure we are now on a different column.
            if (left != r) {
                // Traverse upwards.
                for (int row = b - 1; row > t; row--) {
                    result.push_back(matrix[row][left]);
                }
            }
            left++;r--;t++;b--;
        }
        
        return result;
    }
        
};