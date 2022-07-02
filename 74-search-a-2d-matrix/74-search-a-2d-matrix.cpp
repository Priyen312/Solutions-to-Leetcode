class Solution {
public:
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int row = 0, col = n - 1;
        
        while(row < m and col > -1)
        {
            if(matrix[row][col] == target)
                return true;
            if(matrix[row][col] > target) // traverse left subtree, meaning stay in same row and decrease col
                col--;
            else
                row++;
        }
        
        return false;
    }
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
  
    
//          int row = matrix.size();
//         int column = matrix[0].size();
//                    int left =0;
//         int right = row*column -1;
//                    while(left<=right)
//                    {
//                         int mid = (left+right)/2;
                        
//                        if(matrix[mid/column][mid%column] <target)
//                        {
//                            left = mid+1;
//                        }
//                        else if(matrix[mid/column][mid%column] >target)
//                        {
//                            right = mid-1;
//                        }
//                        else
//                        {
//                            return true;
//                        }
//                    }
                   
//                    return false;
        
//         }
};