class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    bool dfs(vector<vector<char>>& board, string word, int n, int m, int i, int j, int idx){
        if(idx == word.size())
            return true;

        if(i<0 || i>=n || j<0 || j>=m)
            return false;

        if(board[i][j] != word[idx])
            return false;

        
        for(auto dir : dirs){
            int nr = i + dir[0];
            int nc = j + dir[1];
            char temp = board[i][j];
            board[i][j] = '#';
            if(dfs(board, word, n, m, nr, nc, idx+1))
                return true;
            board[i][j] = temp;
        }

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(board[i][j]==word[0])
                    if(dfs(board, word, n, m, i, j, 0))
                        return true;

        return false;
    }
};
