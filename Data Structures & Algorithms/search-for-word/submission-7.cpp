class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i, int ROW, int COL){
        if(i==word.size())
            return true;

        if(r<0 || c<0 || r>=ROW || c>=COL || board[r][c]!=word[i] || board[r][c]=='#')
            return false;

        board[r][c] = '#';
        bool res = dfs(board, word, r+1, c, i+1, ROW, COL) ||
                   dfs(board, word, r-1, c, i+1, ROW, COL) ||
                   dfs(board, word, r, c+1, i+1, ROW, COL) ||
                   dfs(board, word, r, c-1, i+1, ROW, COL) ;
        board[r][c] = word[i];
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for(int r=0; r<m; r++)
            for(int c=0; c<n; c++)
                if(dfs(board, word, r, c, 0, m, n))
                    return true;

        return false;
    }
};
