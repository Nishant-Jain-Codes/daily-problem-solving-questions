//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution2
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        // time complexity = O(nlogn) runs fine (1120 /1120 )Accepted
        return binarySearchApproach(nums);
        // all the below are giving tle (1087 /1120 )Time Limit Exceeded
        return differentApproach(nums);
        return spaceOptimized(nums);
        return tabulation(nums);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return memoization(nums, 0, -1, dp);
        return recursion(nums, 0, -1); // nums,idx,prevIdx
    }
    // time complexity = O(2^n)
    // space complexity = O(n) stack space
    int recursion(vector<int> &nums, int idx, int prevIdx)
    {
        if (idx == nums.size())
            return 0;
        int taken = 0, notTaken = 0;
        if (prevIdx == -1 || nums[idx] > nums[prevIdx])
        {
            taken = 1 + recursion(nums, idx + 1, idx);
        }
        notTaken = recursion(nums, idx + 1, prevIdx);
        return max(taken, notTaken);
    }
    // time complexity = O(n^2)
    // space complexity = O(n^2) + O(n) stack space
    int memoization(vector<int> &nums, int idx, int prevIdx, vector<vector<int>> &dp)
    {
        if (idx == nums.size())
            return 0;
        int taken = 0, notTaken = 0;
        if (dp[idx][prevIdx + 1] != -1)
            return dp[idx][prevIdx + 1];
        if (prevIdx == -1 || nums[idx] > nums[prevIdx])
        {
            taken = 1 + memoization(nums, idx + 1, idx, dp);
        }
        notTaken = memoization(nums, idx + 1, prevIdx, dp);
        return dp[idx][prevIdx + 1] = max(taken, notTaken);
    }
    // time complexity = O(n^2)
    // space complexity = O(n^2)
    int tabulation(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--)
            {
                int taken = 0, notTaken = 0;
                if (prevIdx == -1 || nums[idx] > nums[prevIdx])
                {
                    taken = 1 + dp[idx + 1][idx + 1];
                }
                notTaken = dp[idx + 1][prevIdx + 1];
                dp[idx][prevIdx + 1] = max(taken, notTaken);
            }
        }
        return dp[0][0];
    }
    // time complexity = O(n^2)
    // space complexity = O(n)
    int spaceOptimized(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> curr(n + 1, 0);
        vector<int> after(n + 1, 0);
        for (int idx = n - 1; idx >= 0; idx--)
        {
            for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--)
            {
                int taken = 0, notTaken = 0;
                if (prevIdx == -1 || nums[idx] > nums[prevIdx])
                {
                    taken = 1 + after[idx + 1];
                }
                notTaken = after[prevIdx + 1];
                curr[prevIdx + 1] = max(taken, notTaken);
            }
            after = curr;
        }
        return curr[0];
    }
    // time complexity = O(n^2)
    // space complexity = O(n)
    int differentApproach(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    // time complexity = O(nlogn)
    // space complexity = O(n)
    int binarySearchApproach(vector<int> &nums)
{
    vector<int> dp;
    dp.push_back(nums[0]); 
    // Initialize the dynamic programming (DP) vector with the first element of 'nums'

    // Iterate through the elements of 'nums' starting from the second element
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > dp.back())
        {
            // If the current element is greater than the last element in 'dp',
            // we can extend the longest increasing subsequence (LIS) by appending the current element
            dp.push_back(nums[i]);
        }
        else
        {
            // If the current element is not greater than the last element in 'dp',
            // we need to find the index where the current element can be inserted while maintaining a sorted order
            int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();

            if (idx < dp.size())
                dp[idx] = nums[i]; // Replace the element at index 'idx' with the current element
            else
                dp[0] = nums[i]; // If 'idx' is out of range, replace the first element of 'dp' with the current element
        }
    }
    return dp.size(); // Return the size of the LIS
}

};

class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<int> nums(a, a + n);
        Solution2 s;
        return s.lengthOfLIS(nums);
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends