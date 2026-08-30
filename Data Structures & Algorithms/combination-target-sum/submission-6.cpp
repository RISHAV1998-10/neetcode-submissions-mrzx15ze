class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int target, int idx){
        if(target == 0){
            res.push_back(sub);
            return;
        }

        for(int i=idx; i<nums.size(); i++){
            if(nums[i] > target)
                break;

            sub.push_back(nums[i]);
            backtrack(nums, res, sub, target-nums[i], i);
            sub.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> sub;
        backtrack(nums, res, sub, target, 0);
        return res;
    }
};
