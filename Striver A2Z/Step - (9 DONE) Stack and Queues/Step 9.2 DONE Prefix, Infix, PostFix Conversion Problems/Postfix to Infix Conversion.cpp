//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    string postToInfix(string s) {
        stack<string> stk;
        for (int i = 0; i < s.length(); i++) {
            if (isalpha(s[i]) || isdigit(s[i])) {
                string operand(1, s[i]);
                stk.push(operand);
            } else {
                string op2 = stk.top();
                stk.pop();
                string op1 = stk.top();
                stk.pop();

                // string temp = op1 + s[i] + op2;
                stk.push("(" + op1 + s[i] + op2 + ")");
            }
        }
        string ans = stk.top();
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string postfix;
        cin >> postfix;
        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToInfix(postfix) << endl;

        // cout << "~\n";
    }
    fclose(stdout);

    return 0;
}

// } Driver Code Ends