class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(auto i :s)
        {
            m[i]++;
        }
        sort(s.begin(), s.end(), [&] (char x, char y) {
            return (m[x] > m[y] | (m[x] == m[y] and x < y));
        });
        
        return s;
        
    }
};