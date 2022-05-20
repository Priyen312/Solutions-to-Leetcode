class Solution {
public:
    int lengthOfLastWord(string A) {//Solution is right test case is wrong
    int start = 0,end = 0,spaces = 0;
    int l = 0;
    int e = A.size();
    for(int g=0;g<A.size(); g++)
    {
        if(A[g]!=' ')
            {l = g;break;}
    }
        
        for(int i = A.size()-1; i>=0;i--)
        {
            if(A[i]!=' ')
               { e = i;break;}
        }
    for(int x = l; x <=e; x++)
    {
        if(A[x] == ' ')
        {
            start = x;
            spaces++;
        }
    }

    if(spaces >= 1)
    {
        return (e - (start));
    }

    return e-l+1;
}
};