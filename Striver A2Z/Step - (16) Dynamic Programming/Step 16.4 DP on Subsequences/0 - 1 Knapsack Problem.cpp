//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
        return optimized(W,n,wt,val);
        return tabulation(W,n,wt,val);
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return memoisation(W,n-1,wt,val,dp);
        return recursion(W,n-1,wt,val);
    }
private:
    int recursion(int leftW ,int curIdx , int * wt , int * val){
        if(curIdx==-1 || leftW == 0){
            return 0;
        }
        int take = 0 ;
        if(leftW >= wt[curIdx]){
            take = recursion(leftW - wt[curIdx] , curIdx - 1 , wt , val) + val[curIdx];
        }
        int notTake = recursion(leftW , curIdx - 1 , wt , val);
        return max(take , notTake);
    }
    int memoisation(int leftW ,int curIdx , int * wt , int * val,vector<vector<int>> &dp){
        if(curIdx==-1 || leftW == 0){
            return 0;
        }
        if(dp[curIdx][leftW] != -1){
            return dp[curIdx][leftW];
        }
        int take = 0 ;
        if(leftW >= wt[curIdx]){
            take = memoisation(leftW - wt[curIdx] , curIdx - 1 , wt , val,dp) + val[curIdx];
        }
        int notTake = memoisation(leftW , curIdx - 1 , wt , val,dp);
        return dp[curIdx][leftW] = max(take , notTake);
    }
    int tabulation(int W ,int n , int * wt , int * val){
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        for (int j = 0; j <= W; j++) {
            if (j >= wt[0]) {
                dp[0][j] = val[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int take = 0 ;
                if(j >= wt[i]){
                    take = dp[ i - 1][ j - wt[i]] + val[i];
                }
                int notTake = dp[ i - 1][ j];
                dp[i][j] = max(take , notTake);
            }
        }
        return dp[n-1][W];
    }
    int optimized(int W ,int n , int * wt , int * val){
        vector<int> prev(W+1,0) , curr(W+1,0);
        for (int j = 0; j <= W; j++) {
            if (j >= wt[0]) {
                prev[j] = val[0];
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=W;j++){
                int take = 0 ;
                if(j >= wt[i]){
                    take = prev[ j - wt[i]] + val[i];
                }
                int notTake = prev[ j];
                curr[j] = max(take , notTake);
            }
            prev = curr;
        }
        return prev[W];
    }
};

//{ Driver Code Starts.

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends