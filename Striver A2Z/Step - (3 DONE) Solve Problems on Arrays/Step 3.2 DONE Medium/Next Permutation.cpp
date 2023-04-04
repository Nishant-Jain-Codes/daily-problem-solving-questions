https://practice.geeksforgeeks.org/problems/next-permutation5226/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=next-permutation

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> input){
        // code here
        vector<int>arr;
        for(auto x:input)
            arr.push_back(x);
        int n=N;
        int idx1=-1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                idx1=i;
                break;
            }
        }
        if(idx1<0)
            reverse(arr.begin(),arr.end());
        else{
            int idx2 ;
            for(int i=n-1;i>idx1;i--){
                if(arr[i]>arr[idx1]){
                    idx2=i;
                    break;
                }
            }
            swap(arr[idx1],arr[idx2]);
            reverse(arr.begin()+idx1+1,arr.end());
        }
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends