class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> res(n, 0);
        stack<int> st;
        for(int i=0; i<temps.size(); i++){
            while(!st.empty() && temps[i]>temps[st.top()]){
                int r = st.top();
                res[r] = i-r;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
