class Solution {
public:
    void dfs(vector<int>& nums, vector<bool>& visit, vector<vector<int>>& res, vector<int>& perm){
        if(perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(visit[i])
                continue;

            visit[i]=true;
            perm.push_back(nums[i]);
            dfs(nums, visit, res, perm);
            perm.pop_back();
            visit[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> visit(nums.size(), false);
        vector<vector<int>> res;
        vector<int> perm;
        dfs(nums, visit, res, perm);
        return res;
    }
};
