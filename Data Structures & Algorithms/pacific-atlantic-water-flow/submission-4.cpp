class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};

    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, queue<pair<int, int>>& oceanQ){
        int oceanLen = oceanQ.size();
        for(int i=0; i<oceanLen; i++){
            auto oceanFront = oceanQ.front();
            oceanQ.pop();
            int r = oceanFront.first;
            int c = oceanFront.second;
            ocean[r][c] = true;

            for(auto d: dirs){
                int nr = r + d[0];
                int nc = c + d[1];
                if(nr>=0 && nr<heights.size() && nc>=0 && nc<heights[0].size() && !ocean[nr][nc] && heights[nr][nc]>=heights[r][c])
                    oceanQ.push({nr, nc});
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));

        queue<pair<int, int>> pacQ, atlQ;

        for(int r=0; r<n; r++){
            pacQ.push({r, 0});
            atlQ.push({r, m-1});
        }
        for(int c=0; c<m; c++){
            pacQ.push({0, c});
            atlQ.push({n-1, c});
        }

        while(!pacQ.empty() && !atl.empty()){

            bfs(heights, pac, pacQ);
            bfs(heights, atl, atlQ);
        }

        vector<vector<int>> res;
        for(int r=0; r<n; r++)
            for(int c=0; c<m; c++)
                if(pac[r][c] && atl[r][c])
                    res.push_back({r, c});

        return res;
    }
};
