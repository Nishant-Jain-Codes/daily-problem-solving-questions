class Solution {
    private:
    bool dfs(vector<vector<char>> & board, const string & word , int i , int j , int curIdx ,vector<vector<bool>>&used){
        if(curIdx == word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || used[i][j] || board[i][j] != word[curIdx]){
            return false;
        }
        used[i][j] = true;
        int deltaX[] = {-1,0,1,0};
        int deltaY[] = {0,1,0,-1};
        for(int k=0;k<4;k++){
            if(dfs(board, word, i+deltaX[k], j+deltaY[k], curIdx+1, used)){
                return true;
            }
        }
        used[i][j] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));  
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0] == board[i][j] && dfs(board, word, i, j, 0, used)){
                    return true;
                }
            }
        }
        return false;
    }
};