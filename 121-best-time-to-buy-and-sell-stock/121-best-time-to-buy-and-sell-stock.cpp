class Solution {
public:
    int maxProfit(vector<int>& prices) {
//         int profit = 0;
//         int min = prices[0];
//         int profit_sofar = 0;
        
//         for(int i=1;i<prices.size();i++)
//         {
//             profit_sofar = prices[i] - min;
            
//              if(profit_sofar < 0)
//             {
//                 profit_sofar = 0;
//                 min = prices[i];
//             }
            
//             if(profit_sofar >profit)
//             {
//                 profit = profit_sofar;
//             }
            
           
            
            
//         }
        
//         return profit;
        
        int min_buy = INT_MAX;
        int max_profit = 0;
	
	
        for(int i = 0; i< prices.size(); i++)
        {
            min_buy = min(prices[i], min_buy);
            max_profit = max(max_profit, prices[i] - min_buy);
        }

        return max_profit;
       

        
    }
};