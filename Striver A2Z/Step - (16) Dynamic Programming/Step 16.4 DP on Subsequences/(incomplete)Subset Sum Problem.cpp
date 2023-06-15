//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++
// Constraints:
// 1 <= N <= 100
// 1<= arr[i] <= 100
// 1<= sum <= 10^5

class Solution{   
private:
    bool recursive(int idx , int sum , vector<int>& arr){
        if(sum == 0) return true;
        if(sum<0 || idx>=arr.size()) return false;
        return recursive(idx+1,sum-arr[idx],arr) || recursive(idx+1,sum,arr);
    }
    int memoisation(int idx , int sum , vector<int>& arr , vector<vector<int>>& dp){
        if(sum == 0) return true;
        if(sum<0 || idx>=arr.size()) return false;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        return dp[idx][sum]=recursive(idx+1,sum-arr[idx],arr) || recursive(idx+1,sum,arr);
    }
    bool tabulation(vector<int>& arr,int sum){
        int maxSum = 0;
        for(int i=0;i<arr.size();i++) maxSum+=arr[i];
        vector<vector<bool>> dp(arr.size()+1,vector<int>(maxSum+1,false)); 
        for(int i=0;i<=arr.size();i++){
            dp[i][0]=true;
            dp[i][arr[i]]=true;
        }
        for(int i=1;i<=arr.size();i++){
            for(int j=1;j<=maxSum;j++){
                if(j-arr[i-1]>=0) dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[arr.size()][sum];

    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        //tabulation
        return tabulation(arr,sum);
        //memoisation
        int maxSum = 0;
        for(int i=0;i<arr.size();i++) maxSum+=arr[i];
        vector<vector<int>> dp(arr.size()+1,vector<int>(maxSum+1,-1));
        if(memoisation(0,sum,arr,dp)==1) return true;
            return false;
        //recursive
        return recursive(0,sum,arr);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends