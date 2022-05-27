/*class MinStack {
public:
  
   
    
       
          stack <int> s;
       
        int min = INT_MAX;
        
          void push(int val) {
     if(s.empty())
     {
         min = val;
         s.push(val);
     }
              if(val<min)
              {
                  s.push(2*val - min);
                  min = val;
                  
              }
              else
              {
                  s.push(val);
              }
                  
        
             }
    
    void pop() {
        if (s.empty())
        {
            cout << "Stack is empty\n";
            return;
        }
       
        int t = s.top();
        s.pop();

       
        if (t < min)
        {
            cout << min << "\n";
            min = 2*min - t;
        }

        else
            cout << t << "\n";
    }

      

        
            
       
    
    
    int top() {
        int t = s.top(); // Top element.

        

         t = (t < min)? min: t;
        return t;
    }
    
    int getMin() {
        
        return min;
    }
    
  
    
};
*/
class MinStack {
public:
long min;
    stack<long> s;

   
    
    void push(int x) {
        if (s.size() == 0){
            s.push(-1);
            min=x;
        }else{
            s.push(x-min);//Could be negative if min value needs to change
            if (x<min) min=x;
        }
    }

    void pop() {
        if (s.size() == 0) return;
        
        long p=s.top();s.pop();
        
        if (p<0)  min=min-p;//If negative, increase the min value
        
    }

    int top() {
        long tp=s.top();
        if (tp>0){
            return (int)(tp+min);
        }else{
           return (int)(min);
        }
    }

   int getMin() {
        return (int)min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */