// https://leetcode.com/problems/surrounded-regions/
class Solution {
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited,int i, int j){
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || visited[i][j] || board[i][j]=='X')
            return;
        visited[i][j]=true;
        dfs(board,visited,i+1,j);
        dfs(board,visited,i-1,j);
        dfs(board,visited,i,j+1);
        dfs(board,visited,i,j-1);
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && !visited[0][i]) {
                dfs(board, visited, 0, i);
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[n - 1][i] == 'O' && !visited[n - 1][i]) {
                dfs(board, visited, n - 1, i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && !visited[i][0]) {
                dfs(board, visited, i, 0);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][m - 1] == 'O' && !visited[i][m - 1]) {
                dfs(board, visited, i, m - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};