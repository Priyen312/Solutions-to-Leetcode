class Solution {
public:
    bool flush(vector<char>& suits) {
        for(int i = 0; i < 4; i++) {
            if(suits[i] != suits[i + 1])
                return false;
        }
        
        return true;
    }
    
    bool threeAKind(vector<int>& ranks) {
        unordered_map<int, int> mappings;
        for(int i = 0; i < 5; i++) {
            mappings[ranks[i]]++;
            if(mappings[ranks[i]] == 3)
                return true;
        }
        
        return false;
    }
    
    bool pair(vector<int>& ranks) {
        unordered_map<int, int> mappings;
        for(int i = 0; i < 5; i++) {
            mappings[ranks[i]]++;
            if(mappings[ranks[i]] == 2)
                return true;
        }
        
        return false;
    }
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        
        //flush
        if(flush(suits))
            return "Flush";
        else if(threeAKind(ranks))
            return "Three of a Kind";
        else if(pair(ranks))
            return "Pair";
        else
            return "High Card";
        
        //three of a kind
        
        
        
        
        
    }
};