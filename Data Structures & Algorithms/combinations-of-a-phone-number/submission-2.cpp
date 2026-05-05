class Solution {
public:
    vector<string> nums = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    void dfs(string digits, int idx, string& str, vector<string>& res){
        if(idx >= digits.size()){
            res.push_back(str);
            return;
        }

        for(char c: nums[digits[idx]-'0']){
            str.push_back(c);
            dfs(digits, idx+1, str, res);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits=="")
            return res;
        string str="";
        dfs(digits, 0, str, res);
        return res;    
    }
};
