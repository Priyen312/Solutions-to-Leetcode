class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
       
        int fruit1 = 0, fruit2 = 0;
        int type1 = -1, type2 = -1;
        
        int current_max = 0;
        int maximum = 0;
        
        
       
        
        
        
        
        for(int r = 0; r < fruits.size(); r++)
        {
            
            int current_type = fruits[r];
            if(current_type == type1 || current_type == type2)//check if the current fruit is in the bastket
            {
                current_max++;
            }
            else// if not, then the fruit just before the current fruit is kept and the current fruit is also kept
            {
                current_max = fruit2 + 1;
            }
            
            if(current_type == type2)// if the current fruit is the last fruit in the bag then increase its count
            {
                fruit2++;
            }
            else// else it is already in bag or a new fruit, either way make the count of last seen fruit as 1
            {
                fruit2 = 1;
            }
            
            if(current_type != type2)// if the new fruit that was seen wasn't the last seen fruit then it either is a new fruit or a fruit from the other basket, either way we change the values
            {
                type1 = type2;
                type2 = current_type;
                
                
            }
               
            
            maximum = max(maximum, current_max);
            
        }
        return maximum;
    }
};