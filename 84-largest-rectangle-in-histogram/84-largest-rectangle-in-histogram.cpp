class Solution {
public:
    
        int largestRectangleArea(vector<int>& A) {
    stack<pair<int,int>> stack;
    int index;
    int largestArea = -1;
    stack.push({-1,0});
    //the stack will only have values in increasing order
    for(int i = 0; i<A.size(); i++)
    {
        if(A[i] >= stack.top().second)
        {
            stack.push({i,A[i]});
        }

        else
        {//keep popping and calculating max area until stack has a place for current value
           
                while(stack.top().second > A[i])
                {
                          pair<int, int> bar = stack.top();
                    index = bar.first;
            stack.pop();
            largestArea = max(largestArea, (bar.second*(i-stack.top().first - 1)));
                }

            stack.push({i,A[i]});
            
        }

    }
        int size = A.size();
            //finally increasing ordered
            while(stack.top().first!=-1)
            {
               pair<int, int> bar = stack.top();
            stack.pop();
            largestArea = max(largestArea, (int)(bar.second*(size-stack.top().first - 1)));
            }
        return largestArea;
    }
};