class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2 == 1)
            return {};
        
        long long total_sum = 0;
        vector<long long> finalSplit;
        long long counter = 2;
        
        while(total_sum + counter <= finalSum)
        {
            finalSplit.push_back(counter);
            total_sum += counter;
            counter += 2;
        }
        
        finalSplit[finalSplit.size() - 1] += finalSum - total_sum;
        
        return finalSplit;
    }
};