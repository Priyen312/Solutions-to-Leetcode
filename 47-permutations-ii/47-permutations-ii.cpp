class Solution {
public:
    void recursion(vector<int> num, int index, int size, vector<vector<int> > &res) {
        if (index == size) {
            res.push_back(num);
            return;
        }
        
        for (int k = index; k < size; k++) {
            
            if (index != k && num[index] == num[k]) 
                continue;
            swap(num[index], num[k]);
            
            recursion(num, index + 1, size, res);
        }
    }
    
    vector<vector<int> > permuteUnique(vector<int> &num) {
        
        sort(num.begin(), num.end());
        
        vector<vector<int> >res;
        
        recursion(num, 0, num.size(), res);
        
        return res;
    }
//     void generate_permutations(vector<int>& nums, vector<vector<int>> &permutations, int index)
//     {//This is like the Permutation I solution, but we use an unordered_set to avoid swapping elements that are the same (which would generate identical permutations).
//         if(index == nums.size())
//         {
//             permutations.push_back(nums);
//             return;
//         }
        
//        unordered_set<int> s;
        
//         for(int i = index; i < nums.size(); i++)
//         {
//             if(s.find(nums[i]) == s.end())// check if the number in the array has already been considered for the permutation
//             {
//                 s.insert(nums[i]);
                
//                 swap(nums[index], nums[i]);
//                 generate_permutations(nums, permutations, index + 1);
//                 swap(nums[index], nums[i]);
                
                
//             }
            
                       
//         }
//     }
//     vector<vector<int>> permuteUnique(vector<int>& nums) {
        
//         sort(nums.begin(), nums.end());
//         vector<vector<int>> permutations;
        
//         generate_permutations(nums, permutations, 0);
        
//         return permutations;
//     }
};