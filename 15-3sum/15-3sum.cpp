class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &A) {
    // add your logic here
	vector<vector<int>> v;
	sort(A.begin(),A.end());
        int n = A.size();
	int i = 0, l = 0, r = 0, target = 0;
	for(i = 0 ; i<A.size(); i++)
		{
        if ((i>0) && (A[i]==A[i-1]))
            continue;
        target = 0 - A[i];
		 	l = i+1;
		 	r = n - 1;
			
			while(l<r)
				{
                
					if((A[l] + A[r]) >  target) r--;
					else if((A[l] + A[r]) < target) l++;
					else
						{v.push_back({A[i], A[l] , A[r]}); 
                        
                         while ( l < r && A[l]==A[l+1]) l++;
                         while ( l < r && A[r]==A[r-1]) r--;
                
                        l++; r--;
                      }
				}
		}
       
	
	return v;
        
}
};