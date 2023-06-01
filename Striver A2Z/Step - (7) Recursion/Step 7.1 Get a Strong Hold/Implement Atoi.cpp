// https://practice.geeksforgeeks.org/problems/implement-atoi/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-atoi


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    private:
    int helper(string& s, int index, int sign, int result ) {
        if (index >= s.length() || !isdigit(s[index]))
        return result;

    int digit = s[index] - '0';

    // Check for overflow
    if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
        return (sign == -1) ? INT_MIN : INT_MAX;
    }
    if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit > -(INT_MIN % 10))) {
        return (sign == 1) ? INT_MAX : INT_MIN;
    }

    result = result * 10 + sign * digit;

    // Recursive call to process the next character
    return helper(s, index + 1, sign, result);
    }
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        if (s.length() == 0)
            return 0;
        
        int index = 0;
        while (index < s.length() && s[index] == ' ')
            index++;

        int sign = 1;
        if (index < s.length() && (s[index] == '+' || s[index] == '-')) {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }
        for(int i=index;i<s.length();i++){
            if(!isdigit(s[i]))
                return -1;
        }
        int result = helper(s, index, sign, 0);


        return result;
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