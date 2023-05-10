// https://practice.geeksforgeeks.org/problems/find-nth-root-of-m5843/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-nth-root-of-m
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	double multiply(double a,int b){
	    double ans = 1.0;
	    for(int i=1;i<=b;i++){
	        ans=ans*a;
	    }
	    return ans;
	}
	int NthRoot(int n, int m)
	{
	    // Code here.
	    double eps = 1e-2;
        double X = m;
        double lo =1,hi=X,mid;
        while(hi-lo>eps){
            mid = (hi+lo)/2.0;
            if(multiply(mid,n) < X)
                lo = mid;
            else
                hi = mid;
            
        }
        if(multiply(floor(hi),n)!=m)
            return -1;
       return floor(hi);
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends