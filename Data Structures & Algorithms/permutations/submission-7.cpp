class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& perm, vector<bool>& visit){
        if(perm.size()==nums.size()){
            res.push_back(perm);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(visit[i])   
                continue;

            visit[i]=true;
            perm.push_back(nums[i]);
            dfs(nums, res, perm, visit);
            perm.pop_back();
            visit[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        vector<bool> visit(nums.size(), false);
        dfs(nums, res, perm, visit);
        return res;
    }
};
