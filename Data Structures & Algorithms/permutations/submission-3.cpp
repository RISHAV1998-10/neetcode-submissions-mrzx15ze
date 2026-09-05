class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, unordered_map<int, bool>& hash){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(hash[nums[i]])
                continue;
            hash[nums[i]]=true;
            path.push_back(nums[i]);
            dfs(nums, res, path, hash);
            path.pop_back();
            hash[nums[i]]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        unordered_map<int, bool> hash;
        dfs(nums, res, path, hash);
        return res;
    }
};
