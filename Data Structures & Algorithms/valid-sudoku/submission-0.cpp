class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> rows;
        unordered_set<int> cols;
        unordered_set<int> sqrs;

        //this checks all rows and cols
        for(int i=0; i<9; ++i){
            for(int j=0; j<9; ++j){
                if(board[i][j] == '.') continue;
                if(rows.find(board[i][j]) == rows.end()){
                    rows.insert(board[i][j]);
                }
                else return false;
            }
            rows.clear();

            for(int k=0; k<9; ++k){
                if(board[k][i] == '.') continue;
                if(cols.find(board[k][i]) == cols.end()){
                    cols.insert(board[k][i]);
                }
                else return false;
            }
            cols.clear();
        }

        //checking squares
        for(int i=0; i<9; i+=3){
            for(int j=0; j<9; j+=3){
                for(int k=0; k<3; ++k){
                    for(int l=0; l<3; ++l){
                        int n = board[i+k][j+l];
                        if(n == '.') continue;
                        if(sqrs.find(n) == sqrs.end()){
                            sqrs.insert(n);
                        }
                        else return false;
                    }
                }
                sqrs.clear();
            }
        }

        return true;
    }
};
