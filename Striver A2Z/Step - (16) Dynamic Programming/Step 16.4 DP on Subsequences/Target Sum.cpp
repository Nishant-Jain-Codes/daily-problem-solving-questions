//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
public:
    int findTargetSumWays(vector<int>&nums ,int target) {
        //Your code here
        return countPartitions(nums.size(),target,nums);
        unordered_map<int,unordered_map<int,int>> dp;
        return memoisation(nums.size()-1, nums, target, dp);
        return recursion(nums.size()-1, nums, target);
    }
private:
    int recursion(int idx , const vector<int> & nums , int target){
        if(idx < 0)
            return target == 0;
        int negative = recursion(idx-1,nums,target+nums[idx]);
        int positive =  recursion(idx-1,nums,target-nums[idx]);
        return positive + negative;
    }
    int memoisation(int idx , const vector<int> & nums , int target,unordered_map<int,unordered_map<int,int>> & dp){
        if(idx < 0)
            return target == 0;
        if(dp[idx].find(target) != dp[idx].end())
            return dp[idx][target];
        int negative = memoisation(idx-1,nums,target+nums[idx],dp);
        int positive =  memoisation(idx-1,nums,target-nums[idx],dp);
        return dp[idx][target] =  positive + negative;
    }
private: 
    int noOfsubsetSumTok(vector<int>& arr , int n , int sum ){
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
                curr[j] = (take + notTake);
            }
            prev=curr;
        }
        return prev[sum];
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum-d < 0 || (sum-d)%2 != 0)
            return 0;
        return noOfsubsetSumTok(arr,n ,(sum-d)/2);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends