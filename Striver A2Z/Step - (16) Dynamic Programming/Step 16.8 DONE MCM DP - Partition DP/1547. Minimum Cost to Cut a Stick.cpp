class Solution
{
public:
    int minCost(int n, vector<int> &cuts)
    {
        // precomputation settings
        vector<int> &newCuts = cuts;
        newCuts.push_back(0);
        newCuts.push_back(n);
        sort(newCuts.begin(), newCuts.end());
        return tabulation(newCuts);
        // memoization solution
        vector<vector<int>> dp(newCuts.size(), vector<int>(newCuts.size(), -1));
        return memoization(newCuts, 0, newCuts.size() - 1, dp);
        // recursion
        return recursion(newCuts, 0, newCuts.size() - 1);
    }

private:
    // time complexity: O(exp)
    // space complexity: O(n) (stack space)
    int recursion(vector<int> &newCuts, int si, int ei)
    {
        if (ei - si <= 1)
            return 0;
        int costForCurCut = newCuts[ei] - newCuts[si];
        int minCost = INT_MAX;
        for (int cut = si + 1; cut < ei; cut++)
        {
            int leftCutCost = recursion(newCuts, si, cut);
            int rightCutCost = recursion(newCuts, cut, ei);
            minCost = min(minCost, leftCutCost + rightCutCost);
        }
        return minCost + costForCurCut;
    }
    // time complexity: O(n^3)
    // space complexity: O(n^2) + O(n) (stack space)
    int memoization(vector<int> &newCuts, int si, int ei, vector<vector<int>> &dp)
    {
        if (ei - si <= 1)
            return 0;
        if (dp[si][ei] != -1)
            return dp[si][ei];
        int costForCurCut = newCuts[ei] - newCuts[si];
        int minCost = INT_MAX;
        for (int cut = si + 1; cut < ei; cut++)
        {
            int leftCutCost = memoization(newCuts, si, cut, dp);
            int rightCutCost = memoization(newCuts, cut, ei, dp);
            minCost = min(minCost, leftCutCost + rightCutCost);
        }
        return dp[si][ei] = minCost + costForCurCut;
    }
    // time complexity: O(n^3)
    // space complexity: O(n^2)
    int tabulation(vector<int> &newCuts)
    {
        vector<vector<int>> dp(newCuts.size(), vector<int>(newCuts.size(), 0));
        int n = newCuts.size();
        
        for (int si = n-1; si >= 0; si--)
        {
            for (int ei = 0; ei < n; ei++)
            {
                if (ei - si <= 1)
                    dp[si][ei] = 0;
                else{
                    int costForCurCut = newCuts[ei] - newCuts[si];
                    int minCost = INT_MAX;
                    for (int cut = si + 1; cut < ei; cut++)
                    {
                        int leftCutCost = dp[si][cut];
                        int rightCutCost = dp[cut][ei];
                        minCost = min(minCost, leftCutCost + rightCutCost);
                    }
                    dp[si][ei] = minCost + costForCurCut;
                }
            }
        }
        return dp[0][n-1];
    }
};