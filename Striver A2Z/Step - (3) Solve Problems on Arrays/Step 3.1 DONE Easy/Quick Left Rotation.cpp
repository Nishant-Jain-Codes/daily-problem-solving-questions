// https://practice.geeksforgeeks.org/problems/quick-left-rotation3806/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=quick-left-rotation

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	//O(1) space complexity
	public:
	 void reverseArr(int * arr , int si ,int ei){
        while(si<ei){
            swap(arr[si++],arr[ei--]);
        }
    }
    void leftRotate(int arr[], int k, int n) 
    { 
       // Your code goes here
       k=k%n;
       reverseArr(arr,0,k-1);
       reverseArr(arr,k,n-1);
       reverseArr(arr,0,n-1);
    } 	 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends