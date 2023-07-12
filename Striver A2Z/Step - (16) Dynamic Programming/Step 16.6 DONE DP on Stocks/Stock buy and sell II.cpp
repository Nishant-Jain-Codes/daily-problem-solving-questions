//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class sol
{
public:
    int maxProfit(vector<int> &prices)
    {
        return spaceOptimized(prices);
        return tabulation(prices);
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return memoization(prices, 0, true, dp); // idx / canBuy
        return recursion(prices, 0, true);       // idx / canBuy
    }

private:
    // time complexity : O(2^N)
    // space complexity : O(N)
    int recursion(vector<int> &prices, int idx, bool canBuy)
    {
        // base case
        if (idx == prices.size())
            return 0;
        // trying all possible options
        int ans;
        if (canBuy)
        {
            int didBuy = recursion(prices, idx + 1, false) - prices[idx];
            int didNotBuy = recursion(prices, idx + 1, true);
            ans = max(didBuy, didNotBuy);
        }
        else
        {
            int didSell = recursion(prices, idx + 1, true) + prices[idx];
            int didNotSell = recursion(prices, idx + 1, false);
            ans = max(didSell, didNotSell);
        }
        return ans;
    }
    // time complexity : O(N*2 )
    // space complexity : O(N*2) + O(N) (recursion stack)
    int memoization(vector<int> &prices, int idx, bool canBuy, vector<vector<int>> &dp)
    {
        // base case
        if (idx == prices.size())
            return 0;
        // trying all possible options
        if (dp[idx][canBuy] != -1)
            return dp[idx][canBuy];
        int ans;
        if (canBuy)
        {
            int didBuy = memoization(prices, idx + 1, false, dp) - prices[idx];
            int didNotBuy = memoization(prices, idx + 1, true, dp);
            ans = max(didBuy, didNotBuy);
        }
        else
        {
            int didSell = memoization(prices, idx + 1, true, dp) + prices[idx];
            int didNotSell = memoization(prices, idx + 1, false, dp);
            ans = max(didSell, didNotSell);
        }
        return dp[idx][canBuy] = ans;
    }
    // time complexity : O(N*2 )
    // space complexity : O(N*2)
    int tabulation(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[n][0] = 0;
        dp[n][1] = 0;
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {
                int ans;
                if (canBuy)
                {
                    int didBuy = dp[idx+1][0] - prices[idx];
                    int didNotBuy = dp[idx+1][1];
                    ans = max(didBuy, didNotBuy);
                }
                else
                {
                    int didSell = dp[idx+1][1] + prices[idx];
                    int didNotSell = dp[idx+1][0];
                    ans = max(didSell, didNotSell);
                }
                dp[idx][canBuy] = ans;
            }
        }
        return dp[0][1];
    }
    // time complexity : O(N)
    // space complexity : O(1)
    int spaceOptimized(vector<int> & prices){
        int n = prices.size();
        int prevFalse = 0;
        int prevTrue = 0;
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int canBuy = 1; canBuy >= 0; canBuy--)
            {
                int ans;
                if (canBuy)
                {
                    int didBuy = prevFalse - prices[idx];
                    int didNotBuy = prevTrue;
                    ans = max(didBuy, didNotBuy);
                }
                else
                {
                    int didSell = prevTrue + prices[idx];
                    int didNotSell = prevFalse;
                    ans = max(didSell, didNotSell);
                }
                if(canBuy)
                    prevTrue = ans;
                else
                    prevFalse = ans;
            }
        }
        return prevTrue;
    }

};

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        sol obj;
        return obj.maxProfit(prices);
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends