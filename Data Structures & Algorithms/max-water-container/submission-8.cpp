class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l=0, r=n-1;
        int res = 0;

        while(l<=r){
            if(heights[l] < heights[r]){
                res=max(res, (r-l)*heights[l]);
                l++;
            }
            else{
                res=max(res, (r-l)*heights[r]);
                r--;
            }
        }

        return res;
    }
};
