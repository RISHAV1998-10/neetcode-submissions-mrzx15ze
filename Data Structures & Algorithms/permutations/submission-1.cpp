class Solution {
public:
    void dfs(vector<int>& nums, unordered_set<int>& used, vector<vector<int>>& res, vector<int>& subset){
        if(subset.size() == nums.size()){
            res.push_back(subset);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(used.count(nums[i]) > 0)
                continue;
            
            used.insert(nums[i]);
            subset.push_back(nums[i]);
            dfs(nums, used, res, subset);
            subset.pop_back();
            used.erase(nums[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        unordered_set<int> used;
        dfs(nums, used, res, subset);
        return res; 
    }
};
