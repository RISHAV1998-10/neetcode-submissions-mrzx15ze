class Solution {
public:
    void dfs(vector<int>& nums, int i, int target, vector<vector<int>>& res, vector<int>& subset){
        if(i>=nums.size() || target<0)
            return;
        
        if(target == 0){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i, target-nums[i], res, subset);
        subset.pop_back();
        dfs(nums, i+1, target, res, subset);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, target, res, subset);
        return res;
    }
};
