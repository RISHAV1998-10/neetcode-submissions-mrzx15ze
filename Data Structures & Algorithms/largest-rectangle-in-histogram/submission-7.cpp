class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int area = 0;
        for(int i=0; i<heights.size(); i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int ht = heights[st.top()];
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int currArea = (nse-pse-1)*ht;
                area=max(area, currArea);
            }
            st.push(i);
        }
        while(!st.empty()){
            int ht=heights[st.top()];
            st.pop();
            int nse=n;
            int pse = st.empty() ? -1 : st.top();
            int currArea = (nse-pse-1)*ht;
            area=max(area, currArea);
        }

        return area;
    }
};
