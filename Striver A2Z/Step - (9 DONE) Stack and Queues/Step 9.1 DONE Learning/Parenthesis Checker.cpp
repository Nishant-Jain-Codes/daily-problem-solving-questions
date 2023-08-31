// https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=parenthesis-checker

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        stack<char> stk;
        for(int i=0;i<x.length();i++){
            char curChar = x[i];
            if(curChar=='{'||curChar=='('||curChar=='[')
                stk.push(curChar);
            else {
                if(stk.empty())
                    return false;
                char stkTop = stk.top();
                if((stkTop=='{'&&curChar!='}')||(stkTop=='('&&curChar!=')')||(stkTop=='['&&curChar!=']'))
                    return false;
                else 
                    stk.pop();
            }
        }
    if(!stk.empty())
    return false;
    return true;
    }
    

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends