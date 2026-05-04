class Solution {
public:
    vector<string> nums = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(string digits, int idx, vector<string>& res, string& str){
        if(idx>=digits.size()){
            res.push_back(str);
            return;
        }
        for(char c:nums[digits[idx]-'0']){
            str.push_back(c);
            dfs(digits, idx+1, res, str);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits=="")
            return {};

        vector<string> res;
        string str = "";
        dfs(digits, 0, res, str);
        return res;
    }
};
