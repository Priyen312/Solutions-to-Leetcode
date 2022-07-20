class Solution {
public:
    
   
    int lengthOfLIS(vector<int>& nums) {
        //O(nlogn), O(n)
        vector<int> sub;
        for (int x : nums) {
            if (sub.empty() || sub[sub.size() - 1] < x) {
                sub.push_back(x);
            } else {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x; // Replace that number with x
            }
        }
        return sub.size();
    }
//     int lengthOfLIS(vector<int>& nums) {
//         //Formally, the length of the longest increasing subsequence ending at index i, will be 1 greater than the maximum of lengths of all longest increasing subsequences ending at indices before i
        
//         vector<int>lis(nums.size(), 1); // every index is a lis of 1
        
//         for(int i = 0; i < nums.size(); i++)
//         {
//             for(int j = 0; j <= i; j++)
//             {
//                 if(nums[i] > nums[j]) // if i am greater than any previous value
//                 {
//                     //then my lis is his lis + 1. the maximum from all the previous values will give the answer
//                     {
//                         lis[i] = max(lis[j] + 1, lis[i]);
                        
//                     }
//                 }
//             }
            
            
//         }
        
//         return *max_element(lis.begin(), lis.end());
//     }
};