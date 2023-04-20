// https://practice.geeksforgeeks.org/problems/outermost-parentheses/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    string removeOuter(string& str) {
        // code here
        string answer="";
        bool openFound = false;
        int opC =0;
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(ch=='(')
                if(!openFound)
                    openFound = !openFound;
                else 
                    {
                        answer+=ch;
                        opC++;
                    }
            else
                if(opC==0)
                    openFound = !openFound;
                else 
                {
                    answer+=ch;
                    opC--;
                }
            
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

        cout << obj.removeOuter(s) << "\n";
    }
}
// } Driver Code Ends