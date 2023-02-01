// https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=leaders-in-an-array


//{ Driver Code Starts
// C++ program to remove recurring digits from
// a given number
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
    
 /*
  !logic
    leader element will be greater than the maximum element in the right side
    keep a variable Rmax 
    traverse the error from right end 
    if(arr[i]>Rmax)
        Rmax = arr[i]
        inser arr[i] in answer

    now reverse the answer array to get the result in required order 
 */
class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int arr[], int n){
        // Code here
        vector<int> ans ;
        int Rmax = INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(arr[i]>=Rmax){
                Rmax=arr[i];
                ans.push_back(arr[i]);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
   long long t;
   cin >> t;//testcases
   while (t--)
   {
       long long n;
       cin >> n;//total size of array
        
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++){
            cin >> a[i];
        }
        Solution obj;
        //calling leaders() function
        vector<int> v = obj.leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}

// } Driver Code Ends