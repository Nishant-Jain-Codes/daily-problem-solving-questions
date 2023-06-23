//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    const int mod = 1e9 + 7;
private: 
    int recursion(int arr[] , int idx , int sum){
        if(idx<0){
            if(sum==0)
                return 1;
            else
                return 0;
        }
        int take = recursion(arr,idx-1,sum-arr[idx]);
        int notTake = recursion(arr,idx-1,sum);
        return take+notTake;
    }
    int memoisation(int arr[], int idx, int sum, vector<vector<int>> &dp) {
        if (idx < 0) {
            if (sum == 0)
                return 1;
            else
                return 0;
        }
        if(sum<0)
            return 0;
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        int take = memoisation(arr, idx - 1, sum - arr[idx], dp)%mod;
        int notTake = memoisation(arr, idx - 1, sum, dp)%mod;
        return dp[idx][sum] = (take + notTake)%mod;
    }

    int tabulation(int * arr ,int n , int sum){
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1; // sum = 0 is possible for every index
        }
        if(arr[0]<=sum)
            dp[0][arr[0]]++;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int take = 0;
                if(j - arr[i] >=0){
                    take = dp[i - 1 ][j - arr[i]];
                }
                    
                int notTake = dp[i - 1][j];
                dp[i][j] = (take + notTake)%mod;
            }
        }
        return dp[n-1][sum];
    }
    int optimized(int * arr , int n , int sum ){
        vector<int> prev(sum+1,0);
        vector<int> curr(sum+1,0);
        prev[0] = 1;
        curr[0] = 1;
        if(arr[0]<=sum)
            prev[arr[0]]++;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int take = 0;
                if(j - arr[i] >=0){
                    take = prev[j - arr[i]];
                }
                    
                int notTake = prev[j];
                curr[j] = (take + notTake)%mod;
            }
            prev=curr;
        }
        return prev[sum];
    }
public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes 
        return optimized(arr,n,sum);
        return tabulation(arr,n,sum);

        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return memoisation(arr,n-1,sum,dp);
        
        return recursion(arr,n-1,sum);
	}
	  
};





//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends