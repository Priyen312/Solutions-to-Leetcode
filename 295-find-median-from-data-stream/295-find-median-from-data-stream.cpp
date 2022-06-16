class MedianFinder {
public:
    priority_queue<long> small;
    priority_queue<long, vector<long>, greater<long>> large;
    MedianFinder() {
        
    }
    //small -- 2 3
    //large -- 4
    void addNum(int num) {
        small.push(num);
        large.push(small.top());
        small.pop();
        
        if(small.size() < large.size())
        {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        return small.size() > large.size() ? small.top(): (small.top() + large.top())/2.0;
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */