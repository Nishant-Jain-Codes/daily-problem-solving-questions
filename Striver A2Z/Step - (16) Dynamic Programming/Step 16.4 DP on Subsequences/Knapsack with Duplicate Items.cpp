//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        return optimized(N,W,val,wt);
        return tabulation(N,W,val,wt);
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return memoisation(N-1,W,val,wt,dp);
        return recursive(N-1,W,val,wt);
    }
private:
    int recursive(int idx, int W , int * val , int * wt){
        if(idx<0 || W<=0)
            return 0;
        int notTake = recursive(idx-1,W,val,wt);
        int take = 0;
        if(W-wt[idx]>=0)
            take = val[idx] + recursive(idx,W-wt[idx],val,wt);
        return max(notTake,take);
    }
    int memoisation(int idx, int W , int * val , int * wt , vector<vector<int>> & dp){
        if(idx<0 || W<=0)
            return 0;
        if(dp[idx][W]!=-1)  
            return dp[idx][W];
        int notTake = memoisation(idx-1,W,val,wt,dp);
        int take = 0;
        if(W-wt[idx]>=0)
            take = val[idx] + memoisation(idx,W-wt[idx],val,wt,dp);
        return dp[idx][W] = max(notTake,take);
    }
    int tabulation(int N, int W, int * val , int * wt){
        vector<vector<int>> dp(N+1,vector<int>(W+1,0));
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                int notTake = dp[i-1][j];
                int take = 0;
                if(j-wt[i-1]>=0)
                    take = val[i-1] + dp[i][j-wt[i-1]];
                dp[i][j] = max(notTake,take);
            }
        }
        return dp[N][W];
    }
    int optimized(int N, int W, int * val , int * wt){
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){
                int notTake = prev[j];
                int take = 0;
                if(j-wt[i-1]>=0)
                    take = val[i-1] + curr[j-wt[i-1]];
                curr[j] = max(notTake,take);
            }
            prev = curr;
        }
        return prev[W];
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends