// https://practice.geeksforgeeks.org/problems/aggressive-cows/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=aggressive-cows


//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool canAllocate(vector<int> &stalls,int n, int k,int dist){
        int alloctedCows = 1;
        int prevLoc = stalls[0];
        for(int i=1;i<n;i++){
            if(stalls[i]-prevLoc >= dist){
                alloctedCows++;
                prevLoc = stalls[i];
            }
        }
        return (alloctedCows >= k);

    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        int lo=0;
        int hi=1e9;
         sort(stalls.begin(),stalls.end());
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(canAllocate(stalls,n,k,mid)){
                lo = mid;
            }else {
                hi=mid-1;
            }
        }
        if(canAllocate(stalls,n,k,hi)){
            return hi;
        }
        else 
            return lo;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends