// https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (i == s.length()) {
            return 0;
        }
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }
        int resp = 0;
        while (i < s.length() && isdigit(s[i])) {
            int curChar = s[i] - '0';
            if (resp > (INT_MAX - curChar) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }
            resp = resp * 10 + curChar;
            i++;
        }
        return resp * sign;
    }
};
