class Solution {
public:
    
    int usingsorting(vector<int> &nums){
        
        //sorting the input array (O(nlog(n))), (O(1))
        int n = 1;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)
            
        {
            if(nums[i] == n)
            {
                n++;
            }
            if(nums[i] > n)
            {
                return n;
            }
            
        }
        
        return n;
        
        
    }
    
    int usingmaps(vector<int> &nums){
        
        //using maps(O(n)), (O(n))
        int n = 1; 
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++)
        {
            m[nums[i]]++;
        }
        
        for(int i = 1; i < nums.size() + 1; i++)
        {
            if(m.find(n) == m.end())
                return n;
            else
                n++;
        }
        
        return n;
    }
    
    int firstMissingPositive(vector<int>& nums) {
        
         for(int i = 0; i < nums.size(); i++)
         {
            if(nums[i] <= 0)
                nums[i] =  nums.size() + 1;
         }
    
        for(int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1;
            
            if(index >= 0 and index <nums.size())
            {
                if(nums[index] > 0)
                {
                    nums[index] *= -1;
                }   
            }

        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > 0)
                return i + 1;
        }
        
        return nums.size() + 1;

    }
    
};