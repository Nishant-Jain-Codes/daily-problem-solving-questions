class Solution
{
public:
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s)
    {
        // Your code here
        string output = "";
        stack<char> st;
        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            // if operand then add to output
            if (isalpha(c)||isdigit(c))
            {
                output.push_back(c);
            }
            else
            {
                if (st.empty() || st.top() == '(' || c == '(')
                    st.push(c);
                else if (c == ')')
                {
                    while (!st.empty() && st.top() != '(') // Check if stack is not empty before accessing top element
                    {
                        output.push_back(st.top());
                        st.pop();
                    }
                    st.pop(); // Pop '(' from the stack
                }
                else
                {
                    int inputPrecedence = precedence(c);
                    while (!st.empty() && inputPrecedence <= precedence(st.top())) // Check if stack is not empty before accessing top element
                    {
                        output.push_back(st.top());
                        st.pop();
                    }
                    st.push(c);
                }
            }
        }
        while (!st.empty())
        {
            if(st.top() != '(' && st.top() != ')')
            output.push_back(st.top());
            st.pop();
        }
        return output;
    }

private:
    int precedence(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
};
