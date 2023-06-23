//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
    const int mod = 1e9 + 7;
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
                curr[j] = (take + notTake)%mod;
            }
            prev=curr;
        }
        return prev[sum];
    }
public:
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
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends