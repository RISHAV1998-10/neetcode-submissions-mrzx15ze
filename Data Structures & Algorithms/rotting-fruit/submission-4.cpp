class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fresh=0;
        queue<pair<int,int>> q;

        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(grid[i][j]==1)
                    fresh++;
                else if(grid[i][j]==2)
                    q.push({i,j});
            }

        if(fresh==0)
            return 0;
        vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        int t=0;
        while(fresh>0 && !q.empty()){
            int len = q.size();
            for(int i=0; i<len; i++){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                for(auto dir: dirs){
                    int nr = r+dir[0];
                    int nc = c+dir[1];

                    if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1){
                        grid[nr][nc]=2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
            t++;
        }

        return fresh>0 ? -1 : t;
    }
};
