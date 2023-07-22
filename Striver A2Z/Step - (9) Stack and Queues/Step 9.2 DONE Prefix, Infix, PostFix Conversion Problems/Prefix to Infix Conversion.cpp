//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string preToInfix(string s)
    {
        // Write your code here
        stack<string> stk;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (isalpha(s[i]) || isdigit(s[i]))
            {
                string operand(1, s[i]);
                stk.push(operand);
            }
            else
            {
                string op1 = stk.top();
                stk.pop();
                string op2 = stk.top();
                stk.pop();
                string temp = "(" + op1 + s[i] + op2 + ")";
                stk.push(temp);
            }
        }
        string ans = stk.top();
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--)
    {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends