class Solution {
public:

//     bool get_sum(vector<int> &nums, int target, int index, vector<vector<int>> &memo)
//     {
//         if(target == 0)
//             return true;
        
//         if(target != 0 and index == 0)
//             return false;
        
//         if(memo[index][target] != -1)
//             memo[index][target];
        
//         if(nums[index - 1] > target)
//            return get_sum(nums, target, index - 1, memo);
    
//          return memo[index][target] = get_sum(nums, target - nums[index - 1], index - 1, memo) | get_sum(nums, target, index - 1, memo);
//     }
//     bool canPartition(vector<int>& nums) {
        
        
//         int n = nums.size();
//         int sum = 0;
//         for(int i = 0; i < n; i++)
//         {
//             sum += nums[i];
//         }
        
//         if(sum%2 == 1)
//             return false;
        
        
        
//         vector<vector<int>> memo(n + 1, vector<int> (sum + 1, -1));
        
//         return get_sum(nums, sum / 2, n, memo);
        
//     }
    bool canPartition(vector<int>& arr)
{
    int n = arr.size();
    
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
 
   
    if (sum % 2 != 0)
        return false;
 
    
    vector<vector<int> > dp(n + 1,
                            vector<int>(sum + 1, -1));
    
    
   
    return isSubsetSum(arr, n, sum / 2, dp);
}
    
bool isSubsetSum(vector<int>& arr, int n, int sum,
                 vector<vector<int> >& dp)
{
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0 && sum != 0)
        return false;
 
    
    if (dp[n][sum] != -1) {
        return dp[n][sum];
    }
 
    
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum, dp);
 
    
    return dp[n][sum]
           = isSubsetSum(arr, n - 1, sum, dp)
             || isSubsetSum(arr, n - 1, sum - arr[n - 1],
                            dp);
}
 


};