#include <bits/stdc++.h> 
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
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int same = LCS(str,ptr);
    int removingCost = str.length()-same;
    int addingCost = ptr.length()-same;
    return removingCost+addingCost;
}