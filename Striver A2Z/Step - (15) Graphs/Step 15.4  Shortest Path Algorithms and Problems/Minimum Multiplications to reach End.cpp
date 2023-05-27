// https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-multiplications-to-reach-end


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        int mod = 1e5 ;
        vector<int> minMult (mod, -1);
        queue<pair<int, int>> q;
        q.push({0,start});
        minMult[start] = 0;
        while(!q.empty()){
            int curMult = q.front().first;
            int curNode = q.front().second;
            q.pop();
            if(curNode == end){
                return curMult;
            }
            for(int i=0;i<n;i++){
                int nextNode = (arr[i] * curNode) % mod;
                int nextMult = curMult + 1;
                if(minMult[nextNode]==-1 || minMult[nextNode]>nextMult){
                    minMult[nextNode] = nextMult;
                    q.push({nextMult, nextNode});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends