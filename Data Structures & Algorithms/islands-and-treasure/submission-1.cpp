class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                if(grid[i][j]==0)
                    q.push({i,j});

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int r = top.first;
            int c = top.second;

            for(auto dir : dirs){
                int nr = r + dir[0];
                int nc = c + dir[1];

                if(nr<0 || nr>=m || nc<0 || nc>=n || grid[nr][nc]!=INT_MAX)
                    continue;

                grid[nr][nc]=grid[r][c]+1;
                q.push({nr, nc});                
            }
        }
    }
};
