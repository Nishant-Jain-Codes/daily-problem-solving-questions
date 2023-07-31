//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        return tabulation(N, arr);
        vector<vector<int>> dp(N, vector<int>(N, -1));
        return memoization(arr, 1, N - 1, dp); // arr, i , j
        return recursion(arr, 1, N - 1);       // arr, i , j
    }

private:
    // time complexity - O(exp)
    // space complexity - O(n)
    int recursion(int *arr, int i, int j)
    {
        if (i >= j)
            return 0;
        int temp = INT_MAX;
        for (int k = i; k < j; k++)
        {
            temp = min(temp, recursion(arr, i, k) + recursion(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]));
        }
        return temp;
    }
    // time complexity - O(n^3)
    // space complexity - O(n^2) + O(n) stack space
    int memoization(int *arr, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int temp = INT_MAX;
        for (int k = i; k < j; k++)
        {
            temp = min(temp, memoization(arr, i, k, dp) + memoization(arr, k + 1, j, dp) + (arr[i - 1] * arr[k] * arr[j]));
        }
        return dp[i][j] = temp;
    }
    // time complexity - O(n^3)
    // space complexity - O(n^2)
    int tabulation(int N, int arr[])
    {
        vector<vector<int>> dp(N, vector<int>(N, 0));

        for (int i = N - 1; i > 0; i--)
        {
            for (int j = i + 1; j < N; j++)
            {
                int temp = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    temp = min(temp, dp[i][k] + dp[k + 1][j] + (arr[i - 1] * arr[k] * arr[j]));
                }
                dp[i][j] = temp;
            }
        }
        return dp[1][N - 1];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends