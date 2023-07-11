//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int findMinCost(string X, string Y, int costX, int costY)
    {
        // Your code goes here
        int lcs = LCS(X, Y);
        int x = X.length();
        int y = Y.length();
        int costForX = (x - lcs) * costX;
        int costForY = (y - lcs) * costY;
        return costForX + costForY;
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

//{ Driver Code Starts.
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends