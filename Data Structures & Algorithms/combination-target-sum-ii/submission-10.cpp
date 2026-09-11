class Solution {
public:
    void dfs(vector<int>& candidates, int target, int idx, vector<vector<int>>& res, vector<int>& path){
        if(target == 0){
            res.push_back(path);
            return;
        }

        for(int i=idx; i<candidates.size(); i++){
            if(i>idx && candidates[i-1]==candidates[i])
                continue;

            if(candidates[i]>target)
                break;

            path.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], i+1, res, path);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, target, 0, res, path);
        return res;
    }
};
