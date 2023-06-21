//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    long long int count(int coins[], int N, int sum)
    {

        // code here.
        return optimized(N, sum, coins);
        return tabulation(N, sum, coins);
        vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, -1));
        return memoisation(N - 1, sum, coins, dp);
        return recursion(N - 1, sum, coins);
    }

private:
    // time complexity greater than O(2^n)
    // space complexity  O(sum)
    long long int recursion(int idx, int sum, int *coins)
    {
        if (idx < 0)
        {
            return sum == 0;
        }
        long long int notTake = recursion(idx - 1, sum, coins);
        long long int take = 0;
        if (sum - coins[idx] >= 0)
        {
            take = recursion(idx, sum - coins[idx], coins);
        }
        return notTake + take;
    }
    // time complexity O(N*sum)
    // space complexity O(N*sum) + O(Sum){stack space}
    long long int memoisation(int idx, int sum, int *coins, vector<vector<long long int>> &dp)
    {
        if (idx < 0)
        {
            return sum == 0;
        }
        if (dp[idx][sum] != -1)
        {
            return dp[idx][sum];
        }
        long long int notTake = memoisation(idx - 1, sum, coins, dp);
        long long int take = 0;
        if (sum - coins[idx] >= 0)
        {
            take = memoisation(idx, sum - coins[idx], coins, dp);
        }
        return dp[idx][sum] = notTake + take;
    }
    // time complexity O(N*sum)
    // space complexity O(N*sum)
    long long int tabulation(int N, int sum, int *coins)
    {
        vector<vector<long long int>> dp(N, vector<long long int>(sum + 1, 0));
        // if sum is zero then there is one way to make sum zero
        for (int i = 0; i < N; i++)
        {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= sum; i++)
        {
            if (i % coins[0] == 0)
                dp[0][i] += 1;
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                long long int notTake = dp[i - 1][j];
                long long int take = 0;
                if (j - coins[i] >= 0)
                {
                    take = dp[i][j - coins[i]];
                }
                dp[i][j] = notTake + take;
            }
        }
        return dp[N - 1][sum];
    }
    long long int optimized(int N, int sum, int *coins)
    {
        vector<long long int> prev(sum + 1, 0);
        vector<long long int> curr(sum + 1, 0);
        // if sum is zero then there is one way to make sum zero
        prev[0] = 1;
        curr[0] = 1;
        for (int i = 1; i <= sum; i++)
        {
            if (i % coins[0] == 0)
                prev[i] += 1;
        }
        for (int i = 1; i < N; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                long long int notTake = prev[j];
                long long int take = 0;
                if (j - coins[i] >= 0)
                {
                    take = curr[j - coins[i]];
                }
                curr[j] = notTake + take;
            }
            prev = curr;
        }
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++)
            cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}

// } Driver Code Ends