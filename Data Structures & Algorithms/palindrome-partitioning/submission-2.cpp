class Solution {
public:
    void dfs(string s, int idx, vector<vector<string>>& res, vector<string>& substr){
        if(idx==s.size()){
            res.push_back(substr);
            return;
        }

        for(int i=idx; i<s.size(); i++){
            if(isPali(s, idx, i)){
                substr.push_back(s.substr(idx, i-idx+1));
                dfs(s,i+1,res,substr);
                substr.pop_back();
            }
        }

    }
    bool isPali(string str, int start, int end){
        while(start <= end)
            if(str[start++]!=str[end--])
                return false;

        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> substr;
        dfs(s, 0, res, substr);
        return res;
    }
};
