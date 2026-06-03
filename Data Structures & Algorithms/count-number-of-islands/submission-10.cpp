class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
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

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt=0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j]=='1'){
                    dfs(grid, i, j, m, n);
                    cnt++;
                }    

        return cnt;
    }
};
