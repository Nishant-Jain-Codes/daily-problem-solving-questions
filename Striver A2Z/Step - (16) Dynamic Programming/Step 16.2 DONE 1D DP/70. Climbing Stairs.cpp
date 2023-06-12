class Solution {
private: 
    // Time Complexity : O(2^n)
    // Space Complexity : O(n)
    int recursive(int n){
        if(n<0){
            return 0;
        }
        if(n == 0 || n == 1){
            return 1;
        }
        return recursive(n-1) + recursive(n-2);
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
        return dp[n] = memoization(n-1, dp) + memoization(n-2, dp);
    }
    // Time Complexity : O(n)
    // Space Complexity : O(n)
    int tabulation(int n ){
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
public:
    int climbStairs(int n) {
        return tabulation(n);
        vector<int> dp(n+1, -1);
        return memoization(n, dp);
        return recursive(n);
    }
};