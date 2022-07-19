class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() < b.size())
            return addBinary(b, a);
        string s = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int cy = 0;
        while(i >= 0 or j >= 0 or cy == 1)
        {
            int x = i >= 0 ? a[i] - '0' : 0;
            int y = j >= 0 ? b[j] - '0' : 0;
            
            cy += x + y;
            s = char(cy % 2 + '0') + s;
            cy = cy/2;
            i--;
            j--;
        }
        
        
        return s;
    }
};