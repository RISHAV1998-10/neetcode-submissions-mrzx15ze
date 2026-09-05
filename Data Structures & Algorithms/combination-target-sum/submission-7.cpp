class Solution {
public:
    void dfs(vector<int>& nums, int target, int idx, vector<vector<int>>& res, vector<int>& path){
        if(target == 0){
            res.push_back(path);
            return;
        }

        if(target < 0)
            return;

        for(int i=idx; i<nums.size(); i++){
            path.push_back(nums[i]);
            dfs(nums, target-nums[i], i, res, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, target, 0, res, path);
        return res;
    }
};
