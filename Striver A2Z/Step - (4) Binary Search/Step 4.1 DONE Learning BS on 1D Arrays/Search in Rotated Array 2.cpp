// https://practice.geeksforgeeks.org/problems/search-in-rotated-array-2/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=search-in-rotated-array

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int n, vector<int>& arr, int x) {
        // Code here
        int lo=0;
        int hi=n-1;
        while(hi>=lo){
            int mid = (hi+lo)/2;
            if(arr[mid]==x)
                return true;
            if(arr[lo]==arr[mid] && arr[hi] == arr[mid]){
                lo++;
                hi--;
            }
            else if(arr[mid]>=arr[lo]){
                if(arr[mid]>=x && x>=arr[lo])
                    hi=mid-1;
                else 
                    lo = mid+1;
            }
            else {
                if(arr[mid]<=x && arr[hi]>= x)
                    lo = mid+1;
                else 
                    hi = mid-1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends