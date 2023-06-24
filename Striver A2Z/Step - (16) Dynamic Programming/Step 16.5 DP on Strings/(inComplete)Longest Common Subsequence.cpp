//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        return optimized(x, y, s1, s2);
        return tabulation(x, y, s1, s2);
        vector<vector<int>> dp(x, vector<int>(y, -1));
        return memoisation(x-1, y-1, s1, s2, dp);
        return recursion(x-1, y-1, s1, s2);
    }
private:
    int recursion(int i , int j , const string & s1, const string & s2){
        if(i<0 || j<0) return 0;
        if(s1[i]==s2[j])
            return recursion(i-1, j-1, s1, s2) + 1;
        return max(recursion(i-1, j, s1, s2), recursion(i, j-1, s1, s2));
    }
    int memoisation(int i , int j , const string & s1, const string & s2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return dp[i][j] = memoisation(i-1, j-1, s1, s2,dp) + 1;
        return dp[i][j] =  max(memoisation(i-1, j, s1, s2,dp), memoisation(i, j-1, s1, s2,dp));
    }
    int tabulation(int x, int y, string s1, string s2){
        vector<vector<int>> dp(x+1, vector<int>(y+1, 0));
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
    int optimized(int x, int y, string s1, string s2){
        vector<int> prev(max(x,y)+1, 0);
        vector<int> curr(max(x,y)+1, 0);
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1])
                    curr[j] = prev[j-1] + 1;
                else 
                    curr[j] = max(prev[j], curr[j-1]);
            }
            prev = curr;
        }
        return curr[y];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends