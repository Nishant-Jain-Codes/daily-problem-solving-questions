// https://practice.geeksforgeeks.org/problems/get-minimum-element-from-stack/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=get-minimum-element-from-stack

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty())
            return -1;
           return minEle;
       }
       
       /*returns poped element from stack*/
       int pop(){
           //Write your code here
          if(s.empty())
            return -1;
        
            int top_val = s.top();
            s.pop();
            if(top_val < minEle)
            {
                int prevMin = 2*minEle - top_val;
                int pop_val = minEle;
                minEle = prevMin;
                return pop_val;
            }
            else {
                return top_val;
            }
       }
       
       /*push element x into the stack*/
       void push(int x){
           if(s.empty()){
               minEle = x;
               s.push(x);
           }
           else {
               if(x>=minEle){
                   s.push(x);
               }
               else {
                   int newEle = (2*x) - minEle;
                   minEle = x;
                   s.push(newEle);
                   
               }
           }
           //Write your code here
       }
};




//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends