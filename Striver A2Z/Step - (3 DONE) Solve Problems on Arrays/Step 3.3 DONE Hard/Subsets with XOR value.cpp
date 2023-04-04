// https://practice.geeksforgeeks.org/problems/subsets-with-xor-value2023/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=subsets-with-xor-value

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int dp[21][200];
    int rec(int i,int cur,vector<int> arr,int K){
        if(i==arr.size())
            return cur==K;
        int ans=0;
        if(dp[i][cur]!=-1)
            return dp[i][cur];
        int a1 = rec(i+1,cur,arr,K);
        int a2 = rec(i+1,cur^arr[i],arr,K);
        ans=a1+a2;
        dp[i][cur]=ans;
        return ans;
    }
    int subsetXOR(vector<int> arr, int N, int K) {
        // code here
        memset(dp,-1,sizeof(dp));
        return rec(0,0,arr,K);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}
// } Driver Code Ends