class Solution
{
public:
    int maxCoins(vector<int> &nums)
    {
        return tabulation(nums);
        vector<int> arr(nums.size() + 2, 1);
        for (int i = 0; i < nums.size(); i++)
            arr[i + 1] = nums[i];
        vector<vector<int>> dp(nums.size() + 2, vector<int>(nums.size() + 2, -1));
        return memoization(arr, 1, nums.size(), dp);
        return recursion(arr, 1, nums.size());
    }

private:
    // time complexity = O(exp)
    // space complexity = O(n) stack space
    int recursion(vector<int> &arr, int si, int ei)
    {
        if (si > ei)
            return 0;
        int cost = INT_MIN;
        for (int k = si; k <= ei; k++)
        {
            int curCost = arr[si - 1] * arr[k] * arr[ei + 1];
            int leftCost = recursion(arr, si, k - 1);
            int rightCost = recursion(arr, k + 1, ei);
            cost = max(cost, leftCost + curCost + rightCost);
        }
        return cost;
    }
    // time complexity = O(n^3)
    // space complexity = O(n^2)  + O(n)stack space
    int memoization(vector<int> &arr, int si, int ei, vector<vector<int>> &dp)
    {
        if (si > ei)
            return 0;
        if (dp[si][ei] != -1)
            return dp[si][ei];
        int cost = INT_MIN;
        for (int k = si; k <= ei; k++)
        {
            int curCost = arr[si - 1] * arr[k] * arr[ei + 1];
            int leftCost = memoization(arr, si, k - 1, dp);
            int rightCost = memoization(arr, k + 1, ei, dp);
            cost = max(cost, leftCost + curCost + rightCost);
        }
        return dp[si][ei] = cost;
    }
    // time complexity = O(n^3)
    // space complexity = O(n^2)
    int tabulation(vector<int> &nums)
    {
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