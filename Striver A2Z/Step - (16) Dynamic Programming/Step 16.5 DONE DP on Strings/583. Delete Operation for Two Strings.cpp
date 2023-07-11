class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int lcs = LCS(word1, word2);
        return word1.length() + word2.length() - 2 * lcs;
    }

private:
    int LCS(string s1, string s2)
    {
        int x = s1.length();
        int y = s2.length();
        vector<int> prev(max(x, y) + 1, 0);
        vector<int> curr(max(x, y) + 1, 0);

        for (int i = 1; i <= x; i++)
        {
            for (int j = 1; j <= y; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                    curr[j] = prev[j - 1] + 1;
                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }
        return curr[y];
    }
};