class Solution {
public:
    void dfs(int n, int open, int close, vector<string>& res, string& s){
        if(s.size()==2*n){
            res.push_back(s);
            return;
        }

        if(open<n){
            s.push_back('(');
            dfs(n, open+1, close, res, s);
            s.pop_back();
        }

        if(close<open){
            s.push_back(')');
            dfs(n, open, close+1, res, s);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        int open=0, close=0;
        dfs(n, open, close, res, s);
        return res;
    }
};
