//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution2
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        return spaceOptimized(prices, k);
        return tabulation(prices, k);
        vector<vector<int>> dp(prices.size(), vector<int>((2 * k) + 1, -1));
        return memoization(prices, 0, 2 * k, dp);
        return recursion(prices, 0, 2 * k);
    }

private:
    // time complexity = O(n^2 * k)
    // space complexity = O(n)
    int recursion(vector<int> &prices, int idx, int tId)
    {
        if (idx >= prices.size() || tId == 0)
            return 0;
        bool canBuy = tId % 2 == 0;
        int ans = 0;
        if (canBuy)
        {
            int didbuy = recursion(prices, idx + 1, tId - 1) - prices[idx];
            int didnotbuy = recursion(prices, idx + 1, tId);
            ans = max(didbuy, didnotbuy);
        }
        else
        {
            int didsell = recursion(prices, idx + 1, tId - 1) + prices[idx];
            int didnotsell = recursion(prices, idx + 1, tId);
            ans = max(didsell, didnotsell);
        }
        return ans;
    }
    // time complexity = O(n * k)
    // space complexity = O(n * k) + O(n) stack space
    int memoization(vector<int> &prices, int idx, int tId, vector<vector<int>> &dp)
    {
        if (idx >= prices.size() || tId == 0)
            return 0;
        if (dp[idx][tId] != -1)
            return dp[idx][tId];
        bool canBuy = tId % 2 == 0;
        int ans = 0;
        if (canBuy)
        {
            int didbuy = memoization(prices, idx + 1, tId - 1, dp) - prices[idx];
            int didnotbuy = memoization(prices, idx + 1, tId, dp);
            ans = max(didbuy, didnotbuy);
        }
        else
        {
            int didsell = memoization(prices, idx + 1, tId - 1, dp) + prices[idx];
            int didnotsell = memoization(prices, idx + 1, tId, dp);
            ans = max(didsell, didnotsell);
        }
        return dp[idx][tId] = ans;
    }
    // time complexity = O(n * k)
    // space complexity = O(n * k)
    int tabulation(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>((2 * k) + 1, 0));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int tId = 1; tId <= (2 * k); tId++)
            {
                bool canBuy = tId % 2 == 0;
                int ans = 0;
                if (canBuy)
                {
                    int didbuy = dp[idx + 1][tId - 1] - prices[idx];
                    int didnotbuy = dp[idx + 1][tId];
                    ans = max(didbuy, didnotbuy);
                }
                else
                {
                    int didsell = dp[idx + 1][tId - 1] + prices[idx];
                    int didnotsell = dp[idx + 1][tId];
                    ans = max(didsell, didnotsell);
                }
                dp[idx][tId] = ans;
            }
        }
        return dp[0][2 * k];
    }
    // time complexity = O(n * k)
    // space complexity =
    int spaceOptimized(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<int> after((2 * k) + 1, 0);
        vector<int> curr((2 * k) + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int tId = 1; tId <= (2 * k); tId++)
            {
                bool canBuy = tId % 2 == 0;
                int ans = 0;
                if (canBuy)
                {
                    int didbuy = after[tId - 1] - prices[idx];
                    int didnotbuy = after[tId];
                    ans = max(didbuy, didnotbuy);
                }
                else
                {
                    int didsell = after[tId - 1] + prices[idx];
                    int didnotsell = after[tId];
                    ans = max(didsell, didnotsell);
                }
                curr[tId] = ans;
            }
            after = curr;
        }
        return curr[2 * k];
    }
};
class Solution
{
public:
    int maxProfit(int K, int N, int A[])
    {
        // code here
        vector<int> prices(N);
        for (int i = 0; i < N; i++)
            prices[i] = A[i];
        Solution2 s;
        return s.maxProfit(K, prices);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends