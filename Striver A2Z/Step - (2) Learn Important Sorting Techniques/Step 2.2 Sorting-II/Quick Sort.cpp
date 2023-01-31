// https://practice.geeksforgeeks.org/problems/quick-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-sort
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
    int partition (int arr[], int low, int high)
    {
       // Your code here
       int pIdx = low;
       int pEle = arr[low];
       for(int i=low+1;i<=high;i++){
           if(arr[i]<=pEle)
            pIdx++;
       }
       swap(arr[low],arr[pIdx]);
       while(low<pIdx&&high>pIdx){
           if(arr[low]<=pEle)
                low++;
            else if(arr[high]>pEle)
                high--;
            else 
            {
                swap(arr[low],arr[high]);
                low++;
                high--;
            }
       }
       return pIdx;
       
    }
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low>=high)
            return ;
        int p = partition(arr,low,high);
        quickSort(arr,low,p-1);
        quickSort(arr,p+1,high);
    }
    
    
    
    
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends