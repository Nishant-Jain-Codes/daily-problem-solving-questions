class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        return tabulation(s);
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return memoisation(s, 0, n - 1, dp);
        return recursive(s, 0, s.size() - 1); // string, start, end
    }

private:
    // time complexity: O(2^n)
    int recursive(string &s, int start, int end)
    {
        if (start == end)
            return 1;
        if (start > end)
            return 0;
        if (s[start] == s[end])
            return 2 + recursive(s, start + 1, end - 1);
        int leftTake = recursive(s, start + 1, end);
        int rightTake = recursive(s, start, end - 1);
        return max(leftTake, rightTake);
    }
    int memoisation(string &s, int start, int end, vector<vector<int>> &dp)
    {
        if (start == end)
            return 1;
        if (start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        if (s[start] == s[end])
            return 2 + memoisation(s, start + 1, end - 1, dp);
        int leftTake = memoisation(s, start + 1, end, dp);
        int rightTake = memoisation(s, start, end - 1, dp);
        return dp[start][end] = max(leftTake, rightTake);
    }
    int tabulation(string &s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }

        for (int len = 2; len <= n; len++)
        {
            for (int start = 0; start <= n - len; start++)
            {
                int end = start + len - 1;

                if (s[start] == s[end])
                {
                    dp[start][end] = 2 + dp[start + 1][end - 1];
                }
                else
                {
                    dp[start][end] = max(dp[start + 1][end], dp[start][end - 1]);
                }
            }
        }

        return dp[0][n - 1];
    }
};