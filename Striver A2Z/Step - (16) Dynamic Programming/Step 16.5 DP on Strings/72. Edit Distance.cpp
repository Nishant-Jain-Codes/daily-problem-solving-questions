class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        return optimized(word1, word2);
        return tabulation(word1, word2);
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return memoization(word1, word2, word1.size(), word2.size(), dp);
        return recursion(word1, word2, word1.size() - 1, word2.size() - 1);
    }

private:
    // time complexity: O(3^(m+n))
    // space complexity: O(m+n)
    int recursion(string &word1, string &word2, int i, int j)
    {
        // base case
        if (i < 0 && j < 0)
            return 0;
        if (j < 0)
            return i + 1;
        if (i < 0)
            return j + 1;

        // if match
        if (word1[i] == word2[j])
            return recursion(word1, word2, i - 1, j - 1);
        // if not match
        // 1. insert (i, j - 1)
        int insert = 1 + recursion(word1, word2, i, j - 1);
        // 2. replace (i - 1, j - 1)
        int replace = 1 + recursion(word1, word2, i - 1, j - 1);
        // 3. delete (i - 1, j)
        int del = 1 + recursion(word1, word2, i - 1, j);
        return min({insert, replace, del});
    }
    // time complexity: O(m*n)
    // space complexity: O(m*n)+O(m+n)
    int memoization(string &word1, string &word2, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i < 0 && j < 0)
            return 0;
        if (j < 0)
            return i + 1;
        if (i < 0)
            return j + 1;
        // check if already calculated
        if (dp[i][j] != -1)
            return dp[i][j];
        // if match
        if (word1[i] == word2[j])
            return dp[i][j] = memoization(word1, word2, i - 1, j - 1, dp);
        // if not match
        // 1. insert (i, j - 1)
        int insert = 1 + memoization(word1, word2, i, j - 1, dp);
        // 2. replace (i - 1, j - 1)
        int replace = 1 + memoization(word1, word2, i - 1, j - 1, dp);
        // 3. delete (i - 1, j)
        int del = 1 + memoization(word1, word2, i - 1, j, dp);
        return dp[i][j] = min({insert, replace, del});
    }
    // time complexity: O(m*n)
    // space complexity: O(m*n)
    int tabulation(string &word1, string &word2)
    {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // one based indexing
        // base case
        // if(j==0) dp[i][j] = i;
        for (int i = 1; i <= word1.size(); i++)
            dp[i][0] = i;
        // if(i==0) dp[i][j] = j;
        for (int j = 1; j <= word2.size(); j++)
            dp[0][j] = j;
        // if(j==0 && i==0) dp[i][j] = 0;
        dp[0][0] = 0;

        // filling the table

        for (int i = 1; i <= word1.size(); i++)
        {
            for (int j = 1; j <= word2.size(); j++)
            {
                // if match
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i - 1][j - 1];
                // if not match
                else
                {
                    // 1. insert (i, j - 1)
                    int insert = 1 + dp[i][j-1];
                    // 2. replace (i - 1, j - 1)
                    int replace = 1 + dp[i - 1][j - 1];
                    // 3. delete (i - 1, j)
                    int del = 1 + dp[i - 1][j];
                    dp[i][j] = min({insert, replace, del});
                }
            }
        }
        for(int i=0;i<=word1.size();i++){
            for(int j=0;j<=word2.size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[word1.size()][word2.size()];
    }

    int optimized(string &word1, string &word2)
    {
        vector<int> prev(word2.size() + 1, 0);
        vector<int> curr(word2.size() + 1, 0);
        // one based indexing
        // base case
        for (int j = 1; j <= word2.size(); j++)
            prev[j] = j;


        // filling the table

        for (int i = 1; i <= word1.size(); i++)
        {
            curr[0] = i;
            for (int j = 1; j <= word2.size(); j++)
            {
                // if match
                if (word1[i-1] == word2[j-1])
                    curr[j] = prev[j - 1];
                // if not match
                else
                {
                    // 1. insert (i, j - 1)
                    int insert = 1 + curr[j-1];
                    // 2. replace (i - 1, j - 1)
                    int replace = 1 + prev[j - 1];
                    // 3. delete (i - 1, j)
                    int del = 1 + prev[j];
                    curr[j] = min({insert, replace, del});
                }
            }
            prev = curr;
        }
        return prev[word2.size()];
    }



};