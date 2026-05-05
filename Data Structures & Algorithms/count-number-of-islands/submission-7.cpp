class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}}; 
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt=0;

        for(int r=0; r<m; r++)
            for(int c=0; c<n; c++)
                if(grid[r][c]=='1'){
                    dfs(grid, r, c, m, n);
                    cnt++;
                }

        return cnt;
    }

    void dfs(vector<vector<char>>& grid, int r, int c, int m, int n){
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]=='0')
            return;

        grid[r][c]='0';
        for(auto dir: dirs){
            int nr = r + dir[0];
            int nc = c + dir[1];
            dfs(grid, nr, nc, m, n);
        }
    }
};
