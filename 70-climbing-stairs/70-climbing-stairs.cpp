class Solution {
public:
    map<int,int> memo;
    int dfs(int n, int step)
    {
        if(memo[step])
            return memo[step];
        if(step == n)
            return 1;
        
        if(step >n)
            return 0;
        
        return memo[step] = (dfs(n, step + 1) + dfs(n,step + 2));
    }
    int climbStairs(int n) {
        return dfs(n, 0);
    }
};