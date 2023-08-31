https://practice.geeksforgeeks.org/problems/implement-stack-using-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implement-stack-using-linked-list

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
    void push(int);
    int pop();
    MyStack() { top = NULL; }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        MyStack *sq = new MyStack();

        int Q;
        cin >> Q;
        while (Q--) {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1) {
                int a;
                cin >> a;
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
    }
}

// } Driver Code Ends


//Function to push an integer into the stack.
void MyStack ::push(int x) 
{
    // Your Code
    StackNode * add = new StackNode(x);
    if(!this->top){
        this->top=add;
    }
    else{
        add->next = this->top;
        this->top=add;
    }
    
}

//Function to remove an item from top of the stack.
int MyStack ::pop() 
{
    // Your Code
    if(!this->top)    
        return -1;
    else 
    {
        int pop_val = this->top->data;
        StackNode* del = this->top;
        this->top = this->top->next;
        del->next= NULL;
        delete del;
        return pop_val;
    }
}
