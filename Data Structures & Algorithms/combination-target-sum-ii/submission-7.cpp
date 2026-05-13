class Solution {
public:
    void dfs(vector<int>& arr, int target, int i, vector<vector<int>>& res,
        vector<int>& subset){
        if(target==0){
            res.push_back(subset);
            return;
        }
        if(i>=arr.size() || target<0)
            return;

        subset.push_back(arr[i]);
        dfs(arr, target-arr[i], i+1, res, subset);
        subset.pop_back();
        while(i+1<arr.size() && arr[i]==arr[i+1])
            i++;

        dfs(arr, target, i+1, res, subset);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(candidates, target, 0, res, subset);
        return res;
    }
};
