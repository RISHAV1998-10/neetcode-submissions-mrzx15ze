class Solution {
public:
    int trap(vector<int>& height) {
        int r = height.size()-1, l=0;
        int lmax = 0, rmax=0;
        int res=0;

        while(l<=r){
            if(lmax<=rmax){
                lmax=max(lmax, height[l]);
                res+=max(lmax-height[l], 0);
                l++;
            }
            else{
                rmax=max(rmax, height[r]);
                res+=max(rmax-height[r], 0);
                r--;
            }
        }

        return res;
    }
};
