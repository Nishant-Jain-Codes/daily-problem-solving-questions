// https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=Power+of+2

//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here    
        bool bitSet = false;
        long long  no = 1;
        long long i=0;
        while(i++ < 64){
            if(no&n){
                if(bitSet)
                    return false;
                else 
                    bitSet= true;
            }
            no<<=1;
        }
        if(!bitSet)
            return false;
        return true;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{

    int t;
    cin>>t;//testcases

    for(int i=0;i<t;i++)
    {
        long long n; //input a number n
        cin>>n;

        Solution ob;
         if(ob.isPowerofTwo(n))//Now, if log2 produces an integer not decimal then we are sure raising 2 to this value
             cout<<"YES"<<endl;
         else
            cout<<"NO"<<endl;

    }

    return 0;
}

// } Driver Code Ends