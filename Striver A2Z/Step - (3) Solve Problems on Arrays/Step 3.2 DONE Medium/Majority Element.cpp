// https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=majority-element


//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    /*
    using O(N) space complexity
    store frequency in hashmap
    and check n/2 freq
    */
    int majorityElement(int a[], int size)
    {
        
        // your code here
        unordered_map<int,int> m;
        for(int i=0;i<size;i++){
            m[a[i]]++;
        }
        int ans=-1;
        for(auto x: m){
            if(x.second>size/2)
                ans=x.first;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends