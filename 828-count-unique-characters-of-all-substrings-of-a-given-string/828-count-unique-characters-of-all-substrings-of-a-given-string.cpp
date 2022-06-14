class Solution {
public:
    int uniqueLetterString(string s) {
        
        int sum = 0;
        int n = s.size();
        unordered_map<char, vector<int>> indices;
        
        for(int i = 0; i < n; i++)
        {
            indices[s[i]].push_back(i);
        }
        
        for(auto i : indices)
        {
            vector<int> index = i.second;
            int m = index.size();
            for(int i = 0; i < index.size(); i++)
            {
                int l = i == 0 ? index[i] + 1 : index[i] - index[i - 1];
                int r = (i == (m - 1)) ? s.size() - index[i] : index[i + 1] - index[i];
                
                sum += l * r; 
                
            }    
            
            
        }
        
        return sum;
    }
};