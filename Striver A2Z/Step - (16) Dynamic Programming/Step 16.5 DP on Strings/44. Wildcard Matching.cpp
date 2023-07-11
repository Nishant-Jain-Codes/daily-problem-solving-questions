class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return optimized(s, p);
        return tabulation(s, p);
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return memoization(s, p, s.size(), p.size(), dp);
        return recursion(s, p, s.size() - 1, p.size() - 1);
    }

private:
    // time complexity: O(3^(m+n))
    // space complexity: O(m+n)
    bool recursion(string &s, string &p, int i, int j)
    {
        //! base case
        if (i < 0 && j < 0)
            return true;
        else if (i < 0)
        {
            for (int idx = j; idx >= 0; idx--)
            {
                if (p[idx] != '*')
                    return false;
            }
            return true;
        }
        else if (j < 0)
            return false;

        // if match
        if (s[i] == p[j])
            return recursion(s, p, i - 1, j - 1);
        // if not match
        //  if p[j] == '?'
        if (p[j] == '?')
            return recursion(s, p, i - 1, j - 1);
        // if p[j] == '*'
        if (p[j] == '*')
        {
            // dont use *
            bool dontUse = recursion(s, p, i, j - 1);
            // use * for 1
            bool useSingle = recursion(s, p, i - 1, j - 1);
            // use * for multiple
            bool useMultiple = recursion(s, p, i - 1, j);

            return dontUse || useSingle || useMultiple;
        }
        return false;
    }
    // time complexity: O(m*n)
    // space complexity: O(m*n)+O(m+n)
    bool memoization(string &s, string &p, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i < 0 && j < 0)
            return true;
        else if (i < 0)
        {
            for (int idx = j; idx >= 0; idx--)
            {
                if (p[idx] != '*')
                    return false;
            }
            return true;
        }
        else if (j < 0)
            return false;
        if (dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;
        // if match
        if (s[i] == p[j])
            ans = memoization(s, p, i - 1, j - 1, dp);
        // if not match
        //  if p[j] == '?'
        if (p[j] == '?')
            ans = memoization(s, p, i - 1, j - 1, dp);
        // if p[j] == '*'
        if (p[j] == '*')
        {
            // dont use *
            bool dontUse = memoization(s, p, i, j - 1, dp);
            // use * for 1
            bool useSingle = memoization(s, p, i - 1, j - 1, dp);
            // use * for multiple
            bool useMultiple = memoization(s, p, i - 1, j, dp);

            ans = (dontUse || useSingle || useMultiple);
        }
        return dp[i][j] = ans;
    }
    // time complexity: O(m*n)
    // space complexity: O(m*n)
    bool tabulation(string &s, string &p)
    {
        // dp array
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        // base case
        // ! one base indexing
        dp[0][0] = true;
        bool contiStar = true;
        for (int idx = 0; idx < p.size(); idx++)
        { // true till first non star
            if (p[idx] == '*')
            {
                dp[0][idx + 1] = contiStar;
            }
            else
            {
                contiStar = false;
            }
        }
        for (int i = 1; i <= s.size(); i++)
        {
            dp[i][0] = false; // else if(i<0) return false;
        }
        // filling up table
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                bool ans = false;
                // if match
                if (s[i - 1] == p[j - 1])
                    ans = dp[i - 1][j - 1];
                // if not match
                //  if p[j] == '?'
                else if (p[j - 1] == '?')
                    ans = dp[i - 1][j - 1];
                // if p[j] == '*'
                else if (p[j - 1] == '*')
                {
                    // dont use *
                    bool dontUse = dp[i][j - 1];
                    // use * for 1
                    bool useSingle = dp[i - 1][j - 1];
                    // use * for multiple
                    bool useMultiple = dp[i - 1][j];

                    ans = (dontUse || useSingle || useMultiple);
                }
                dp[i][j] = ans;
            }
        }
        // returning answer
        return dp[s.size()][p.size()];
    }
    // time complexity: O(m*n)
    // space complexity: O(m+n)
    bool optimized(string &s, string &p)
    {
        // dp array
        vector<bool> curr(p.size() + 1, false);
        vector<bool> prev(p.size() + 1, false);
        // base case
        // ! one base indexing
        prev[0] = true;
        bool contiStar = true;
        for (int idx = 0; idx < p.size(); idx++)
        { // true till first non star
            if (p[idx] == '*')
            {
                prev[idx + 1] = contiStar;
            }
            else
            {
                contiStar = false;
            }
        }
        // filling up table
        for (int i = 1; i <= s.size(); i++)
        {
            curr[0] = false;
            for (int j = 1; j <= p.size(); j++)
            {
                bool ans = false;
                // if match
                if (s[i - 1] == p[j - 1])
                    ans = prev[j - 1];
                // if not match
                //  if p[j] == '?'
                else if (p[j - 1] == '?')
                    ans = prev[j - 1];
                // if p[j] == '*'
                else if (p[j - 1] == '*')
                {
                    // dont use *
                    bool dontUse = curr[j - 1];
                    // use * for 1
                    bool useSingle = prev[j - 1];
                    // use * for multiple
                    bool useMultiple = prev[j];
                    ans = (dontUse || useSingle || useMultiple);
                }
                curr[j] = ans;
            }
            prev = curr;
        }
        // returning answer
        return prev[p.size()];
    }
};