// https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1

//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int n)
    {
        // Write Your Code here
        long long ans =0;
        for(int i=1;i<=n;i++){
            ans+=((n/i)*i);
            //n/i no of ints divisble by i
            //*i to get the value since n/i will only give the quantity 
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends