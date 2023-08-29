class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stk;
        
        for (char digit : num) {
            while (!stk.empty() && k > 0 && stk.top() > digit) {
                stk.pop();
                k--;
            }
            stk.push(digit);
        }
        
        while (k > 0 && !stk.empty()) {
            stk.pop();
            k--;
        }
        
        string ans;
        while (!stk.empty()) {
            ans.push_back(stk.top());
            stk.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        int i = 0;
        while (i < ans.length() && ans[i] == '0') {
            i++;
        }
        
        return (i == ans.length()) ? "0" : ans.substr(i);
    }
};
