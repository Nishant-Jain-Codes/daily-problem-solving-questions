// https://practice.geeksforgeeks.org/problems/count-reverse-pairs/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=count-reverse-pairs

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  long long int merge(vector<int>& arr,long long  si,long long mid ,long long ei){
            long long *tempArr = new long long[ei-si+1];

        int li = si;
    int ri = mid+1;
    int cnt = 0;
    int k = 0;
    while(li <= mid && ri <= ei) {
        if(ceil(arr[li]/2.0) > arr[ri]) {
            cnt += (mid-li+1);
            ri++;
        } else {
            li++;
        }
    }
    li = si;
    ri = mid+1;
    k = 0;
    while(li <= mid && ri <= ei) {
        if(arr[li] <= arr[ri]) {
            tempArr[k++] = arr[li++];
        } else {
            tempArr[k++] = arr[ri++];
        }
    }
    while(li <= mid) {
        tempArr[k++] = arr[li++];
    }
    while(ri <= ei) {
        tempArr[k++] = arr[ri++];
    }
    k = 0;
    for(int i = si; i <= ei; i++) {
        arr[i] = tempArr[k++];
    }
    delete[] tempArr;
    return cnt;

    }
    long long int mergeSort(vector<int>& arr, long long si , long long ei){
        long long int invCnt=0;
        if(si<ei)
        {       long long mid = ((ei+si)/2);
                invCnt += mergeSort(arr,si,mid);
                invCnt +=mergeSort(arr,mid+1,ei);
                invCnt += merge(arr,si,mid,ei);
        }
        return invCnt;
    }
    int countRevPairs(int n, vector<int> arr) {
        // Code here
        return mergeSort(arr,0,n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends