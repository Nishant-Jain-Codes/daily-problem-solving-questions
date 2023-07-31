//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
public:
    int maxCoins(int N, vector<int> &nums) {
        // code here
        vector<int> arr(nums.size() + 2, 1);
        for (int i = 0; i < nums.size(); i++)
            arr[i + 1] = nums[i];
        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, 0));
        for (int si = nums.size(); si >= 1; si--)
        {
            for (int ei = 1; ei <= nums.size(); ei++)
            {
                if (si > ei)
                    dp[si][ei] = 0;
                else
                {

                    int cost = INT_MIN;
                    for (int k = si; k <= ei; k++)
                    {
                        int curCost = arr[si - 1] * arr[k] * arr[ei + 1];
                        int leftCost = dp[si][k - 1];
                        int rightCost = dp[k + 1][ei];
                        cost = max(cost, leftCost + curCost + rightCost);
                    }
                    dp[si][ei] = cost;
                }
            }
        }
        return dp[1][nums.size()];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends