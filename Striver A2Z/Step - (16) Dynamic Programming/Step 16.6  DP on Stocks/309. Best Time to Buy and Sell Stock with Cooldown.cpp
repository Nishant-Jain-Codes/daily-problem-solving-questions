class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return spaceOptimized(prices);
        return tabulation(prices);
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        return memoization(prices, 0, true, false, dp);
        return recursion(prices, 0, true, false); // prices,idx,canBut,hasCooldown
    }

private:
    // time complexity : O(2^n)
    // space complexity : O(n) stack space
    int recursion(vector<int> &prices, int idx, bool canBuy, bool hasCoolDown)
    {
        if (idx >= prices.size())
            return 0;
        int ans;
        if (hasCoolDown)
            ans = recursion(prices, idx + 1, true, false);
        else
        {
            if (canBuy)
            {
                int didBuy = recursion(prices, idx + 1, false, false) - prices[idx];
                int didNotBuy = recursion(prices, idx + 1, true, false);
                ans = max(didBuy, didNotBuy);
            }
            else
            {
                int didSell = recursion(prices, idx + 1, true, true) + prices[idx];
                int didNotSell = recursion(prices, idx + 1, false, false);
                ans = max(didSell, didNotSell);
            }
        }
        return ans;
    }
    // time complexity : O(n)
    // space complexity : O(2*2*n) + O(n) stack space
    int memoization(vector<int> &prices, int idx, bool canBuy, bool hasCoolDown, vector<vector<vector<int>>> &dp)
    {
        if (idx >= prices.size())
            return 0;
        if (dp[idx][canBuy][hasCoolDown] != -1)
            return dp[idx][canBuy][hasCoolDown];
        int ans;
        if (hasCoolDown)
            ans = memoization(prices, idx + 1, true, false, dp);
        else
        {
            if (canBuy)
            {
                int didBuy = memoization(prices, idx + 1, false, false, dp) - prices[idx];
                int didNotBuy = memoization(prices, idx + 1, true, false, dp);
                ans = max(didBuy, didNotBuy);
            }
            else
            {
                int didSell = memoization(prices, idx + 1, true, true, dp) + prices[idx];
                int didNotSell = memoization(prices, idx + 1, false, false, dp);
                ans = max(didSell, didNotSell);
            }
        }
        return dp[idx][canBuy][hasCoolDown] = ans;
    }
    // time complexity : O(n)
    // space complexity : O(2*2*n)
    int tabulation(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2, 0)));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {
                for (int hasCoolDown = 1; hasCoolDown >= 0; hasCoolDown--)
                {
                    int ans;
                    if (hasCoolDown)
                        ans = dp[idx + 1][1][0];
                    else
                    {
                        if (canBuy)
                        {
                            int didBuy = dp[idx + 1][0][0] - prices[idx];
                            int didNotBuy = dp[idx + 1][1][0];
                            ans = max(didBuy, didNotBuy);
                        }
                        else
                        {
                            int didSell = dp[idx + 1][1][1] + prices[idx];
                            int didNotSell = dp[idx + 1][0][0];
                            ans = max(didSell, didNotSell);
                        }
                    }
                    dp[idx][canBuy][hasCoolDown] = ans;
                }
            }
        }
        return dp[0][1][0];
    }
    // time complexity : O(n)
    // space complexity : O(2*2*2)
    int spaceOptimized(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> after(2, vector<int>(2, 0));
        vector<vector<int>> curr(2, vector<int>(2, 0));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {
                for (int hasCoolDown = 1; hasCoolDown >= 0; hasCoolDown--)
                {
                    int ans;
                    if (hasCoolDown)
                        ans = after[1][0];
                    else
                    {
                        if (canBuy)
                        {
                            int didBuy = after[0][0] - prices[idx];
                            int didNotBuy = after[1][0];
                            ans = max(didBuy, didNotBuy);
                        }
                        else
                        {
                            int didSell = after[1][1] + prices[idx];
                            int didNotSell = after[0][0];
                            ans = max(didSell, didNotSell);
                        }
                    }
                    curr[canBuy][hasCoolDown] = ans;
                }
            }
            after = curr;
        }
        return curr[1][0];
    }
};