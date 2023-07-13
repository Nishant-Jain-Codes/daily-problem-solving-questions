//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // time complexity = O(n^2)
    // space complexity = O(n)
    vector<int> longestIncreasingSubsequence(int n, vector<int> &arr)
    {
        // Code here
        vector<int> dp(n, 1);
        vector<int> parent(n,-1);
        int maxLen = 1, maxIdx = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    parent[i] = j;
                }
            }
            if(maxLen<dp[i]){
                maxLen = dp[i];
                maxIdx = i;
            }
        }
        vector<int> answer;
        while(maxIdx!=-1){
            answer.push_back(arr[maxIdx]);
            maxIdx = parent[maxIdx];
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends