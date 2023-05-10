// https://practice.geeksforgeeks.org/problems/k-th-missing-element3635/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=k-th-missing-element

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends

int KthMissingElement(int arr[], int n, int k) {
    int count = 0;

    for (int i = 1; i < n; i++) {
        int diff = arr[i] - arr[i - 1] - 1;  // Calculate the difference between adjacent elements
        count += diff;

        if (count >= k) {
            // Calculate the Kth missing element
            return arr[i - 1] + (k - (count - diff));
        }
    }

    // If the loop completes without finding the Kth missing element
    return -1;
}
