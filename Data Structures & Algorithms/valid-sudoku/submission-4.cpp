class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> s;

        // row check
        for(int i=0; i<9; i++){
            s.clear();

            for(int j=0; j<9; j++){
                if(board[i][j]=='.')
                    continue;
                if(s.count(board[i][j])>0)
                    return false;
                s.insert(board[i][j]);
            }
        }

        // col check
        for(int j=0; j<9; j++){
            s.clear();

            for(int i=0; i<9; i++){
                if(board[i][j]=='.')
                    continue;
                if(s.count(board[i][j])>0)
                    return false;
                s.insert(board[i][j]);
            }
        }

        for(int m=0; m<3; m++){
            for(int n=0; n<3; n++){
                s.clear();

                for(int i=0; i<3; i++)
                    for(int j=0; j<3; j++){
                        int r = 3*m+i;
                        int c = 3*n+j;
                        if(board[r][c]=='.')
                            continue;

                        if(s.count(board[r][c])>0)
                            return false;

                        s.insert(board[r][c]);
                    }
            }
        }

        return true;
    }
};
