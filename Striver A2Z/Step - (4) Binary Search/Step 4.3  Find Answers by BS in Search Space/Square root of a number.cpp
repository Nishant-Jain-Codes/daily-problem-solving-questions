//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// https://practice.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
double eps = 1e-2;
        double X = x;
        double lo =1,hi=X,mid;
        while(hi-lo>eps){
            mid = (hi+lo)/2;
            if(mid * mid < X)
                lo = mid;
            else 
                hi = mid;
        }
        return floor(hi);
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends