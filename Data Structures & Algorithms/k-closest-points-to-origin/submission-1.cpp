class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(auto p: points){
            int d = p[0]*p[0] + p[1]*p[1];
            pq.push({d, p});
            if(pq.size()>k)
                pq.pop();
        }

        vector<vector<int>> res;
        while(!pq.empty()){
            auto p = pq.top().second;
            pq.pop();
            res.push_back(p);
        }

        return res;
    }
};
