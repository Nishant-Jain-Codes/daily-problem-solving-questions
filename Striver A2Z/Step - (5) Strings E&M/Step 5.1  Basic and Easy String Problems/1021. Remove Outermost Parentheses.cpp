// https://leetcode.com/problems/remove-outermost-parentheses/description/

class Solution {
public:
    string removeOuterParentheses(string str) {
        string answer="";
        bool openFound = false;
        int opC =0;
        for(int i=0;i<str.length();i++){
            char ch = str[i];
            if(ch=='(')
                if(!openFound)
                    openFound = !openFound;
                else 
                    {
                        answer+=ch;
                        opC++;
                    }
            else
                if(opC==0)
                    openFound = !openFound;
                else 
                {
                    answer+=ch;
                    opC--;
                }
            
        }
        return answer;
    }
};