// https://practice.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category=&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=max-sum-in-sub-arrays


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends

    // !logic 
    // find maximum of A[i]+aA[i+1]
    
class Solution{
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long int sum,ans=INT_MIN;
        for(int i=0;i<N-1;i++){
            sum= arr[i]+arr[i+1];
            ans = max(sum,ans);
        }
        return ans;
    }
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends