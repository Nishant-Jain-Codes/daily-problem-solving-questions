// https://practice.geeksforgeeks.org/problems/merge-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=merge-sort


//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
         // Your code here
         int *tempArr = new int[r-l+1];
         int tIdx=0;
         int tempL=l;
         int tempR=m+1;
         while(tempL<=m&&tempR<=r){
            if(arr[tempL]<=arr[tempR])
            {
                tempArr[tIdx++]=arr[tempL++];
            }
            else
            {
                 tempArr[tIdx++]=arr[tempR++];
            }
         }
         while(tempL<=m){
            tempArr[tIdx++]=arr[tempL++];
         }
         while(tempR<=r){
            tempArr[tIdx++]=arr[tempR++];
         }
         
         tIdx=0;
         for(int i=l;i<=r;i++){
             arr[i]=tempArr[tIdx++];
         }
         delete [] tempArr;
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        //code here
        if(l>=r)
            return;
        int mid = l + ((r-l)/2);
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends