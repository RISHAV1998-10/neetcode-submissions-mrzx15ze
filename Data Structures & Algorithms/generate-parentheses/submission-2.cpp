class Solution {
public:
    void dfs(int n, int open, int close, string& str, vector<string>& res){
        if(open==close && open == n){
            res.push_back(str);
            return;
        }
        if(open<n){
            str.push_back('(');
            dfs(n, open+1, close, str, res);
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            dfs(n, open, close+1, str, res);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str="";
        dfs(n, 0, 0, str, res);
        return res;
    }
};
