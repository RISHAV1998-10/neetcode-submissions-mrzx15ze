class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1>n2)
            return findMedianSortedArrays(nums2, nums1);

        int n=n1+n2, l=0, r=n1;

        while(l<=r){
            int m1 = l+(r-l)/2;
            int m2 = (n+1)/2 - m1;
            int l1 = m1==0 ? INT_MIN : nums1[m1-1];
            int l2 = m2==0 ? INT_MIN : nums2[m2-1];
            int r1 = m1==n1 ? INT_MAX : nums1[m1];
            int r2 = m2==n2 ? INT_MAX : nums2[m2];

            if(l1 > r2)
                r=m1-1;
            else if(l2>r1)
                l=m1+1;
            else{
                if(n%2==0)
                    return ((double)(max(l1,l2)+min(r1,r2)))/2.0;
                else
                    return max(l1,l2);
            }
        }

        return -1;
    }
};
