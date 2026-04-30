class Solution {
public:
    void dfs(vector<int>& nums, int idx, vector<int>& subset, 
            vector<vector<int>>& res, int sum, int target ){
        if(sum==target){
            res.push_back(subset);
            return;
        }

        if(idx>=nums.size() || sum>target)
            return;
        
        subset.push_back(nums[idx]);
        dfs(nums, idx, subset, res, sum+nums[idx], target);
        subset.pop_back();
        dfs(nums, idx+1, subset, res, sum, target);        
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res, 0, target);
        return res;
    }
};
