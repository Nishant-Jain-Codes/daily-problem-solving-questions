class Solution {
private:
    int helper(string& s, int index, int sign, int result) {
        if (index >= s.length() || !isdigit(s[index]))
        return result;

    int digit = s[index] - '0';

    // Check for overflow
    if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
        return (sign == -1) ? INT_MIN : INT_MAX;
    }
    if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit > -(INT_MIN % 10))) {
        return (sign == 1) ? INT_MAX : INT_MIN;
    }

    result = result * 10 + sign * digit;

    // Recursive call to process the next character
    return helper(s, index + 1, sign, result);
    }

public:
    int myAtoi(string s) {
        if (s.length() == 0)
            return 0;

        int index = 0;
        while (index < s.length() && s[index] == ' ')
            index++;

        int sign = 1;
        if (index < s.length() && (s[index] == '+' || s[index] == '-')) {
            sign = (s[index] == '-') ? -1 : 1;
            index++;
        }

        int result = helper(s, index, sign, 0);
        return result;
    }
};