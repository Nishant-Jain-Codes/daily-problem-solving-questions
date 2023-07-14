class Solution
{
public:
    // time complexity - O(n^2)
    // space complexity - O(n)
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1);
        vector<int> parent(nums.size(), -1);
        int maxLen = 1, maxIdx = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                maxIdx = i;
            }
        }
        vector<int> ans;
        while (maxIdx != -1)
        {
            ans.push_back(nums[maxIdx]);
            maxIdx = parent[maxIdx];
        }
        return ans;
    }
};