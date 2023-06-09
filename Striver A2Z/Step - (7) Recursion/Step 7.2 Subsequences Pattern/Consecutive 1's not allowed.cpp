//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++

//getting TLE
class Solution{
    int mod = 1e9+7;
private: 
    ll helper(int n , char lastChar){
        if(n==0){
            return 1;
        }
        if(lastChar==' '||lastChar=='0'){ // if no character selected or zero is selected we can select both 0 and 1
            return (helper(n-1,'0')%mod + helper(n-1,'1')%mod)%mod;
        }
        else{ // if last selected char is 1 we cant select 1 again
            return helper(n-1,'0');
        }
    }
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
        return helper(n,' ');
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
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends