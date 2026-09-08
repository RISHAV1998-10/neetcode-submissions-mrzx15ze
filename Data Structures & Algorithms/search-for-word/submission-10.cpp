class Solution {
public:
    vector<vector<int>> dirs = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int idx)  {
        int n = board.size();
        int m = board[0].size();

        if(i<0 || i>=n || j<0 || j>=m)
            return false;

        if(board[i][j] != word[idx])
            return false;


        if(idx == word.size()-1)
            return true;

        char temp = board[i][j];
        board[i][j] = '#';
        
        for(auto dir : dirs){
            int nr = i + dir[0];
            int nc = j + dir[1];

            if(dfs(board, word, nr, nc, idx+1))
                return true;
        }
        board[i][j] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(board[i][j]==word[0])
                    if(dfs(board, word, i, j, 0))
                        return true;

        return false;
    }
};
