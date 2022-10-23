/*

https://practice.geeksforgeeks.org/problems/palindrome0746/1

*/


//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
	public:
		string is_palindrome(int n)
		{
		    // Code here.
		    int n2=0;
		    int temp = n;
		    while(temp>0)
		    {
		        n2=(n2*10) + temp%10;
		        temp/=10;
		    }
		    if( n2 == n)
		    return "Yes";
		    else 
		    return "No";
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends