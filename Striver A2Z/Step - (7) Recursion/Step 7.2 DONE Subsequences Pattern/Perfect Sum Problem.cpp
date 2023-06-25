// https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int bruteRecursion(int arr[],int size , int sum , int curSum){
        if(size==0)
            if(sum==curSum)
                return 1;
            else 
                return 0;
        return bruteRecursion(arr+1,size-1,sum,curSum+arr[0]) + bruteRecursion(arr+1,size-1,sum,curSum);
        
	}
	int perfectSum(int arr[], int n, int sum)
	{
        return bruteRecursion(arr,n,sum,0);
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends