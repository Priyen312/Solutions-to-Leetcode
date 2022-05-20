class Solution {
public:
    bool isValid(string s) {
        {
	stack<char  > stack;
	for (char c : s) {
		if (c == '(')
			stack.push(')');
		else if (c == '{')
			stack.push('}');
		else if (c == '[')
			
            stack.push(']');
		 else
        {
            if(!stack.empty())
            {if(c == stack.top())
            {
                stack.pop();
            }
            else
             return false;} 
            else
            {
                return false;
            }
            
        }
	}
	return stack.empty();
}
        
    }
};