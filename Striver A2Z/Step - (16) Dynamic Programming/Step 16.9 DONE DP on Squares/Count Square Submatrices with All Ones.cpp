//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        // code here
        vector<vector<int>> dp(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for(int i=1;i<=matrix.size();i++){
            for(int j=1;j<=matrix[0].size();j++){
                if(matrix[i-1][j-1]==1){
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        int total = 0;
        for(int i=1;i<=matrix.size();i++){
            for(int j=1;j<=matrix[0].size();j++){
                total += dp[i][j];
            }
        }
        return total;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    }
    return 0;
}
// } Driver Code Ends