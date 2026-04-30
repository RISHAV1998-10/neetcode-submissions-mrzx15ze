class Solution {
public:
    void dfs(vector<int>& arr, int idx, int target, 
                vector<vector<int>>& res, vector<int>& subset){
        if(target==0){
            res.push_back(subset);
            return;
        }
        
        if(idx>=arr.size() || target<0)
            return;
        
        subset.push_back(arr[idx]);
        dfs(arr, idx+1, target-arr[idx], res, subset);
        subset.pop_back();

        while(idx+1<arr.size() && arr[idx]==arr[idx+1])
            idx++;
        dfs(arr, idx+1, target, res, subset);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target, res, subset);
        return res;
    }
};
