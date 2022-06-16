class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n1 = nums1.size(), n2 = nums2.size();
        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);
            
        int l = 0;// low of first array
        int h = n1;// low of second array
        
        while(l <= h)
        {
            
            int mid1 = (l + h) / 2;// exact middle of first array
            int mid2 = (n1 + n2 + 1) / 2  // middle of merged array
                        - mid1; // minus the middle that has already been taken
            
                
            int L1 = mid1 == 0 ? INT_MIN : nums1[mid1 - 1];
            int L2 = mid2 == 0 ? INT_MIN : nums2[mid2 - 1];
            
            int H1 = mid1 == n1 ? INT_MAX : nums1[mid1];
            int H2 = mid2 == n2 ? INT_MAX : nums2[mid2];
                
            if(L1 <= H2 and L2 <= H1)
            {
                if((n1 + n2) % 2 == 1)
                    return max(L1, L2);
                
                    return (max(L1, L2) + min(H1, H2)) / 2.0;
            }
            
            else if(L1 > H2)
                h = mid1 - 1;
            
            else
                l = mid1 + 1;
        }
        
        return 0.0;
    }
};