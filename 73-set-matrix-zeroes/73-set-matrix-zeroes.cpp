class Solution {
public:
    bool firstRowZero(vector<vector<int>>& nums)
    {
        int m = nums[0].size();
        for(int i = 0; i < m; i++)
        {
            if(nums[0][i] == 0)
                return true;
        }
        
        return false;
    }
    
    bool firstColumnZero(vector<vector<int>>& nums)
    {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            if(nums[i][0] == 0)
                return true;
        }
        
        return false;
    }
    void setZeroes(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        
        bool make_first_row_zero = firstRowZero(nums);
        bool make_first_column_zero = firstColumnZero(nums);
        if(n == 0 or m == 0)
            return;
        
        for(int i = 1; i < n; i++)
        {
          for(int j = 1; j < m; j++)
          {
              if(nums[i][j] == 0)
              {
                  nums[i][0] = 0;
                  nums[0][j] = 0;
              }
          }
        }
        
        
        for(int i = 1; i < n; i++)
        {
          for(int j = 1; j < m; j++)
          {
              if(nums[i][0] == 0 || nums[0][j] == 0)
              {
                  nums[i][j] = 0;
              }
          }
        }
        
        if(make_first_row_zero == true)
        {
            for(int i = 0; i < m; i++)
            {
                nums[0][i] = 0;
            }
        }
        
        if(make_first_column_zero == true)
        {
            for(int i = 0; i < n; i++)
            {
                nums[i][0] = 0;
            }
        }  
    }
};