class RandomizedCollection {
private:
    vector<pair<int, int>> nums;
    unordered_map<int, vector<int>> m;
public:
    RandomizedCollection() {
        
    }
    


    bool insert(int val) {
        bool not_present = m.find(val) == m.end();
        
        m[val].push_back(nums.size()); // pushing the new index to the map
        
        nums.push_back({val, m[val].size() - 1}); //pushing the number and it's corresponding index to the list
        
        return not_present;
    }
    
    bool remove(int val) {
        
        auto present = m.find(val) != m.end();
        
        if(present)
        {
            auto [value, index] = nums.back(); //[value, index]
            
            m[value][index] = m[val].back(); // change the last element's index
            
            nums[m[val].back()] = {value, index}; // overwrite the 'to be removed element' with [value, index]
            
            m[val].pop_back(); // remove the last index of the 'value to be removed'
            
            if(m[val].empty()) // remove from map if totally removed from nums
                m.erase(val);
            
            nums.pop_back(); // delete the last element as it is now a redundance
        }
        return present;
        
    }
    
    int getRandom() {
        return nums[rand() % nums.size()].first;
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */