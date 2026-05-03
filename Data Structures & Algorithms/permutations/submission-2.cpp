class Solution {
public:
    void dfs(vector<int>& nums, unordered_set<int>& uset, 
        vector<vector<int>>& res, vector<int>& subset){
        if(nums.size() == subset.size()){
            res.push_back(subset);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(uset.count(nums[i])>0)
                continue;

            uset.insert(nums[i]);
            subset.push_back(nums[i]);
            dfs(nums, uset, res, subset);
            subset.pop_back();
            uset.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        unordered_set<int> uset;
        dfs(nums, uset, res, subset);
        return res;
    }
};
