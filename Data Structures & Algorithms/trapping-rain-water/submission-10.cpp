class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> lMax(n, 0), rMax(n, 0);

        lMax[0]=height[0];
        rMax[n-1]=height[n-1];

        for(int i=1; i<n; i++)
            lMax[i]=max(lMax[i-1], height[i]);

        for(int i=n-2; i>=0; i--)
            rMax[i]=max(rMax[i+1], height[i]);

        int sum=0;
        for(int i=0; i<n-1; i++)
            sum+=max(min(lMax[i], rMax[i])-height[i], 0);

        return sum;
    }
};
