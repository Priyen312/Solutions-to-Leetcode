class Solution {
public:
    int myAtoi(string s) {
        
        
        int i = 0;
        int n = s.size();
        
        //whitespaces
        for(; i < n; i++)
        {
            if(s[i] != ' ')
                break;
        }
        
        
        //sign
        int sign = 1; 
        if (i < n && s[i] == '+') 
        {
            i++;
        } 
        else if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        
        //forming the integer
        int result = 0; 
        while (i < n && (s[i] >= '0' and s[i] <= '9')) 
        {
            int digit = s[i] - '0';

            //overflow 
            if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) 
            { 
                
                // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.    
                if(sign == 1)
                {
                    return INT_MAX;
                }
                else if(sign == -1)
                    return INT_MIN;
                
            }
            
            
            result = 10 * result + digit;
            i++;
        }
        
        // We have formed a valid number without any overflow/underflow.
        // Return it after multiplying it with its sign.
        return sign * result;
    }
};