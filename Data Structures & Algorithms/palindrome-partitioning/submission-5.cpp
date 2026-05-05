class Solution {
public:
    void dfs(string s, int idx, vector<vector<string>>& res, vector<string>& subset){
        if(idx>=s.size()){
            res.push_back(subset);
            return;
        }

        for(int i=idx; i<s.size(); i++){
            if(isPali(s, idx, i)){
                subset.push_back(s.substr(idx, i-idx+1));
                dfs(s, i+1, res, subset);
                subset.pop_back();
            }
        }
    }

    bool isPali(string s, int l, int r){
        while(l<r)
            if(s[l++]!=s[r--])
                return false;

        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> subset;
        dfs(s, 0, res, subset);
        return res;
    }
};
