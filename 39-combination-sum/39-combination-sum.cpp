class Solution {
public:
    vector<int> emp;vector<vector<int>> emp1; vector<int> empty;
    
   void getAllCombinationsUtil(vector<int> a, int sum, int currIndex, vector<vector<int>> &result, vector<int> &curr) {
        if (sum == 0) {
            result.push_back(curr);
            return;
        } 
        else if (sum < 0 || currIndex == a.size()) {
            return;
        } 
       
       else {
            curr.push_back(a[currIndex]);
            getAllCombinationsUtil(a, sum - a[currIndex], currIndex, result, curr);
            curr.pop_back();
            getAllCombinationsUtil(a, sum, currIndex + 1, result, curr);
        }
}
        
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> curr;
        
        getAllCombinationsUtil(candidates,target,0,result,curr);
        return result;
        
    }
    
    
};