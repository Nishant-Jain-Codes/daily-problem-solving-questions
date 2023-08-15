class Solution {
public:
// approach 2 
    bool checkValidString(string s) {
        stack<int> openStack;
        stack<int> starStack;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                openStack.push(i);
            } else if (s[i] == '*') {
                starStack.push(i);
            } else {
                if (!openStack.empty()) {
                    openStack.pop();
                } else if (!starStack.empty()) {
                    starStack.pop();
                } else {
                    return false;
                }
            }
        }
        
        while (!openStack.empty() && !starStack.empty()) {
            if (openStack.top() > starStack.top()) {
                return false;
            }
            openStack.pop();
            starStack.pop();
        }
        
        return openStack.empty();
    }
};


class Solution {
public:
// approach 1 
    bool checkValidString(string s) {
        int open = 0, star = 0;
        
        // Forward pass: prioritize using stars to balance open parentheses
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                open++;
            else if (s[i] == '*')
                star++;
            else {
                if (open > 0)
                    open--;
                else if (star > 0)
                    star--;
                else
                    return false;
            }
        }
          if (open > star)
            return false;
        // Backward pass: prioritize using stars to balance closed parentheses
        open = 0;
        star = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')')
                open++;
            else if (s[i] == '*')
                star++;
            else {
                if (open > 0)
                    open--;
                else if (star > 0)
                    star--;
                else
                    return false;
            }
        }
        
        return true;
    }
};
