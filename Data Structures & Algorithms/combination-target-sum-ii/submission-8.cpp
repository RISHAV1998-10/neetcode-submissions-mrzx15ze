class Solution {
public:
    void dfs(vector<int>& nums, int target, int idx, vector<vector<int>>& res, vector<int>& path){
        if(target == 0){
            res.push_back(path);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            if(nums[i] > target)
                break;
            if(i>idx && nums[i]==nums[i-1])
                continue;

            path.push_back(nums[i]);
            dfs(nums, target-nums[i], i+1, res, path);
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
