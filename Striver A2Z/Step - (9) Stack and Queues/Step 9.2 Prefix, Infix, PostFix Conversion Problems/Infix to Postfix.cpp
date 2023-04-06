// https://practice.geeksforgeeks.org/problems/infix-to-postfix-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=infix-to-postfix

class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int precedence(char opr){
        switch (opr){
            case '+' : return 1;
            case '-' : return 1;
            case '*' : return 2;
            case '/' : return 2;
            case '^' : return 3;
            default : return -1;
        }
    }
    bool isOperator(char c){
        return c=='+' || c=='-' || c=='^' || c== '*' || c=='/'; 
    }
    string infixToPostfix(string infix) {
        // Your code here
        string postfix= "";
        stack<char> stk;
        for(int i=0;i<infix.length();i++){
            //if operand then push to the postfix string
            if( isalnum(infix[i])){
                postfix.push_back(infix[i]);
            }
            //if opening bracket, push it to the stack
            else if( infix[i]=='(')
                stk.push('(');
            //if closing bracket, pop operators from stack till opening bracket is encountered
            else if(infix[i]==')'){
                while(stk.top()!='(')
                {
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
            }
            //if an operator is encountered
            else if(isOperator(infix[i])){
                //pop operators from stack and add to postfix string till precedence of current operator is greater than top of stack
                while(!stk.empty() && precedence(infix[i])<= precedence(stk.top())){
                    postfix.push_back(stk.top());
                    stk.pop();
                }
                //push the current operator to stack
                stk.push(infix[i]);
            }
        }
        //pop remaining operators from stack and add to postfix string
        while(!stk.empty()){
            postfix.push_back(stk.top());
            stk.pop();
        }
        //return the postfix expression
        return postfix;
    }
};
