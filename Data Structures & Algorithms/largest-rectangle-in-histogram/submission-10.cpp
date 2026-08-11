class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                int idx = st.top();
                st.pop();
                int nse=i;
                int pse = st.empty() ? -1 : st.top();
                maxArea=max(maxArea, heights[idx]*(nse-pse-1));
            }
            st.push(i);
        }

        while(!st.empty()){
            int h=heights[st.top()]; st.pop();
            int nse=heights.size();
            int pse = st.empty() ? -1  : st.top();
            maxArea=max(maxArea, h*(nse-pse-1));
        }

        return maxArea;
    }
};
