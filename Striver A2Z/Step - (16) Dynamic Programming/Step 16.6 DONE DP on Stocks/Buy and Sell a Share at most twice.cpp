//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        return tabulation(prices);
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return memoization(prices, 0, 1, 2, dp);
        return recursion(prices, 0, true, 2);
    }

private:
    // time complexity : O(n^2)
    // space complexity : O(n)
    int recursion(vector<int> &prices, int idx, bool canBuy, int transactionsLeft)
    {
        if (transactionsLeft == 0 || idx >= prices.size())
            return 0;
        int ans;
        if (canBuy)
        {
            int didBuy = recursion(prices, idx + 1, false, transactionsLeft) - prices[idx];
            int didNotBuy = recursion(prices, idx + 1, true, transactionsLeft);
            ans = max(didBuy, didNotBuy);
        }
        else
        {
            int didSell = recursion(prices, idx + 1, true, transactionsLeft - 1) + prices[idx];
            int didNotSell = recursion(prices, idx + 1, false, transactionsLeft);
            ans = max(didSell, didNotSell);
        }
        return ans;
    }
    // time complexity : O(2*n*2)
    // space complexity : O(n*2*3) + +O(n) stack space
    int memoization(vector<int> &prices, int idx, bool canBuy, int transactionsLeft, vector<vector<vector<int>>> &dp)
    {
        if (transactionsLeft == 0 || idx >= prices.size())
            return 0;
        if (dp[idx][canBuy][transactionsLeft] != -1)
            return dp[idx][canBuy][transactionsLeft];
        int ans;
        if (canBuy)
        {
            int didBuy = memoization(prices, idx + 1, false, transactionsLeft, dp) - prices[idx];
            int didNotBuy = memoization(prices, idx + 1, true, transactionsLeft, dp);
            ans = max(didBuy, didNotBuy);
        }
        else
        {
            int didSell = memoization(prices, idx + 1, true, transactionsLeft - 1, dp) + prices[idx];
            int didNotSell = memoization(prices, idx + 1, false, transactionsLeft, dp);
            ans = max(didSell, didNotSell);
        }
        return dp[idx][canBuy][transactionsLeft] = ans;
    }
    // time complexity : O(n*2*3)
    // space complexity : O(n*2*3)
    int tabulation(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
        //! these base cases are redundant as we are initializing the dp array with 0
        // if transactionsLeft = 0 then profit = 0 for all i
        // for (int i = 0; i < n + 1; i++)
        // {
        //     dp[i][0][0] = 0;
        //     dp[i][1][0] = 0;
        // }
        // if end of the array then profit = 0 for all i
        // for (int i = 0; i < 3; i++)
        // {
        //     dp[n][0][i] = 0;
        //     dp[n][1][i] = 0;
        // }
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {
                for (int transactionsLeft = 2; transactionsLeft >= 1; transactionsLeft--)
                {
                    int ans;
                    if (canBuy)
                    {
                        int didBuy = dp[idx + 1][0][transactionsLeft] - prices[idx];
                        int didNotBuy = dp[idx + 1][1][transactionsLeft];
                        ans = max(didBuy, didNotBuy);
                    }
                    else
                    {
                        int didSell = dp[idx + 1][1][transactionsLeft - 1] + prices[idx];
                        int didNotSell = dp[idx + 1][0][transactionsLeft];
                        ans = max(didSell, didNotSell);
                    }
                    dp[idx][canBuy][transactionsLeft] = ans;
                }
            }
        }
        return dp[0][1][2];
    }
    // time complexity : O(n*2*3)
    // space complexity : O(2*3)
    int optimized(vector<int> &prices)
    {
        int n = prices.size();
        //(after&curr)|(buy&sell)|(transactionsLeft)
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {
                for (int transactionsLeft = 2; transactionsLeft >= 1; transactionsLeft--)
                {
                    int ans;
                    if (canBuy)
                    {
                        int didBuy = after[0][transactionsLeft] - prices[idx];
                        int didNotBuy = after[1][transactionsLeft];
                        ans = max(didBuy, didNotBuy);
                    }
                    else
                    {
                        int didSell = after[1][transactionsLeft - 1] + prices[idx];
                        int didNotSell = after[0][transactionsLeft];
                        ans = max(didSell, didNotSell);
                    }
                    curr[canBuy][transactionsLeft] = ans;
                }
            }
            after = curr;
        }
        return after[1][2];
    }
};
int maxProfit(vector<int>&price){
    //Write your code here..
    Solution sol;
    return sol.maxProfit(price);
}


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends