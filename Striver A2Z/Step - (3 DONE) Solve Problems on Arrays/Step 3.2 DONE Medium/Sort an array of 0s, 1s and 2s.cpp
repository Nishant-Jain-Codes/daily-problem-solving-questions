// https://practice.geeksforgeeks.org/problems/sort-an-array-of-0s-1s-and-2s4231/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=sort-an-array-of-0s-1s-and-2s


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:

    /*
    !logic 
    count number of zeros , one and two 
    and put update them in the array
    */
    void sort012(int a[], int n)
    {
        // code here 
        int z=0,o=0,t=0;
        for(int i=0;i<n;i++){
            if(a[i]==0)
                z++;
            else if(a[i]==1)
                o++;
            else 
                t++;
        }
        for(int i=0;i<n;i++){
            if(z){
                a[i]=0;
                z--;
            }
            else if(o)
            {
                a[i]=1;
                o--;
            }
            else 
            {
                a[i]=2;
                t--;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends