class Solution {
public:
    int minAddToMakeValid(string s) {
        int balance = 0; 
        int needed = 0;  
        
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                if (balance > 0) {
                    balance--;
                } else {
                    needed++;
                }
            }
        }
        
        return needed + balance;
    }
};
