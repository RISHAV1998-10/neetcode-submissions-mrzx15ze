class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
    int dfs(vector<vector<int>>& grid, int r, int c, int m, int n){
        if(r<0 || c<0 || r>=m || c>=n || grid[r][c]==0)
            return 0;

        grid[r][c]=0;
        int area = 1;
        for(auto dir: dirs){
            int nr = r + dir[0];
            int nc = c + dir[1];
            area+=dfs(grid, nr, nc, m, n);
        }

        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int res = 0;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j]==1){
                    res=max(res, dfs(grid, i, j, m, n));
                }

        return res;
    }
};
