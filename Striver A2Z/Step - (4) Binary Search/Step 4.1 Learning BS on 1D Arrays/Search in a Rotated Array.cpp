// https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-a-rotated-array


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int x){
        // l: The starting index
        // h: The ending index, you have to search the key in this range
        
        //complete the function here
        int lo=l;
        int hi=h;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(arr[mid]==x)
                return mid;
            bool isLeftSorted = arr[mid]>=arr[lo];
            if(isLeftSorted){
                if(arr[lo]<=x && arr[mid]>=x)
                    hi=mid;
                else 
                    lo=mid+1;
            }
            else {
                if(arr[hi]>=x && arr[mid]<=x)
                    lo=mid;
                else 
                    hi=mid-1;
            }
        }
        if(arr[lo]==x)
            return lo;
        else if(arr[hi]==x)
            return hi;
        else 
            return -1;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends