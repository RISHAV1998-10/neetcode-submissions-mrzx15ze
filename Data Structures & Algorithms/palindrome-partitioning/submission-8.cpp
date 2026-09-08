class Solution {
public:
    void dfs(const string &s, vector<vector<bool>>& pal, vector<vector<string>>& res, vector<string>& path, int l){
        if(l == s.size()){
            res.push_back(path);
            return;
        }

        for(int r=l; r<s.size();r++){
            if(pal[l][r]){
                path.push_back(s.substr(l, r-l+1));
                dfs(s, pal, res, path, r+1);
                path.pop_back();
            }
        }
    }
    bool isPali(const string &s, int l, int r){
        while(l<=r){
            if(s[l]!=s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int l = n - 1; l >= 0; l--) {
            for (int r = l; r < n; r++) {

                if (s[l] == s[r] &&
                    (r - l <= 2 || pal[l + 1][r - 1])) {
                    pal[l][r] = true;
                }
            }
        }

        vector<vector<string>> res;
        vector<string> path;
        dfs(s, pal, res, path, 0);
        return res;
    }
};
