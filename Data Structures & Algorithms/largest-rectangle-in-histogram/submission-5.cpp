class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int res=0;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int idx = st.top();
                st.pop();
                int nse = i, pse = st.empty() ? -1 : st.top();
                res = max(res, heights[idx]*(nse-pse-1));
            }

            st.push(i);
        }

        while(!st.empty()){
            int ht = heights[st.top()];
            st.pop();
            int nse = n, pse = st.empty() ? -1 : st.top();
            res=max(res, ht*(nse-pse-1));
        }

        return res;
    }
};
