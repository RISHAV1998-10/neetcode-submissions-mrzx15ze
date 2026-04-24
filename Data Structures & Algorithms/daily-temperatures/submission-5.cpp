class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> res(n, 0);
        deque<int> dq;

        for(int i=0; i<n; i++){
            while(!dq.empty() && temps[i]>temps[dq.back()]){
                int idx = dq.back();
                dq.pop_back();
                res[idx] = i-idx;
            }

            dq.push_back(i);
            
        }

        return res;
    }
};
