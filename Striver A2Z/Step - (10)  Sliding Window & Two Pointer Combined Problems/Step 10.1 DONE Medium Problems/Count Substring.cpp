//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countSubstring(string s)
    {
        // Code here
        int n = s.size();
        vector<int> count(3, 0);
        int ans = 0, i = 0, j = 0;

        for (j = 0; j < n; ++j)
        {
            count[s[j] - 'a']++;
            while (count[0] && count[1] && count[2])
            {
                count[s[i] - 'a']--;
                i++;
            }
            ans += i;
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends