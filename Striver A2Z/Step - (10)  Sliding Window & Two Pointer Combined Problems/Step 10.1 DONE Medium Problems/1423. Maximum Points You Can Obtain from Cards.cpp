class Solution
{
private:
    int slidingWindowSolution(vector<int> &cardPoints, int k){
        long long totalSum = 0;
        for(auto x : cardPoints) totalSum += x;
        long long minSum = totalSum;
        int n = cardPoints.size();
        int windowSize = n - k;

        int si = 0, ei = 0;
        long long curSum =0;
        while(ei<n){
            curSum+=cardPoints[ei];
            if(ei-si+1 == windowSize){
                minSum = min(minSum, curSum);
                curSum-=cardPoints[si];
                si++;
            }
            ei++;
        }
        if(minSum==totalSum)
            minSum =0;
        return totalSum - minSum;    
    }
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        return slidingWindowSolution(cardPoints, k);
        //TLE
        return optimization(cardPoints, k);
        return tabulation(cardPoints, k);
        vector<vector<int>> dp(cardPoints.size(), vector<int>(cardPoints.size(), -1));
        return recursion(cardPoints, 0, cardPoints.size() - 1, k, dp);
    }

private:
    int recursion(vector<int> &cardPoints, int si, int ei, int k, vector<vector<int>> &dp)
    {
        if (si + (cardPoints.size() - ei - 1) == k)
            return 0;
        if (dp[si][ei] != -1)
            return dp[si][ei];
        int takeLeft = cardPoints[si] + recursion(cardPoints, si + 1, ei, k, dp);
        int takeRight = cardPoints[ei] + recursion(cardPoints, si, ei - 1, k, dp);
        return dp[si][ei] = max(takeLeft, takeRight);
    }
    int tabulation(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int si = n - 1; si >= 0; si--)
        {
            for (int ei = 1; ei < n; ei++)
            {
                if (si + (n - ei - 1) == k)
                    dp[si][ei] = 0;
                else
                {
                    int takeLeft = cardPoints[si] + dp[si + 1][ei];
                    int takeRight = cardPoints[ei] + dp[si][ei - 1];
                    dp[si][ei] = max(takeLeft, takeRight);
                }
            }
        }
        return dp[0][n - 1];
    }
    int optimization(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        vector<int> next(n + 1, 0);
        vector<int> prev(n + 1, 0);

        for (int si = n - 1; si >= 0; si--)
        {
            for (int ei = 1; ei < n; ei++)
            {
                if (si + (n - ei - 1) == k)
                    prev[ei] = 0;
                else
                {
                    int takeLeft = cardPoints[si] + next[ei];
                    int takeRight = cardPoints[ei] + prev[ei - 1];
                    prev[ei] = max(takeLeft, takeRight);
                }
            }
            next = prev;
        }
        return next[n - 1];
    }
};