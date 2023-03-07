// https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array3611/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-element-in-a-sorted-and-rotated-array

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        //complete the function here
        int lo = 0;
        int hi = n-1;
        int curMin = arr[0];
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            bool isLeftSorted = arr[mid]>= arr[lo];
            if(isLeftSorted){
                curMin = min(curMin,arr[lo]);
                lo=mid+1;
            }else{
                curMin = min(curMin,arr[mid]);
                hi=mid-1;
            }
        }
        return min(curMin,min(arr[lo],arr[hi]));
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends