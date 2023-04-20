// https://practice.geeksforgeeks.org/problems/maximum-nesting-depth-of-the-parentheses/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-nesting-depth-of-the-parentheses

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int maxDepth(string s) {
        // code here
        int answer = 0;
        int opC = 0;
        for(auto &x : s){
            if(x=='(')
                opC++;
            else if(x==')') {
                if(opC)
                    opC--;
            }
            answer = max(answer,opC);
        }
        return answer;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        int ans = obj.maxDepth(s);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends