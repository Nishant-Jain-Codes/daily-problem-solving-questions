// https://practice.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	   int lo =0;
        int hi = n-1;
        int minIdx = 0;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            bool isLeftSorted = arr[mid]>=arr[lo];
            if(isLeftSorted){
                if(arr[lo]<arr[minIdx])
                    minIdx = lo;
                lo=mid+1;
            }
            else{
                if(arr[mid]<arr[minIdx])
                        minIdx = mid;
                hi=mid-1;
            }
        }
        if(arr[minIdx]>arr[lo])
            minIdx=lo;
        if(arr[minIdx]>arr[hi])
            minIdx = hi;
        return minIdx;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends