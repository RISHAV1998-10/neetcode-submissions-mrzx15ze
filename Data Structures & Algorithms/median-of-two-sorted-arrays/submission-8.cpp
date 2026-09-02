class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int l=0, r=n1, n=n1+n2;
        while(l<=r){
            int sepA = (l+r)/2;
            int sepB = (n+1)/2-sepA;
            int lA = sepA == 0 ? INT_MIN : nums1[sepA-1];
            int rA = sepA == n1 ? INT_MAX : nums1[sepA];
            int lB = sepB == 0 ? INT_MIN : nums2[sepB-1];
            int rB = sepB == n2 ? INT_MAX : nums2[sepB];
            if(lA > rB)
                r = sepA - 1;
            else if(lB > rA)
                l = sepA + 1;
            else{
                if(n%2 == 0){
                    return ((double)(max(lA,lB) + min(rA,rB)))/2.0;
                }
                else
                    return max(lA, lB);
            }
        }

        return 0.0;
    }
};
