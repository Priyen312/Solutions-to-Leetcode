class Solution {
public:
    int jump(vector<int>& A) {
        int current = 0;
        int jumps = 0;
        int farthest = 0;
        if(A.size() == 0)
            return -1;
        if(A.size() == 1)
            return 0;
        if(A[0] == 0)
            return -1;
        for(int i = 0; i < A.size() - 1; i++)
        {
            farthest = max(farthest, i + A[i]);

            if(i == current)
            {
                jumps++;
                current = farthest;
            }
        }

        return jumps;
    }
};