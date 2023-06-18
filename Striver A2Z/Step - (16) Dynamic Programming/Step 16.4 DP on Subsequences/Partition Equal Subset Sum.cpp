//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
private: 
    
    bool tabulation(int N , int * arr , int sum){
        int sum1 = 1e6;
    vector<bool> prev(sum1+1, false),curr(sum1+1,false);
        prev[0] = true;
        curr[0] = true;
        prev[arr[0]] = true;
        for(int i = 1 ; i<N ;i++){
            for(int j = 1 ; j<=sum ; j++){
                bool notTake = prev[j];
                bool take = false;
                if(j-arr[i]>=0) take = prev[j-arr[i]];
                curr[j] = take || notTake;
            }
            prev = curr;
        }
        return prev[sum];
    }
public:
    int equalPartition(int N, int arr[])
    {
        int Sum = 0;
        for(int i=0;i<N;i++)
            Sum += arr[i];
        if(Sum%2!=0)
            return 0;
        Sum /= 2;
        return tabulation(N, arr, Sum);
    }
};




//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends