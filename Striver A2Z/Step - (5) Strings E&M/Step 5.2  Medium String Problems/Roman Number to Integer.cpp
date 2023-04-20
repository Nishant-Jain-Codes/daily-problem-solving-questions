// https://practice.geeksforgeeks.org/problems/roman-number-to-integer3201/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=roman-number-to-integer

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        unordered_map<char,int> val= {
        {'I',1},
        {'V',5},
        {'X',10},
        {'L',50},
        {'C',100},
        {'D',500},
        {'M',1000}
    };
    if(s.length()==0)
        return 0;
    int ans =val[s[s.length()-1]];
    for(int i=s.length()-1;i>0;i--){
        if(val[s[i]]>val[s[i-1]])
            ans -= val[s[i-1]];
        else 
            ans += val[s[i-1]];
    }
    return ans;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends