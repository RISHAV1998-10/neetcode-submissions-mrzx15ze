class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int l=0, r=n-1;

        int val = 0;

        while(l<r){
            val = max(val, (r-l)*min(heights[l], heights[r]));
            if(heights[l]<= heights[r])
                l++;
            else r--;
        }

        return val;
    }
};
