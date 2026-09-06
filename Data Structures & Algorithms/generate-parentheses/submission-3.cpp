class Solution {
public:
    void dfs(int n, int open, int close, vector<string>& res, string& path){
        if(path.size() == 2*n){
            res.push_back(path);
            return;
        }
        if(open < n){
            path.push_back('(');
            dfs(n, open+1, close, res, path);
            path.pop_back();
        }
        if(close < open){
            path.push_back(')');
            dfs(n, open, close+1, res, path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path="";
        dfs(n, 0, 0, res, path);
        return res;
    }
};
