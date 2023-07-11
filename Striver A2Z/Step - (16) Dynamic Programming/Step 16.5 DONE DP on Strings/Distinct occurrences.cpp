//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    const int mod = 1e9 + 7;
public:
    int subsequenceCount(string s, string t)
    {
        // Your code here
        return tabulation(s, t);
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));
        return memoisation(s, t, s.length(), t.length(), dp);
        return recursive(s, t, s.length() - 1, t.length() - 1);
    }

private:
    // time complexity: O(2^(n+m))
    // space complexity: O(n+m) stack space
    int recursive(string &s, string &t, int sIdx, int tIdx)
    {
        if (tIdx < 0)
            return 1;
        if (sIdx < 0)
            return 0;
        // if not same
        if (s[sIdx] != t[tIdx])
            return recursive(s, t, sIdx - 1, tIdx);
        // if same
        // take
        int take = recursive(s, t, sIdx - 1, tIdx - 1);
        // not take
        int notTake = recursive(s, t, sIdx - 1, tIdx);
        return take + notTake;
    }
    // time complexity: O((n*m)
    // space complexity: O(n*m) + O(n+m) stack space
    int memoisation(string &s, string &t, int sIdx, int tIdx, vector<vector<int>> &dp)
    {
        if (tIdx < 0)
            return 1;
        if (sIdx < 0)
            return 0;
        if (dp[sIdx][tIdx] != -1)
            return dp[sIdx][tIdx];
        // if not same
        if (s[sIdx] != t[tIdx])
            return memoisation(s, t, sIdx - 1, tIdx, dp);
        // if same
        // take
        int take = memoisation(s, t, sIdx - 1, tIdx - 1, dp);
        // not take
        int notTake = memoisation(s, t, sIdx - 1, tIdx, dp);
        return dp[sIdx][tIdx] = take + notTake;
    }
    // time complexity: O(n*m)
    // space complexity: O(n*m)
    int tabulation(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); // given string / target string
        // base case ( if target string is empty -> 1)
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        // choice diagram
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {

                int sIdx = i - 1;
                int tIdx = j - 1;
                if (s[sIdx] != t[tIdx]) // if not same
                    dp[i][j] = dp[i - 1][j];
                else // if same
                {

                    // take
                    int take = dp[i - 1][j - 1];
                    // not take
                    int notTake = dp[i - 1][j];
                    dp[i][j] = (take + notTake)%mod;
                }
            }
        }

        return dp[n][m];
    }
    
};

//{ Driver Code Starts.

//  Driver code to check above method
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        string tt;
        cin >> s;
        cin >> tt;

        Solution ob;
        cout << ob.subsequenceCount(s, tt) << endl;
    }
}
// } Driver Code Ends