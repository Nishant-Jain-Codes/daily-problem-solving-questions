class Solution
{
public:
    int minCut(string s)
    {
        return tabulationOptimized(s);
        vector<int> dp(s.size(), -1);
        return frontPartition2(s, 0, dp) - 1;
        // vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        // return frontPartition(s, 0, s.size() - 1, dp);
        // return memoization(s, 0, s.size() - 1, dp);
        // return recursion(s, 0, s.size() - 1);
    }

private:
    bool isPalindrome(string &s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int recursion(string &s, int i, int j)
    {
        if (i >= j || isPalindrome(s, i, j))
            return 0;
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int leftBreaks = recursion(s, i, k);
            int rightBreaks = recursion(s, k + 1, j);
            ans = min(ans, leftBreaks + rightBreaks + 1);
        }
        return ans;
    }

    int memoization(string &s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j || isPalindrome(s, i, j))
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (j - i == 1)
            return dp[i][j] = 1;
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            int leftBreaks = memoization(s, i, k, dp);
            int rightBreaks = memoization(s, k + 1, j, dp);
            ans = min(ans, leftBreaks + rightBreaks + 1);
        }
        return dp[i][j] = ans;
    }

    int frontPartition(string &s, int si, int ei, vector<vector<int>> &dp)
    {
        if (si >= ei || isPalindrome(s, si, ei))
            return 0;
        if (dp[si][ei] != -1)
            return dp[si][ei];
        int ans = INT_MAX;
        for (int cut = si; cut < ei; cut++)
        {
            if (isPalindrome(s, si, cut))
            {
                ans = min(ans, frontPartition(s, cut + 1, ei, dp) + 1);
            }
        }
        return dp[si][ei] = ans;
    }

    int frontPartition2(string &s, int si, vector<int> &dp)
    {
        if (si == s.size())
            return 0;
        if (dp[si] != -1)
            return dp[si];
        int answer = INT_MAX;
        for (int cut = si; cut < s.size(); cut++)
        {
            if (isPalindrome(s, si, cut))
                answer = min(answer, frontPartition2(s, cut + 1, dp) + 1);
        }
        return dp[si] = answer;
    }

    int tabulationOptimized(string &s)
    {
        vector<int> dp(s.size() + 1, 0);
        for (int si = s.size() - 1; si >= 0; si--)
        {
            if (si == s.size())
                dp[si] = 0;
            else
            {
                int answer = INT_MAX;
                for (int cut = si; cut < s.size(); cut++)
                {
                    if (isPalindrome(s, si, cut))
                        answer = min(answer, dp[cut + 1] + 1);
                }
                dp[si] = answer;
            }
        }
        return dp[0] - 1;
    }
};