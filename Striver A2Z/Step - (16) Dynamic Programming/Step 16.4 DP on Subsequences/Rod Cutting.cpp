//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution{
public:
    int cutRod(int price[], int n) {
        //code 
        return optimized(price, n);
        return tabulation(price, n);
        vector<vector<int>> dp(n, vector<int>(n+1, -1)); //index, length
        return memoisation(price, n-1, n, dp);
        return recursion(price, n-1, n);
    }
private: 
    //time complexity (exponential)
    //space complexity (length) 
    int recursion(int *price ,int idx, int length){
        if(idx<0 || length<=0) return 0;
        int notTake = recursion(price, idx-1, length);
        int take = 0;
        if(length-(idx+1)>=0)
            take = recursion(price, idx, length-(idx+1)) + price[idx];
        return max(notTake, take);
    }
    //time complexity (n^2)
    //space complexity (n^2) + (n)
    int memoisation(int *price ,int idx, int length,vector<vector<int>>&dp){
        if(idx<0 || length<=0) return 0;
        if(dp[idx][length]!=-1)
            return dp[idx][length];
        int notTake = memoisation(price, idx-1, length,dp);
        int take = 0;
        if(length-(idx+1)>=0)
            take = memoisation(price, idx, length-(idx+1),dp) + price[idx];
        return dp[idx][length] = max(notTake, take);
    }
    //! tabulation not working properly 
    //time complexity (n^2)
    //space complexity (n^2)
    int tabulation(int * price , int n){
        vector<vector<int>> dp(n, vector<int>(n+1, 0)); //index, length
        //at every index if we have length 1 then price will be price[0]
        for(int l=0;l<=n;l++){
            dp[0][l] = l*price[0];
        }

        for(int idx=1;idx<n;idx++){
            for(int length=1 ; length<=n ; length++){
                int notTake = dp[ idx-1][ length];
                int take = 0;
                if(length-(idx+1)>=0)
                    take = dp[idx][ length-(idx+1)] + price[idx];
                dp[idx][length] = max(notTake, take);
            }
        }
        return dp[n-1][n];
    }
    //time complexity (n^2)
    //space complexity (n)
    int optimized(int * price , int n){
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        //at every index if we have length 1 then price will be price[0]
        for(int l=0;l<=n;l++){
            prev[l] = l*price[0];
        }

        for(int idx=1;idx<n;idx++){
            for(int length=1 ; length<=n ; length++){
                int notTake = prev[ length];
                int take = 0;
                if(length-(idx+1)>=0)
                    take = curr[ length-(idx+1)] + price[idx];
                curr[length] = max(notTake, take);
            }
            prev = curr;
        }
        return prev[n];
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends