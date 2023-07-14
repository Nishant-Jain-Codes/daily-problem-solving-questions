class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        // sort according to size
        sort(words.begin(), words.end(),
            [&](string &a, string &b)
            { return a.length() < b.length(); }
        );
        vector<int> dp(words.size(), 1);
        int ans = 1;
        for (int i = 1; i < words.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (isPredecessor(words[j], words[i]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }

private:
    bool isPredecessor(string &a, string &b)
    {
        if (a.size() + 1 != b.size())
            return false;
        int i = 0, j = 0;
        int notMatch = 0;

        while (i < a.size() && j < b.size())
        {
            if (a[i] == b[j])
            {
                i++;
                j++;
            }
            else
            {
                notMatch++;
                j++;
            }
        }
        return notMatch <= 1;
    }
};