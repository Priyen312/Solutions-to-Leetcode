class RandomizedCollection {
  vector<int> nums;
  unordered_map<int, unordered_set<int>> m;
    
public:
    bool insert(int val) {

        nums.push_back(val);
        m[val].insert(nums.size() - 1);

        return m[val].size() == 1;
        
    }
    
    
    
    bool remove(int val) {
        
        auto it = m.find(val);
        
        if (it != end(m)) {
            
            auto free_pos = *it->second.begin();
            it->second.erase(it->second.begin());
            
            
            nums[free_pos] = nums.back();
            m[nums.back()].insert(free_pos);
            m[nums.back()].erase(nums.size() - 1);
            nums.pop_back();
            
            
            if (it->second.size() == 0) 
                m.erase(it);
            return true;
        }
        
        return false;
  }
  int getRandom() {
      return nums[rand() % nums.size()]; 
  }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */