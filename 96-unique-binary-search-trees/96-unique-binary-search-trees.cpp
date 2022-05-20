class Solution {
public:
//     int numTrees(int n) {
//         vector<int> memo(n + 1, 1);
        
//         for(int i = 2; i<= n; i++)
//         {
//             int total = 0;
//             for(int root = 1 ;root <= i; root++)
//             {
//                 int left = root - 1;
//                 int right = i - root;
//                 total += memo[left] * memo[right];
//             }
            
//             memo[i] = total;
//         }
        
//         return memo[n];
//     }
    int helper(int n, vector<int> &memo)
    {
        if(n <= 1)
            return 1;
        
        if(memo[n]!= -1)
            return memo[n];
        
        
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            ans += helper(i-1, memo) * helper(n - i, memo);
        }
        
        return memo[n] = ans;
    }
        
    int numTrees(int n){
        vector<int> memo(n+1, -1);
        return helper(n, memo);
    }
};