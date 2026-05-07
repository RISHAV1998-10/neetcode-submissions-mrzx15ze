class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1, lmax=height[0], rmax=height[n-1];
        int res=0;

        while(l<r){
            if(height[l]<height[r]){
                res+=max(lmax-height[l], 0);
                l++;
                lmax=max(lmax, height[l]);
            }
            else{
                res+=max(rmax-height[r], 0);
                r--;
                rmax=max(rmax, height[r]);
            }
        } 

        return res;
    }
};
