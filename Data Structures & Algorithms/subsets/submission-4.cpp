class Solution {
public:
    void dfs(vector<int>& nums, int idx, vector<vector<int>>& res, vector<int>& sub){
        res.push_back(sub);

        for(int i=idx; i<nums.size(); i++){
            sub.push_back(nums[i]);
            dfs(nums, i+1, res, sub);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        dfs(nums, 0, res, sub);
        return res;
    }
};
