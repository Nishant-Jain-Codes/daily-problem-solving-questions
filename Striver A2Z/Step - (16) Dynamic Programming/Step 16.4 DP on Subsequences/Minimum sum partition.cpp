//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

public:
	int minDifference(int nums[], int n)  { 
	    // Your code goes here
        return tabulation(n,nums);
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return memoisation(n-1,0,sum,nums,dp);
        return recursion(n-1,0,sum,nums);
	} 
private:
    int tabulation(int n , int * nums){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
        vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
        dp[0][nums[0]] = true;
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<=sum;j++){
                bool notTake = dp[i-1][j];
                bool take = false;
                if(j-nums[i]>=0){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j]= notTake || take;
            }
        }
        int ans = INT_MAX;
        for(int i=0;i<=(sum+1)/2;i++){
            if(dp[n-1][i]){
                int s1 = i;
                int s2 = sum-i;
                ans = min(ans, abs(s1-s2));
            }
        }
        return ans;
    }
    int memoisation(int idx ,int curSum, int sum , int* nums,vector<vector<int>>&dp){
        if(idx<0){
            int sum1stHalf = curSum ;
            int sum2ndHalf = sum - curSum;
            return abs(sum1stHalf-sum2ndHalf);
        }
        if(dp[idx][curSum]!=-1){
            return dp[idx][curSum];
        }
        int left = recursion(idx-1,curSum+nums[idx],sum,nums);
        int right = recursion(idx-1,curSum,sum,nums);
        return dp[idx][curSum] = min(left,right);
    }
    int recursion(int idx ,int curSum, int sum , int* nums){
        if(idx<0){
            int sum1stHalf = curSum ;
            int sum2ndHalf = sum - curSum;
            return abs(sum1stHalf-sum2ndHalf);
        }
        int left = recursion(idx-1,curSum+nums[idx],sum,nums);
        int right = recursion(idx-1,curSum,sum,nums);
        return min(left,right);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends