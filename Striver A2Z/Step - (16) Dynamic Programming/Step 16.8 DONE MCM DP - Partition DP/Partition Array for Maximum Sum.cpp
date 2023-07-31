//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int> dp(arr.size()+1, 0);
        for (int si = arr.size() - 1; si >= 0; si--)
        {
            int ans = INT_MIN;
            int maxInPartition = arr[si];
            for (int partition = si; partition < arr.size() && partition - si + 1 <= k; partition++)
            {
                maxInPartition = max(maxInPartition, arr[partition]);
                int remainingPartition = dp[partition + 1];
                ans = max(ans, maxInPartition * (partition - si + 1) + remainingPartition);
            }
            dp[si] = ans;
        }
        return dp[0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            int x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.solve(n,k,arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends