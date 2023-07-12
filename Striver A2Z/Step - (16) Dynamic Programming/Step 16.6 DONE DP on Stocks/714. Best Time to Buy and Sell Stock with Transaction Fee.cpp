class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        return spaceOptimized(prices, fee);
        return tabulation(prices, fee);
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return memoization(prices, fee, 0, true, dp);
        return recursion(prices, fee, 0, true);
    }

private:
    // Time Complexity: O(2^N)
    // Space Complexity: O(N) stack space
    int recursion(const vector<int> &prices, const int fee, int idx, int canBuy)
    {
        if (idx >= prices.size())
            return 0;
        int ans;
        if (canBuy)
        {
            int didBuy = recursion(prices, fee, idx + 1, false) - prices[idx] - fee;
            int didNotBuy = recursion(prices, fee, idx + 1, true);
            ans = max(didBuy, didNotBuy);
        }
        else
        {
            int didSell = recursion(prices, fee, idx + 1, true) + prices[idx];
            int didNotSell = recursion(prices, fee, idx + 1, false);
            ans = max(didSell, didNotSell);
        }
        return ans;
    }
    // Time Complexity: O(N)
    // Space Complexity: O(N*2) + O(N) stack space
    int memoization(const vector<int> &prices, const int fee, int idx, int canBuy, vector<vector<int>> &dp)
    {
        if (idx >= prices.size())
            return 0;
        if (dp[idx][canBuy] != -1)
            return dp[idx][canBuy];
        int ans;
        if (canBuy)
        {
            int didBuy = memoization(prices, fee, idx + 1, false, dp) - prices[idx] - fee;
            int didNotBuy = memoization(prices, fee, idx + 1, true, dp);
            ans = max(didBuy, didNotBuy);
        }
        else
        {
            int didSell = memoization(prices, fee, idx + 1, true, dp) + prices[idx];
            int didNotSell = memoization(prices, fee, idx + 1, false, dp);
            ans = max(didSell, didNotSell);
        }
        return dp[idx][canBuy] = ans;
    }
    // Time Complexity: O(N)
    // Space Complexity: O(N*2)
    int tabulation(vector<int> &prices, int fee)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        for (int idx = prices.size() - 1; idx >= 0; idx--)
        {
            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {
                int ans;
                if (canBuy)
                {
                    int didBuy = dp[idx + 1][0] - prices[idx] - fee;
                    int didNotBuy = dp[idx + 1][1];
                    ans = max(didBuy, didNotBuy);
                }
                else
                {
                    int didSell = dp[idx + 1][1] + prices[idx];
                    int didNotSell = dp[idx + 1][0];
                    ans = max(didSell, didNotSell);
                }
                dp[idx][canBuy] = ans;
            }
        }
        return dp[0][1];
    }
    // Time Complexity: O(N)
    // Space Complexity: O(2*2)
    int spaceOptimized(vector<int> &prices, int fee)
    {
        vector<int> after(2, 0);
        vector<int> curr(2, 0);

        for (int idx = prices.size() - 1; idx >= 0; idx--)
        {
            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {
                int ans;
                if (canBuy)
                {
                    int didBuy = after[0] - prices[idx] - fee;
                    int didNotBuy = after[1];
                    ans = max(didBuy, didNotBuy);
                }
                else
                {
                    int didSell = after[1] + prices[idx];
                    int didNotSell = after[0];
                    ans = max(didSell, didNotSell);
                }
                curr[canBuy] = ans;
            }
            after = curr;
        }
        return curr[1];
    }
};