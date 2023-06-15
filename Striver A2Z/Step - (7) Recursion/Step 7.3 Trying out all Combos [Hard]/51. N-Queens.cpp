class Solution {
private:
    bool isValid(int row,int col , int n ,vector<string> & board){
        for(int i=0;i<row;i++){
            if(board[i][col] == 'Q') return false;
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void solve(int curRow, int n , vector<string> &board, vector<vector<string>> &ans){
        if(curRow == n){
            ans.push_back(board);
            return;
        }
        for(int col = 0; col<n;col++){
            if(isValid(curRow,col,n,board)){
                board[curRow][col] = 'Q';
                solve(curRow+1,n,board,ans);
                board[curRow][col] = '.';
            }
        }
        return ;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(0,n,board,ans);
        return ans;
    }
};