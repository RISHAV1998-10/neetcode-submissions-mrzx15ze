class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<int, int>> maxHeap;
        for(int i=0; i<points.size(); i++){
            int d = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            maxHeap.push({d, i});
            if(maxHeap.size() > k)
                maxHeap.pop();
        }

        while(!maxHeap.empty()){
            auto [d, i] = maxHeap.top();
            maxHeap.pop();
            res.push_back(points[i]);
        }

        return res;
    }
};
