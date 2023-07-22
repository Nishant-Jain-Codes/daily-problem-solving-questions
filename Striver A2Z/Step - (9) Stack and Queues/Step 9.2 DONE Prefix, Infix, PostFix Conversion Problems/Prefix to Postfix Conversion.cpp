//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string preToPost(string s) 
    {
        string ans = "";
        stack<string> st;
        for(int i=s.length()-1;i>=0;i--){
            if(isdigit(s[i])||isalpha(s[i])){
                string operand(1,s[i]);
                st.push(operand);
            }
            else{
                string op1 = st.top();
                st.pop();
                string op2 = st.top();
                st.pop();
                st.push(op1+op2+s[i]);
            }
        }
        return st.top();
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
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends