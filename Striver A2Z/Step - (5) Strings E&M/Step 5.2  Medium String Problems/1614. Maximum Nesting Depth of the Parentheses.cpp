// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

class Solution {
public:
    int maxDepth(string s) {
        int answer = 0;
        int opC = 0;
        for(auto &x : s){
            if(x=='(')
                opC++;
            else if(x==')') {
                if(opC)
                    opC--;
            }
            answer = max(answer,opC);
        }
        return answer;
    }
};