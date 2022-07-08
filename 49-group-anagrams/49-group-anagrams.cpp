class Solution {
public:
    string generate_hash(string word) {
        
        string temp = word;
        sort(temp.begin(), temp.end());
        return temp;
        
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> hash_strings;
        
        
        for(auto word: strs)
        {
            string key = generate_hash(word);
            hash_strings[key].push_back(word);
        }
        
        vector<vector<string>> anagrams;
        
        for(auto i: hash_strings)
        {
            anagrams.push_back(i.second);
        }
        
        return anagrams;
    }
};