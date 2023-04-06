// https://practice.geeksforgeeks.org/problems/stack-using-two-queues/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=stack-using-two-queues

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        this->q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
        // Your Code   
        if(this->q1.empty())
            return -1;
        int ref = INT_MAX;
        this->q1.push(ref);
        int pop_val;
        while(true){
            pop_val = this->q1.front();
            q1.pop();
            if(this->q1.front()==ref)
            {
                this->q1.pop();
                return pop_val;
            }else {
                this->q1.push(pop_val);
            }
        }
}
