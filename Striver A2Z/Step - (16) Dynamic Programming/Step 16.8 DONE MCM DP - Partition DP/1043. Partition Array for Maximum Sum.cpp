class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        return tabulation(arr, k);
        vector<int> dp(arr.size(), -1);
        return memoization(arr, k, 0, dp);
        return recursion(arr, k, 0);
    }

private:
    int recursion(vector<int> &arr, int k, int si)
    {
        if (si == arr.size())
            return 0;
        int ans = INT_MIN;
        int maxInPartition = arr[si];
        for (int partition = si; partition < arr.size() && partition - si + 1 <= k; partition++)
        {
            maxInPartition = max(maxInPartition, arr[partition]);
            int remainingPartition = recursion(arr, k, partition + 1);
            ans = max(ans, maxInPartition * (partition - si + 1) + remainingPartition);
        }
        return ans;
    }
    int memoization(vector<int> &arr, int k, int si, vector<int> &dp)
    {
        if (si == arr.size())
            return 0;
        if (dp[si] != -1)
            return dp[si];
        int ans = INT_MIN;
        int maxInPartition = arr[si];
        for (int partition = si; partition < arr.size() && partition - si + 1 <= k; partition++)
        {
            maxInPartition = max(maxInPartition, arr[partition]);
            int remainingPartition = memoization(arr, k, partition + 1, dp);
            ans = max(ans, maxInPartition * (partition - si + 1) + remainingPartition);
        }
        return dp[si] = ans;
    }
    int tabulation(vector<int> &arr, int k)
    {
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