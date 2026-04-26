class Solution {
public:
    vector<int> findNSE(vector<int>& heights){
        int n = heights.size();
        vector<int> res(n);
        stack<int> st;

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[i]<=heights[st.top()])
                st.pop();

            res[i]=st.empty() ? n: st.top();
            st.push(i);
        }

        return res;
    }

    vector<int> findPSE(vector<int>& heights){
        int n = heights.size();
        vector<int> res(n);
        stack<int> st;

        for(int i=0; i<n; i++){
            while(!st.empty() && heights[i]<=heights[st.top()])
                st.pop();

            res[i]=st.empty() ? -1: st.top();
            st.push(i);
        }

        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = findNSE(heights);
        vector<int> pse = findPSE(heights);

        int res = 0;
        for(int i=0; i<n; i++)
            res = max(res, heights[i]*(nse[i]-pse[i]-1));

        return res;
    }
};
