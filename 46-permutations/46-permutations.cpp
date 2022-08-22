class Solution {
public:
//     void find_permutations(vector<int>& nums, vector<vector<int>> &permutations, int index)
//     {//https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
//         // O(n*n!)
//         if(index == nums.size())
//         {
//             permutations.push_back(nums);
//             return;
//         }
        
//         for(int i = index; i < nums.size(); i++)
//         {
//             swap(nums[index], nums[i]);
            
//             find_permutations(nums, permutations, index + 1);
            
//             swap(nums[index], nums[i]);
//         }
        
        
        
//     }
    
//     vector<vector<int>> permute(vector<int>& nums) {
        
//         vector<vector<int>> permutations;
        
        
//         find_permutations(nums, permutations, 0);
        
//         return permutations;
//     }
    
    void backtrack(vector<int> comb, int N, unordered_map<int, int> counter, vector<vector<int>> &results) {

        if (comb.size() == N) {
            results.push_back(comb);
            return;
        }

        for(auto [num, count]: counter)
        {
            
            
            if(count == 0)
                continue;
            
            comb.push_back(num);
            counter[num] = count - 1;
            
            backtrack(comb, N, counter, results);
            
            comb.pop_back();
            counter[num] = count;
                
        }
        
            
    }
    
     vector<vector<int>> permute(vector <int> nums) {
        vector<vector<int>> results;

        
        unordered_map<int, int> counter;
        
         for (int num : nums) {
            counter[num]++;
        }

        vector<int> comb;
        backtrack(comb, nums.size(), counter, results);
        return results;
    }
    
    
//                                                       ABC
//         ABC [swap A, A]                          BAC [swap A, B]                      CBA [swap A, C]
//             A is fixed                             B is fixed                           C is fixed
// ABC [swap B, B]   ACB [swap B, C]       BAC [swap A, A]   BCA [swap A, C]      CBA [swap B, B]    CAB [swap B, A]
};