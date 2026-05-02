class Solution {
public:
    void dfs(vector<int>& arr, int i, int target, vector<vector<int>>& res, vector<int>& subset){
        if(target == 0){
            res.push_back(subset);
            return;
        }
        if(i>=arr.size() || target < 0)
            return;

        subset.push_back(arr[i]);
        dfs(arr, i+1, target-arr[i], res, subset);
        subset.pop_back();

        while(i+1<arr.size() && arr[i]==arr[i+1])
            i++;
        
        dfs(arr, i+1, target, res, subset);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());        
        vector<vector<int>> res;
        vector<int> subset;
        dfs(candidates, 0, target, res, subset);
        return res;
    }
};
