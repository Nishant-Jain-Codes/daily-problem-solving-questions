//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
private: 
    //time complexity : O(n^k)
    //space complexity : O(n)
    int recursion(vector<int>& height , int n , int k){
        if(n==0)
            return 0;
        int minCost = INT_MAX;
        for(int i = 1 ; i <= k ; i++){
            if(n-i >= 0)
            minCost = min(minCost , recursion(height , n-i , k) + abs(height[n] - height[n-i]));
        }
        return minCost;
    }
    //time complexity : O(n*k)
    //space complexity : O(n) + O(n)
    int memoisation(vector<int>& height , int n , int k,vector<int>& dp){
        if(n==0)
            return 0;
        if(dp[n]!=-1)
            return  dp[n];
        int minCost = INT_MAX;
        for(int i = 1 ; i <= k ; i++){
            if(n-i >= 0)
            minCost = min(minCost , recursion(height , n-i , k) + abs(height[n] - height[n-i]));
        }
        return dp[n]=minCost;
    }
    //time complexity : O(n*k)
    //space complexity : O(n)
    int tabulation(vector<int>& height, int n, int k){
        vector<int> dp(n+1,-1);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int minCost = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0)
                    minCost = min(minCost , dp[i-j] + abs(height[i] - height[i-j]));
            }
            dp[i] = minCost;
        }
        return dp[n-1];
    }
public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        return tabulation(height , n , k);
        vector<int> dp(n, -1);
        return memoisation(height , n-1 , k , dp);
        return recursion(height,n-1, k);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends