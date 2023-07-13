class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        //return tabulation(nums);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int ans =  memoization(nums, 0, -1, dp);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= n; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return ans;
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
    
};