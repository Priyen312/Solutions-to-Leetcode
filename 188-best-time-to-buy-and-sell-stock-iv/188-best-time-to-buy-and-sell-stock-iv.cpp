class Solution {
public:
    map<pair<int, pair<int, int>>, int> memo;
    int profit(int index, int k, vector<int> &prices, int can_buy)
    {
        if(index == prices.size() or k == 0)
            return 0;
        if(memo.find({index, {k, can_buy}}) != memo.end())
        {
            return memo[{index, {k, can_buy}}];
        }
        if(can_buy)
        {
            return 
                memo[{index, {k, can_buy}}] = 
                max(-1 * prices[index] + profit(index + 1, k, prices, 0), profit(index + 1, k, prices, 1));
        }
        else
        {
            return memo[{index, {k, can_buy}}] = 
                max(prices[index] + profit(index + 1, k - 1, prices, 1), profit(index + 1, k, prices, 0));
        }
        
        return 0;
    }
    int maxProfit(int k, vector<int>& prices) {
        return profit(0, k, prices, 1);
    }
};