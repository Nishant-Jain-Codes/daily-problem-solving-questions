class Solution
{
public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        string lcs = LCS(str1, str2);
        int lcsIdx = 0;
        int str1Idx = 0;
        int str2Idx = 0;
        string ans = "";
        while (lcsIdx < lcs.length())
        {
            while (str1[str1Idx] != lcs[lcsIdx])
            {

                ans.push_back(str1[str1Idx]);
                str1Idx++;
            }
            while (str2[str2Idx] != lcs[lcsIdx])
            {

                ans.push_back(str2[str2Idx]);
                str2Idx++;
            }
            ans.push_back(lcs[lcsIdx]);
            str1Idx++;
            str2Idx++;
            lcsIdx++;
        }
        while (str1Idx < str1.length())
        {
            ans.push_back(str1[str1Idx]);
            str1Idx++;
        }
        while (str2Idx < str2.length())
        {
            ans.push_back(str2[str2Idx]);
            str2Idx++;
        }
        return ans;
    }

private:
    string LCS(string &s1, string &s2)
    {
        int x = s1.size(), y = s2.size();
        vector<vector<int>> dp(x + 1, vector<int>(y + 1, 0));
        // filling up the dp table
        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        int lcs = dp[x][y];
        string ans = "";
        for (int i = 0; i < lcs; i++)
            ans.push_back('#');
        int idx = lcs - 1;
        int i = x, j = y;
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans[idx] = s1[i - 1];
                i--;
                j--;
                idx--;
            }
            else
            {
                if (dp[i - 1][j] > dp[i][j - 1])
                    i--;
                else
                    j--;
            }
        }
        if (lcs == 0)
            return "";
        return ans;
    }
};