class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l=0, r=n-1, lMax=height[0], rMax=height[n-1];

        int sum=0;
        while(l<r){
            if(lMax < rMax){
                l++;
                lMax=max(lMax, height[l]);
                sum+=max(lMax-height[l], 0);
            }
            else{
                r--;
                rMax=max(rMax, height[r]);
                sum+=max(rMax-height[r], 0);
            }
        }

        return sum;
    }
};
