class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean){
        ocean[r][c] = true;

        for(auto d: dirs){
            int nr = r+d[0];
            int nc = c+d[1];
            
            if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && !ocean[nr][nc] && heights[nr][nc]>=heights[r][c])
                dfs(nr, nc, heights, ocean);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        for(int r=0; r<n; r++){
            dfs(r, 0, heights, pac);
            dfs(r, m-1, heights, atl);
        }
        for(int c=0; c<m; c++){
            dfs(0, c, heights, pac);
            dfs(n-1, c, heights, atl);
        }

        vector<vector<int>> res;
        for(int r=0; r<n; r++)
            for(int c=0; c<m; c++)
                if(pac[r][c] && atl[r][c])
                    res.push_back({r, c});

        return res;
    }
};
