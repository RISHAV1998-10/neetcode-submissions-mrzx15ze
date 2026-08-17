class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1>n2)
            return findMedianSortedArrays(nums2, nums1);

        int l=0, r=n1, n=n1+n2;
        while(l<=r){
            int partA = (l+r)/2;
            int partB = (n+1)/2-partA;
            int l1 = partA==0 ? INT_MIN : nums1[partA-1];
            int r1 = partA==n1 ? INT_MAX : nums1[partA];
            int l2 = partB==0 ? INT_MIN : nums2[partB-1];
            int r2 = partB==n2 ? INT_MAX : nums2[partB];
            
            if(l1>r2)
                r=partA-1;
            else if(l2>r1)
                l=partA+1;
            else{
                if(n%2 == 0){
                    return (double)(max(l1,l2) + min(r1,r2))/2;
                }
                else{
                    return max(l1,l2);
                }
            }
        }

        return 0.0;
    }
};
