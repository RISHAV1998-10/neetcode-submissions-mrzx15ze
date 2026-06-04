class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    void dfs(int r, int c, vector<vector<int>>& heights, vector<vector<bool>>& ocean){
        for(auto dir: dirs){
            int nr = r + dir[0];
            int nc = c + dir[1];

            if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[r][c] ){
                ocean[nr][nc] = true;
                dfs(nr, nc , heights, ocean);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        for(int c=0; c<m; c++){
            pac[0][c]=true;
            dfs(0, c, heights, pac);
            atl[n-1][c]=true;
            dfs(n-1, c, heights, atl);
        }

        for(int r=0; r<n; r++){
            pac[r][0]=true;
            dfs(r, 0, heights, pac);
            atl[r][m-1]=true;
            dfs(r, m-1, heights, atl);
        }

        vector<vector<int>> res;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(pac[i][j] && atl[i][j])
                    res.push_back({i,j});

        return res;
    }
};
