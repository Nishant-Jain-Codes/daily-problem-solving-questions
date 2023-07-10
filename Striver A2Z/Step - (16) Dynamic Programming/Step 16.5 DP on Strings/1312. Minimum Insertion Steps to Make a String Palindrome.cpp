class Solution
{
public:
    int minInsertions(string str)
    {
        vector<vector<int>> dp(str.length(), vector<int>(str.length(), -1));
        return memoisation(str, 0, str.length() - 1, dp);
    }

private:
    // time complexity : O(n^2)
    // space complexity : O(n^2)
    int memoisation(string &str, int start, int end, vector<vector<int>> &dp)
    {
        if (start == end || start > end)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        if (str[start] == str[end])
            return memoisation(str, start + 1, end - 1, dp);
        int leftTake = memoisation(str, start + 1, end, dp);
        int rightTake = memoisation(str, start, end - 1, dp);
        return dp[start][end] = min(leftTake, rightTake) + 1;
    }
};