class Solution {
public:
    int trap(const vector<int> &A) {
    if(A.size() == 0) return 0;
    vector<int> l(A.size());
    
    l[0] = A[0];
    
    for(int i =1; i<A.size() ; i++)
    {
        
        l[i] = max(A[i],l[i-1]);
    }
    vector<int> r(A.size());
    
    r[A.size() - 1] = A[A.size() - 1];
for(int i =A.size() - 2 ; i>=0 ; i--)
    {
        r[i] = max(r[i + 1],A[i]);
        
    }
   
        int sum = 0;
        for(int i = 1; i<A.size() - 1; i++)
        {
            sum = sum + (min(l[i],r[i]) - A[i]);
        }
return max(sum,0);

}
};