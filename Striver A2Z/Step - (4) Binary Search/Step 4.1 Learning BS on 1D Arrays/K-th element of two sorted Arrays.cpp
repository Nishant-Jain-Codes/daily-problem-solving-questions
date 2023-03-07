// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-element-of-two-sorted-array


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int l =0;
        int r=0;
        int k2=0;
        int ans = -1;
        while(l<n && r<m){
            if(arr1[l]<arr2[r]){
                ans = arr1[l];
                l++;
                k2++;
            }
            else{
                ans = arr2[r];
                r++;
                k2++;
            }
            if(k2==k)
                return ans;
        }
        while(l<n){
            if(k2==k)
                return ans;
            ans = arr1[l];
            l++;
            k2++;
        }
        while(r<m){
            if(k2==k)
                return ans;
            ans = arr2[r];
            r++;
            k2++;
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