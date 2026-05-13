class Solution {
public:
    void dfs(string s, int i, vector<vector<string>>& res, vector<string>& str){
        if(i>=s.length()){
            res.push_back(str);
        }

        for(int l=i; l<s.size(); l++){
            if(isPali(s, i, l)){
                str.push_back(s.substr(i, l-i+1));
                dfs(s, l+1, res, str);
                str.pop_back();
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
        vector<string> str;
        dfs(s, 0, res, str);
        return res;
    }
};
