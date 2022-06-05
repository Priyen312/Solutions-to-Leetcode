class Solution {
public:
    
struct Key {
    int freq; 
    char ch;
 
   
    bool operator<(const Key& k) const
    {
        return freq < k.freq;
    }
};
 

    string reorganizeString(string s) {
        
    int n = s.length();
 
    
    int count[26] = { 0 };
    for (int i = 0; i < n; i++)
        count[s[i] - 'a']++;
 
    
    priority_queue<Key> pq;
    for (char c = 'a'; c <= 'z'; c++) {
          int val = c - 'a';
        if (count[val]) {
            pq.push(Key{ count[val], c });
        }
    }
 
    
    string str = "";
 
    // work as the previous visited element
    // initial previous element be. ( '#' and
    // it's frequency '-1' )
    Key prev{ -1, '#' };
 
    // traverse queue
    while (!pq.empty()) {
        
        Key k = pq.top();
        pq.pop();
        str = str + k.ch;
 
        // IF frequency of previous character is less
        // than zero that means it is useless, we
        // need not to push it
        if (prev.freq > 0)
            pq.push(prev);
 
        // decrease frequency by 'one'
        
        
        (k.freq)--;
        
        // make current character as the previous 'char'
        prev = k;
    }
 
    // If length of the resultant string and original
    // string is not same then string is not valid
    if (n != str.length())
        return "";
 
    else return str;
}
        
    
};