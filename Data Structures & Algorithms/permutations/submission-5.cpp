class Solution {
public:
    void dfs(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int>& perm, unordered_map<int, bool>& visit){
        if(perm.size()==nums.size()){
            res.push_back(perm);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            if(visit[nums[i]])   
                continue;
            visit[nums[i]]=true;
            perm.push_back(nums[i]);
            dfs(nums, idx, res, perm, visit);
            perm.pop_back();
            visit[nums[i]]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> perm;
        unordered_map<int, bool> visit;
        for(int i : nums)
            visit[i]=false;
        dfs(nums, 0, res, perm, visit);
        return res;
    }
};
