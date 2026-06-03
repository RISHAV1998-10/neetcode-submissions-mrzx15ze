class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        int tot = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                    tot++;
                if(grid[i][j]==2)
                    q.push({i,j});
            }
        int t=0;
        while(tot>0 && !q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                auto node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;

                for(auto dir : dirs){
                    int nr = r + dir[0];
                    int nc = c + dir[1];

                    if(nr<0 || nr>=m || nc<0 || nc>=n || grid[nr][nc]!=1)
                        continue;

                    grid[nr][nc]=2;
                    tot--;
                    q.push({nr, nc});
                }
            }
            
            t++;
        }

        return tot>0 ? -1 : t;
    }
};
