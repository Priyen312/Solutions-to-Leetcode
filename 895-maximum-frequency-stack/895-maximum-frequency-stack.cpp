class FreqStack {
public:
    unordered_map<int, int> c;
    unordered_map<int, stack<int>> group;
    int max_f = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        c[val]++;
        int curr_f = c[val];
        
        max_f = max(curr_f, max_f);
        
        
        group[curr_f].push(val);
    }
    
    int pop() {
        int ans = group[max_f].top();
        group[max_f].pop();
        c[ans]--;
        
        if(group[max_f].size() == 0)
            max_f--;
        
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */