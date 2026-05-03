class Solution {
public:
    void dfs(int open, int close, int n, string& str, vector<string>& res){
        if(open == close && open == n){
            res.push_back(str);
            return;
        }

        if(open < n){
            str.push_back('(');
            dfs(open+1, close, n, str, res);
            str.pop_back();
        }

        if(close < open){
            str.push_back(')');
            dfs(open, close+1, n, str, res);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string str = "";
        vector<string> res;
        dfs(0, 0, n, str, res);
        return res;        
    }
};
