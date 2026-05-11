class Solution {
public:
    void dfs(vector<int>& nums, int target, int i, vector<vector<int>>& res, vector<int>& subset){
        if(target==0){
            res.push_back(subset);
            return;
        }
        if(target <0 || i>=nums.size())
            return;

        subset.push_back(nums[i]);
        dfs(nums, target-nums[i], i, res, subset);
        subset.pop_back();

        dfs(nums, target, i+1, res, subset);
            
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, target, 0, res, subset);
        return res;
    }
};
