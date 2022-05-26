class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
//       if(nums.size() == 1 && nums[0] == 1)
//           return (nums[0] + 1);
//         if(nums.size() == 1)
//             return 1;
//         int n = nums.size();
//         vector<int> A = nums;
//    int i = 0;while( i < n){
//             if(A[i] > 0 && A[i] <= n && A[A[i] - 1] != A[i])
//                 swap(A[i], A[A[i] - 1]);
//         else
//             ++ i;}
//         for(int i = 0; i < n; ++ i)
//             if(A[i] != i + 1)
//                 return i + 1;
        
//         return n + 1;
        
        int n = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            
        {
            if(nums[i] == n)
            {
                n++;
            }
            
        }
        
        return n;
    }
    
};