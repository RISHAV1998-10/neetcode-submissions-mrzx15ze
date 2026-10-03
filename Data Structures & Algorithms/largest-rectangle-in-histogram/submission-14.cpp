class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxarea = -1;
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int ht = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int width = nse - pse - 1;
                maxarea = max(maxarea, width * ht);
            }

            st.push(i);
        }

        while(!st.empty()){
            int ht = heights[st.top()];
            st.pop();
            int nse = n;
            int pse = st.empty() ? -1 : st.top();
            int width = nse - pse - 1;
            maxarea = max(maxarea, width * ht);
        }

        return maxarea;

    }
};
