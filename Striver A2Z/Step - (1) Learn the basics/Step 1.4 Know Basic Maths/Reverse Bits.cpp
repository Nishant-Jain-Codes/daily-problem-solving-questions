// https://practice.geeksforgeeks.org/problems/reverse-bits3556/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long X) {
        // code here
        int size = 32;
        long long ans=0;
        while(size)
        {
            ans<<=1;
            if(X&1==1)
                ans^=1;
            X>>=1;
            size--;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends