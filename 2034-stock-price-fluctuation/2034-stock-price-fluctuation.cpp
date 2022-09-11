class StockPrice {
public:
    unordered_map<int, int> m;
    multiset<int> timeline;
    int curr_timestamp = 0, curr_price = 0;
    
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        
        if(m.find(timestamp) != m.end())
        {
            timeline.erase(timeline.find(m[timestamp]));
        }
        
        m[timestamp] = price;
        timeline.insert(price);
        
        if(curr_timestamp <= timestamp)
        {
            curr_timestamp = timestamp;
            curr_price = price;
        }
    }
    
    int current() {
        return curr_price;
    }
    
    int maximum() {
        return *rbegin(timeline);
    }
    
    int minimum() {
        return *begin(timeline);
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */