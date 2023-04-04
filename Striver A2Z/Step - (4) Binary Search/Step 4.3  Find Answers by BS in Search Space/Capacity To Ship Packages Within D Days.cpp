// https://practice.geeksforgeeks.org/problems/capacity-to-ship-packages-within-d-days/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=capacity-to-ship-packages-within-d-days

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool possible_to_ship(int weights[],int n,int days,int weight){
        int cur_Weight=0;
        int cur_days=0;
        for(int i=0;i<n;i++){
            int w = weights[i];
            if(w>weight)
                return false;
            if(cur_Weight+w > weight){
                cur_Weight=0;
                cur_days++;
            }
            cur_Weight+=w;
        }
        cur_days+=1;
        return cur_days<=days;
    }
    int leastWeightCapacity(int weights[], int n, int days) {
        // code here
        int lo = 1;
        int hi = 1e8;
        while(hi-lo>1){
            int mid = (hi+lo)/2;
            if(possible_to_ship(weights,n,days,mid)){
                hi=mid;
            }
            else 
            {
                lo=mid+1;
            }
        }
        if(possible_to_ship(weights,n,days,lo))
            return lo;
        if(possible_to_ship(weights,n,days,hi))
            return hi;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends