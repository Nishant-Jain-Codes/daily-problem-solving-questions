//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int i, int j)
    {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] == 'X')
            return;
        visited[i][j] = true;
        dfs(board, visited, i + 1, j);
        dfs(board, visited, i - 1, j);
        dfs(board, visited, i, j + 1);
        dfs(board, visited, i, j - 1);
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> &board)
    {
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O' && !visited[0][i])
            {
                dfs(board, visited, 0, i);
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (board[n - 1][i] == 'O' && !visited[n - 1][i])
            {
                dfs(board, visited, n - 1, i);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O' && !visited[i][0])
            {
                dfs(board, visited, i, 0);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (board[i][m - 1] == 'O' && !visited[i][m - 1])
            {
                dfs(board, visited, i, m - 1);
            }
        }

        vector<vector<char>> solution(board);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && !visited[i][j])
                {
                    solution[i][j] = 'X';
                }
            }
        }

        return solution;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends