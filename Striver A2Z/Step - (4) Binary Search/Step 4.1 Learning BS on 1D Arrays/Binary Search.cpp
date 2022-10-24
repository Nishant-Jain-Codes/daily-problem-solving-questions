/*

https://practice.geeksforgeeks.org/problems/binary-search-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=binary-search

*/


//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        int si=0;
        int ei=n-1;
        bool found = false;
        int ans;
        while(si<=ei)
        {
            int mid=si+((ei-si)/2);
            if(arr[mid]<k)
                si=mid+1;
            else if(arr[mid]>k)
                ei=mid-1;
            else 
                {
                    found = true;
                    ans = mid;
                    break;
                }
        }
            
        if(found)
            return ans;
        else 
            return -1;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends