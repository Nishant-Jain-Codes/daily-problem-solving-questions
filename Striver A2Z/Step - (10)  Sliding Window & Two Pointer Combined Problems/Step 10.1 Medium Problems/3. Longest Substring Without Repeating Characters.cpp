class Solution
{
public:
    int lengthOfLongestSubstring(string S)
    {
        unordered_map<char, int> m;
        int i = 0, j = 0;
        int repeating = 0;
        int ans = 0;
        while (j < S.length())
        {
            char curChar = S[j];
            m[curChar]++;
            if (m[curChar] > 1)
            {
                repeating++;
            }
            if (repeating == 0)
            {
                ans = max(ans, j - i + 1);
                j++;
            }
            else
            {
                while (i < j && repeating > 0)
                {
                    char curChar = S[i];
                    m[curChar]--;
                    if (m[curChar] == 1)
                    {
                        repeating--;
                    }
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};