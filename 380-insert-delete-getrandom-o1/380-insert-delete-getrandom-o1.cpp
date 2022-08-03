class RandomizedSet {
private:
    vector<int> nums;
    unordered_map <int, int> s;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool b =false;
        if (s.find(val) == s.end())
            b = true;
        nums.push_back(val);
        s[val] = nums.size() - 1;
        
        return b;
    }
    
    bool remove(int val) {// overwriting the last element to the removing index and then deleting last element from the list, changing the index of last in the map
        
        if(s.find(val) == s.end())
            return false;
        
        int last_element = nums.back();
        int new_index = s[val];
        int overwrite_index = s[val];
        nums[overwrite_index] = last_element;
        s[last_element] = new_index;
        
        nums.pop_back();
        s.erase(val);
        
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */