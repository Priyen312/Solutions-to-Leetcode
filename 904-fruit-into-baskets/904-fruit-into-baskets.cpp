class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
       
        int last_fruit = -1, second_last_fruit = -1;
        int last_fruit_count = 0;
        
        int curr_maximum = 0;
        int maximum = 0;
        
        for(auto curr_fruit : fruits)
        {
            if(curr_fruit == last_fruit | curr_fruit == second_last_fruit)
            {
                curr_maximum++;
            }
            
            else
            {
                curr_maximum = last_fruit_count + 1;
                                
            }
            
            if(curr_fruit == last_fruit)
            {
                last_fruit_count++;
            }
            else
            {
                last_fruit_count = 1;
            }
               
            if(curr_fruit != last_fruit)
            {
                second_last_fruit = last_fruit;
                last_fruit = curr_fruit;
            }
            maximum = max(maximum, curr_maximum);
            
        }
        return maximum;
    }
};