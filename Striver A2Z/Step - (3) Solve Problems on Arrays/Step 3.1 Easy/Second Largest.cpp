/*
https://practice.geeksforgeeks.org/problems/second-largest3735/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=second-largest
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	// in 2 traversals
	int print2largest(int arr[], int n) {
	    // code here
	    int M1=-1,M2=-1;
	    for(int i=0;i<n;i++)
	    {
	        int x = arr[i];
	        M1=max(M1,x);
	        
	    }
	    for(int i=0;i<n;i++)
	    {
	        int x = arr[i];
	        if(x!=M1)
	            M2=max(M2,x);
	    }
	    return M2;
	}
	
	// in one traversal
	
	int print2largest(int arr[], int n) {
	    // code here
	   if(n<2)
	return -1;
    int large=-1,second_large=-1;
    int i;
    for (i = 0; i < n; i++) 
    {
        if (arr[i] > large) 
        {
            second_large = large;
            large = arr[i];
        }
 
        else if (arr[i] > second_large && arr[i] != large) 
        {
            second_large = arr[i];
        }
    }
    return second_large;  
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends