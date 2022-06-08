class Solution {
public:
    int jump(vector<int>& A) {
        //The main idea is based on greedy. Let's say the range of the current jump is [curBegin, curEnd], curFarthest is the farthest point that all points in [curBegin, curEnd] can reach. Once the current point reaches curEnd, then trigger another jump, and set the new curEnd with curFarthest, 
        
        int start_to_see = 0;
        int jumps = 0;
        int farthest = 0;
        if(A.size() == 0)
            return -1;
        if(A.size() == 1)
            return 0;
        if(A[0] == 0)
            return -1;
        // i always want to jump to the node that has the highest value within my range
        for(int i = 0; i < A.size() - 1; i++)
        {
            farthest = max(farthest, i + A[i]);
                                               

            if(i == start_to_see)
            {
                jumps++;
                start_to_see = farthest;
                if(start_to_see == A.size() - 1)
                    return jumps;
            }
        }

        return jumps;
    }
              
};