class Solution {
public:
    void dfs(vector<int>& candidates, int target, int idx, vector<vector<int>>& res, vector<int>& subset){
        if(target==0){
            res.push_back(subset);
            return;
        }
        if(idx>=candidates.size() || target<0)
            return;

        subset.push_back(candidates[idx]);
        dfs(candidates, target-candidates[idx], idx+1, res, subset);
        subset.pop_back();

        while(idx+1<candidates.size() && candidates[idx]==candidates[idx+1])
            idx++;

        dfs(candidates, target, idx+1, res, subset);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(candidates, target, 0, res, subset);
        return res;
    }
};
