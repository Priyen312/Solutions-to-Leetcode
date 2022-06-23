class Solution {
public:
    int h(vector<int>& nums, int target,unordered_map<int,int>& memo ) {
    
        if(memo.find(target) != memo.end()) return memo[target];
        if( target == 0) {return 1;}
        if( target <  0) {return 0;}
        int count  = 0;
        for (auto n : nums)
        {
            count += h(nums, target - n, memo);            
        }
     
       
        
        return memo[target] = count;
   
    }
        
      int combinationSum4(vector<int>& nums, int target ) {
            
            unordered_map<int,int> memo;
          
            sort(nums.begin(), nums.end());
            
            return h(nums, target,memo); 
      
   
    }
    
    
  
        
};