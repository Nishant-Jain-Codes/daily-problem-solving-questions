//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

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
        vector<vector<bool>> dp(arr.size()+1,vector<bool>(sum+1,false));
        for(int i=0;i<=arr.size();i++) dp[i][0] = true;//can make sum == 0 at any index
        dp[0][arr[0]] = true;//can make sum == first element at first index
        for(int idx = 1; idx<=arr.size();idx++){
            for(int target = 1;target<=sum ; target++){
                bool notTake = dp[idx-1][target];
                bool take = false;
                if(target-arr[idx]>=0) take = dp[idx-1][target-arr[idx]];
                dp[idx][target] = take || notTake;
            }
        }
        return dp[arr.size()-1][sum];

    }
public:
    bool isSubsetSum(vector<int>arr, int sum){
        //tabulation
        return tabulation(arr,sum);
        //memoisation
        vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1));
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