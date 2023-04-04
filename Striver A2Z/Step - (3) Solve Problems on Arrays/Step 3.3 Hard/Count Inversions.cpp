// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=inversion-of-array

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
   long long int merge(long long arr[],long long  si,long long mid ,long long ei){
        long long * tempArr = new long long [ei-si+1];
        long long li = si;
        long long ri=mid+1;
        long long int cnt=0;
        long long k=0;
        while(li<=mid && ri<=ei){
            if(arr[li]<=arr[ri]){
                tempArr[k]=arr[li];
                k++;
                li++;
            }
            else {
                cnt += (mid-li+1);
                tempArr[k]=arr[ri];
                k++;
                ri++;
            }
        }
        while(li<=mid){
            tempArr[k]=arr[li];
            k++;
            li++;
        }
        while(ri<=ei){
            tempArr[k]=arr[ri];
            k++;
            ri++;
        }
         k=0;
        for(int i=si;i<=ei;i++){
            arr[i]=tempArr[k];
            k++;
        }
        delete[] tempArr;
        return cnt;

    }
    long long int mergeSort(long long arr[], long long si , long long ei){
        long long int invCnt=0;
        if(si<ei)
        {       long long mid = ((ei+si)/2);
                invCnt += mergeSort(arr,si,mid);
                invCnt +=mergeSort(arr,mid+1,ei);
                invCnt += merge(arr,si,mid,ei);
        }
        return invCnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends