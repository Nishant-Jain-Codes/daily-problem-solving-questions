// https://practice.geeksforgeeks.org/problems/implement-stack-using-array/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-stack-using-array

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};


int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        MyStack *sq = new MyStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


//Function to push an integer into the stack.

/*
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
*/

void MyStack :: push(int x)
{
    // Your Code
    if(this->top+1 == 1000)
        return ;
    else 
    {
        this->top++;
        this->arr[this->top] = x;
    }
}

//Function to remove an item from top of the stack.
int MyStack :: pop()
{
    // Your Code   
    if(this->top == -1) 
        return -1;
   int pop_val = this->arr[this->top] ;
   this->top--;
   return pop_val;
}
