class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for(int r=0; r<n; r++){
            if(board[r][0]=='O'){
                q.push({r, 0});
                vis[r][0]=true;
            }

            if(board[r][m-1]=='O'){
                q.push({r, m-1});
                vis[r][m-1]=true;
            }
        }

        for(int c=0; c<m; c++){
            if(board[0][c]=='O'){
                q.push({0, c});
                vis[0][c]=true;
            }

            if(board[n-1][c]=='O'){
                q.push({n-1, c});
                vis[n-1][c]=true;
            }
        }

        while(!q.empty()){
            auto [r, c] = q.front();
            q.pop();

            for(auto& d : dirs){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='O'){
                    q.push({nr, nc});
                    vis[nr][nc] = true;
                }
            }
        }

        for(int r=0; r<n; r++)
            for(int c=0; c<m; c++)
                if(board[r][c]=='O' && !vis[r][c])
                    board[r][c]='X';
    }
};
