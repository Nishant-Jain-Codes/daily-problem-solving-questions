//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int NumberofLIS(int n, vector<int> &nums)
    {
        // Code here
        vector<int> dp(nums.size(), 1);
        vector<int> freq(nums.size(), 1);
        int ansLen = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    if (dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        freq[i] = freq[j];
                    }
                    else if (dp[i] == dp[j] + 1)
                    {
                        // if the length of the current subsequence is equal to the length of the subsequence ending at j
                        // then we add the freq of the subsequence ending at j to the freq of the subsequence ending at i
                        freq[i] += freq[j];
                    }
                }
            }
            ansLen = max(ansLen, dp[i]);
        }
        int ansFreq = 0;
        // summing up all the freq of the longest increasing subsequence
        for (int i = 0; i < nums.size(); i++)
        {
            if (dp[i] == ansLen)
                ansFreq += freq[i];
        }

        return ansFreq;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            long long x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.NumberofLIS(n, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends