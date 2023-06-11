//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    const int mod = 1e9+7;
    // Time Complexity : O(2^n)
    // Space Complexity : O(n)
    int recursive(int n){
        if(n<0){
            return 0;
        }
        if(n == 0 || n == 1){
            return 1;
        }
        return (recursive(n-1)%mod + recursive(n-2)%mod)%mod;
    }
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    int memoization(int n , vector<int>& dp){
        if(n<0){
            return 0;
        }
        if(n == 0 || n == 1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        return dp[n] = (memoization(n-1, dp)%mod + memoization(n-2, dp)%mod)%mod;
    }
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    int tabulation(int n ){
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            dp[i] = (dp[i-1]%mod + dp[i-2]%mod)%mod;
        }
        return dp[n];
    }
public:
    int countWays(int n) {
        return tabulation(n);
        vector<int> dp(n+1, -1);
        return memoization(n, dp);
        return recursive(n);
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends