class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l=0, r=n-1;
        int maxarea = 0;
        while(l<r){
            if(heights[l]<heights[r]){
                maxarea=max(maxarea, heights[l]*(r-l));
                l++;
            }
            else{
                maxarea=max(maxarea, heights[r]*(r-l));
                r--;
            }
        }

        return maxarea;
    }
};
