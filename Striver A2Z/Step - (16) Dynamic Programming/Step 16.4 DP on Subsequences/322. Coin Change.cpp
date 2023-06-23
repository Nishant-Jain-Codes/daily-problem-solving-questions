class Solution
{

public:
    int coinChange(vector<int> &coins, int amount)
    {
        return optimized(coins, amount);
        return tabulation(coins, amount);
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -10));
        return memoisation(0, amount, coins, dp);
        return recursion(0, amount, coins);
    }

private:
    int recursion(int idx, int amount, vector<int> &coins)
    {
        if (amount == 0)
            return 0;
        if (idx >= coins.size() || amount < 0)
            return -1;
        int notTake = recursion(idx + 1, amount, coins);
        int take = -1;
        if (amount - coins[idx] >= 0)
            take = recursion(idx, amount - coins[idx], coins);
        if (notTake == -1 && take == -1)
            return -1;
        else if (notTake == -1)
        {
            return take + 1;
        }
        else if (take == -1)
        {
            return notTake;
        }
        else
        {
            return min(notTake, take + 1);
        }
    }
    int memoisation(int idx, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (amount == 0)
            return 0;
        if (idx >= coins.size() || amount < 0)
            return -1;
        if (dp[idx][amount] != -10)
            return dp[idx][amount];
        int notTake = memoisation(idx + 1, amount, coins, dp);
        int take = -1;
        if (amount - coins[idx] >= 0)
            take = memoisation(idx, amount - coins[idx], coins, dp);
        int ans = -1;
        if (notTake == -1 && take == -1)
            ans = -1;
        else if (notTake == -1)
        {
            ans = take + 1;
        }
        else if (take == -1)
        {
            ans = notTake;
        }
        else
        {
            ans = min(notTake, take + 1);
        }
        return dp[idx][amount] = ans;
    }
    int tabulation(vector<int> &coins, int amount)
    {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        for (int i = 0; i < coins.size(); i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = -1;
        }
        for (int i = 1; i < coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                int notTake = dp[i - 1][j];
                int take = -1;
                if (j - coins[i] >= 0)
                    take = dp[i][j - coins[i]];
                int ans = -1;
                if (notTake == -1 && take == -1)
                    ans = -1;
                else if (notTake == -1)
                {
                    ans = take + 1;
                }
                else if (take == -1)
                {
                    ans = notTake;
                }
                else
                {
                    ans = min(notTake, take + 1);
                }
                dp[i][j] = ans;
            }
        }
        return dp[coins.size() - 1][amount];
    }
    int optimized(vector<int> &coins, int amount)
    {
        vector<int> prev(amount + 1, -1);
        vector<int> curr(amount + 1, -1);

        prev[0] = 0;
        curr[0] = 0;

        for (int i = 1; i <= amount; i++)
        {
            if (i % coins[0] == 0)
                prev[i] = i / coins[0];
            else
                prev[i] = -1;
        }

        for (int i = 1; i < coins.size(); i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                int notTake = prev[j];
                int take = -1;

                if (j - coins[i] >= 0)
                    take = curr[j - coins[i]];

                int ans = -1;

                if (notTake == -1 && take == -1)
                    ans = -1;
                else if (notTake == -1)
                    ans = take + 1;
                else if (take == -1)
                    ans = notTake;
                else
                    ans = min(notTake, take + 1);

                curr[j] = ans;
            }

            prev = curr;
        }

        return prev[amount];
    }
};