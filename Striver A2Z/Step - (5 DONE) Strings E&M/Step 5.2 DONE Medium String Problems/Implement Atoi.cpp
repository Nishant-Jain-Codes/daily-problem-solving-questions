// https://practice.geeksforgeeks.org/problems/implement-atoi/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-atoi

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int i=0;
        int resp =0;
        int sign=1;
        while(str[i]==' ')
            i++;
        if(str[i]=='-')
            {
                sign=-1;
                i++;
            }
        
        while(i<str.length() && isdigit(str[i])){
            int curChar = str[i] - '0';
            if (resp > (INT_MAX - curChar) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            resp = resp * 10 + curChar;
            i++;
        }
        if(i<str.length())
            return -1;
        return resp*sign;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends