class Solution {
public:
    string getPermutation(int n , int k) {
        
        string unused = "";int i;
      
        vector<int> v(n);int f = 1;
        for(i = 1; i<=n ; i++)
        {
            unused = unused + to_string(i);
            f = f * i;
            v[i-1] = f;
          
          
        }
        k--;
        i = 0;
        string permutation = "";
        
        while(n>0)
        {   
           
           
            int part_length = v[v.size()-1]/(n);
            v.pop_back();
            
            i = k/part_length;
            
            permutation = permutation + unused[i];
            unused = unused.substr(0,i) + unused.substr(i+1);
            cout<<unused;
            n--;
            k = k%part_length;
            
        }
        
        return permutation;
    }
};