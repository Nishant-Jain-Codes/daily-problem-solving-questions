/*

https://practice.geeksforgeeks.org/problems/armstrong-numbers2727/1

*/

//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int ans=0;
        int temp=n;
        while(temp>0)
        {   int mult=temp%10;
            ans+=(mult*mult*mult);
            temp/=10;
        }
        if(ans==n)
        return "Yes";
        else 
        return "No";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends