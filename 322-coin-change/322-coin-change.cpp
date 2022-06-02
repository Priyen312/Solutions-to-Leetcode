class Solution {
public:
    int find_denominations(vector<int> &coins, int amount, int index, long long denominations, vector<vector<int>> &memo)
    {
        if(denominations == amount)
            return 0;
        if(denominations > amount or index == coins.size())
            return INT_MAX - 1;
        if(memo[denominations][index] != -1)
            return memo[denominations][index];
        
        return memo[denominations][index] = min(1 + find_denominations(coins, amount, index, denominations + coins[index], memo), 
                   find_denominations(coins, amount, index + 1, denominations, memo));
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> memo(amount + 1, vector<int> (coins.size(), -1));
        
        int no_coins = find_denominations(coins, amount, 0, 0, memo);
        return no_coins == INT_MAX - 1 ? -1 : no_coins;
        
    }
};