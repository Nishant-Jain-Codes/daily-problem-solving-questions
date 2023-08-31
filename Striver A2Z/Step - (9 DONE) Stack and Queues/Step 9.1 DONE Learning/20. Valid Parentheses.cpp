// https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string x) {
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