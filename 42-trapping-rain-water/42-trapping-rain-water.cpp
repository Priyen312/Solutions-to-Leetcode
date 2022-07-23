class Solution {
public:
//     int trap(const vector<int> &A) {
        
//         //For each element in the array, we find the maximum level of water it can trap after the rain, which is equal to the minimum of maximum height of bars on both the sides minus its own height.

//         if(A.size() == 0) return 0;


//         vector<int> l(A.size());

//         l[0] = A[0];
//         for(int i = 1; i < A.size() ; i++)
//         {
//             l[i] = max(A[i],l[i-1]);
//         }

//         vector<int> r(A.size());

//         r[A.size() - 1] = A[A.size() - 1];
//         for(int i = A.size() - 2 ; i>=0 ; i--)
//         {
//             r[i] = max(r[i + 1],A[i]);

//         }

//         int sum = 0;
//         for(int i = 1; i<A.size() - 1; i++)
//         {
//             sum += (min(l[i],r[i]) - A[i]);
//         }
        
//         return max(sum,0);

// }
    
    int trap(vector<int> &nums) {
        int leftmax = 0;
        int rightmax = 0;
        
        int l = 0, r = nums.size() -1, res = 0;
        
        while(l < r) {
            if(nums[l] < nums[r]) {
                if(nums[l] < leftmax) {
                    res += leftmax - nums[l];
                }
                else {
                    leftmax = nums[l];
                }
                l +=1;
                
            }
            else {
                if(nums[r] < rightmax) {
                    res += rightmax - nums[r];
                }
                else {
                    rightmax = nums[r];
                }
               
                r -=1;
                
            }
        }
        
        return res;
    }
};