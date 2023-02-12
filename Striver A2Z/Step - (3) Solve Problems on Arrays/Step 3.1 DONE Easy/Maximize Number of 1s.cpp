// https://practice.geeksforgeeks.org/problems/maximize-number-of-1s0905/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximize-number-of-1s

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        int len=0;
        int ans=0;
        int j=-1;
        int zero =0;
        for(int i=0;i<n;i++){
            if(arr[i]==0)
                zero++;
            if(zero>m){//if we have flippen max no of zeroes 
                while(zero>m){
                    j++;//shifting from left size
                    if(arr[j]==0) //if encountering a zero
                        zero--; //removing it from out current window cnt
                }
            }
            len = i-j;
            ans= max(ans,len);
        }
        return ans;
    } 
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends