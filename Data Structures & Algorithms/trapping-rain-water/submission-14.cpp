class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1, lmax = height[0], rmax = height[n-1];

        int res = 0;

        while(l<r){
            if(lmax<rmax){
                l++;
                lmax=max(lmax, height[l]);
                res+=max(lmax-height[l], 0);
            }
            else{
                r--;
                rmax=max(rmax, height[r]);
                res+=max(rmax-height[r], 0);
            }
        }

        return res;
    }
};
