// https://practice.geeksforgeeks.org/problems/lcm-and-gcd4516/1

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long gcd_f(long long a , long long b){
        if(b==0)
            return a;
        else 
            return gcd_f(b,a%b);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long gcd = gcd_f(A,B);
        long long lcm = (A*B)/gcd;
        vector<long long > ans;
        ans.push_back(lcm);
        ans.push_back(gcd);
        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends