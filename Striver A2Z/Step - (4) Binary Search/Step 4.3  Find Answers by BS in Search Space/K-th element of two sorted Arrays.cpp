// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(n>m)
            return kthElement(arr2,arr1,m,n,k);
        int lo = max(0,k-m);
        int hi = min (n,k);
        while(lo<=hi){
            int cut1 = (hi+lo)>>1;
            int cut2 = (k-cut1);
            int left1 = cut1==0?INT_MIN : arr1[cut1-1];
            int left2 = cut2==0?INT_MIN : arr2[cut2-1];
            int right1 = cut1==n?INT_MAX:arr1[cut1];
            int right2 = cut2==m?INT_MAX:arr2[cut2];
            if(left1<=right2 && left2<=right1){
                    return max(left1,left2);
            }
            else if(left1>right2){
                hi=cut1-1;
            }
            else {
                lo=cut1+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends