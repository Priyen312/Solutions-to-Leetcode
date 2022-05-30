class Solution {
public:
    
//     bool dfs(vector<int> &nums, int i, int sum, int count)
//     {
//         if(sum == 0 and count == 0)
//             return true;
//         if(i >= nums.size() or sum < 0)
//             return false;
        
//             return (dfs(nums, i + 1, sum - nums[i], count - 1)) |
//                 (dfs(nums, i + 1, sum, count));
            
//     }
//     bool splitArraySameAverage(vector<int>& nums) {
        
//         int sum = 0;
//         for(auto num: nums)
//             sum += num;
        
//         // sum/ nums.size() = sum1/ i
//         for(int i = 0; i < nums.size() - 1; i++)
//         {
//             if((sum * (i + 1)) % nums.size() == 0)// meaning division leads to an integer
//             {
//                 int s1 = (sum * (i + 1)) / nums.size();
                
                
                
//                 if(dfs(nums, 0, s1, i + 1))
//                 {
//                     return true;
//                 }
//             }
             
//         }
        
//         return false;
//     }
    //MEMOIZATION
    bool dfs(vector<int> &nums, int i, int sum, int count,  vector<vector<vector< bool>>> &memo)
    {
        if(count == 0)
            return sum == 0;
        if(i >= nums.size() or sum < 0)
            return false;
        
        if(memo[i][count][sum] == false)
            return memo[i][count][sum];
        
            return memo[i][count][sum] = (dfs(nums, i + 1, sum - nums[i], count - 1, memo)) |
                (dfs(nums, i + 1, sum, count, memo));
            
    }
    bool splitArraySameAverage(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(auto num: nums)
            sum += num;
        int n = nums.size();
        vector < vector < vector < bool >>> memo(n, vector < vector < bool >> (n, vector < bool > (sum + 1, true)));
        
        
        // sum/ nums.size() = sum1/ i
        for(int i = 0; i < nums.size() - 1; i++) 
        {
            if((sum * (i + 1)) % nums.size() == 0)// meaning division leads to an integer
            {
                int s1 = (sum * (i + 1)) / nums.size();
                
                
                
                if(dfs(nums, 0, s1, i + 1, memo))
                {
                    return true;
                }
            }
             
        }
        
        return false;
    }
    
// bool isPossible(int idx, int size, int sum, vector < int > & A, vector < int > & A1, vector < vector < vector < bool >>> & dp) {
//   //base cases
//   if (size == 0)
//     return sum == 0;
//   if (idx == A.size())
//     return false;
//   //The very first time we get a solution we exit. So calcuations are getting repeated for false cases. So we check if (idx,size,sum) has already been
//   //calculated i.e been set to false. If yes, return else calculate save and return.
//   if (dp[idx][size][sum] == false)
//     return dp[idx][size][sum];
//   if (A[idx] <= sum) {
//     //option1:use idx th element
//     A1.push_back(A[idx]);
//     if (isPossible(idx + 1, size - 1, sum - A[idx], A, A1, dp))
//       return true;
//     A1.pop_back();
//     //this can also be done since A[idx]> sum so there's no point going any further since A is sorted
//     // if(isPossible(idx+1,size,sum,A,A1,dp))
//     // return true;
//   }
//   if (isPossible(idx + 1, size, sum, A, A1, dp))
//     return true;
//   return dp[idx][size][sum] = false;
// }
// bool splitArraySameAverage(vector < int > & A) {
//   sort(A.begin(), A.end());
//   int n = A.size();
//   int s = 0;
//   for (int num: A)
//     s += num;
//   vector < vector < vector < bool >>> dp(n, vector < vector < bool >> (n, vector < bool > (s + 1, true)));
//   // dp[i][j][k] tells if in A[i...n-1],there exists a subset of length j with sum k
//   vector < vector < int >> ans;
//   // subset1:sum=s1 size=n1 subset2:sum=s2 size=n2 For equal average partition:s1/n1==s2/n2 which leads to s1=(n1*s)/n
//   //size of 1st subset can be from 1 to (n-1)(since both subsets need to be non-empty). if for a given n1, s1 comes out to be decimal we can straight away say that we can't find sum s1 in A
//   for (int n1 = 1; n1 < n; n1++) {
//     if ((n1 * s) % n == 0) {
//       int s1 = (n1 * s) / n;
//       vector < int > A1;
//       if (isPossible(0, n1, s1, A, A1, dp)) {
       
//           return true;
//         //The way we generated subset1, it will follow all the ordering constraints given in the question. So we dont really need to sort.
//         // sort(ans.begin(),ans.end(),customComp);
        
//       }
//     }
//   }
//     return false;
   
// }
};