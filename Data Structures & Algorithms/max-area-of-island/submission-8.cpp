class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {0,1}, {0,-1}, {1,0}};
    int dfs(vector<vector<int>>& grid, int r, int c, int m, int n){
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]==0)
            return 0;

        grid[r][c]=0;
        int res=1;
        for(auto dir: dirs){
            int nr=r+dir[0];
            int nc=c+dir[1];
            res+=dfs(grid, nr, nc, m, n);
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int res=0;

        for(int r=0; r<m; r++)
            for(int c=0; c<n; c++)
                if(grid[r][c]==1)
                    res=max(res, dfs(grid, r, c, m, n));

        return res;
    }
};
