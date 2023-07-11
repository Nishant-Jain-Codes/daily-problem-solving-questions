//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str)
    {
        return isMatch(str, pattern);
    }

private:

    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
        return memoization(s, p, s.size(), p.size(), dp);
        return recursion(s, p, s.size() - 1, p.size() - 1);
    }

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
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends