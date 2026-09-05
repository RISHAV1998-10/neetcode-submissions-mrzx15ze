class Solution {
public:
    void dfs(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int>& path){
        res.push_back(path);

        for(int i=idx; i<nums.size(); i++){
            if(i>idx && nums[i]==nums[i-1])
                continue;
            path.push_back(nums[i]);
            dfs(nums, i+1, res, path);
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, res, path);
        return res;
    }
};
