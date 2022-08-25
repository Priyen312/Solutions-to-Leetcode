class Solution {
public:
    int stocks(int i, int buying, vector<int>& p, vector<vector<int>> &memo)
    {
        if(i >= p.size())
            return 0;
        
        if(memo[i][buying] != INT_MIN)
            return memo[i][buying];
        
        if(buying)
        {
            memo[i][buying] = max(stocks(i + 1, !buying, p, memo) - p[i], stocks(i + 1, buying, p, memo));
        }
        else
            memo[i][buying] = max(stocks(i + 2, !buying, p, memo) + p[i], stocks(i + 1, buying, p, memo));
        
        return memo[i][buying];
    }
    int maxProfit(vector<int>& p) {
       
        vector<vector<int>> memo(p.size() + 1, vector<int>(2, INT_MIN));
        return stocks(0, 1, p, memo);
        
    }
};