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
class Node {
    public:
    
    int val;
    int minimum;
    Node *next;
    
    Node(int val, int minimum = INT_MAX, Node *next = nullptr)
    {
        this->val = val;
        this->minimum = minimum;
        
        this->next = next;
    }
};
class MinStack {
public:
   
    Node* curr;
    
    void push(int x) {
        if (curr == nullptr){// if the stack is empty
            curr = new Node(x, x, nullptr);
        }
        else
        {
            curr = new Node(x, min(x, curr->minimum), curr);
            
        }
    }

    void pop() {
        if(curr == nullptr)
            return;
        curr = curr->next;
    }

    int top() {
        return curr->val;
    }

   int getMin() {
        return curr->minimum;
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