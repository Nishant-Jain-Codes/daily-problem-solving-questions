
// time complexity: O(exp)
// space complexity: O(n) stack
int recursion(string &exp, int si, int ei, int boolReq)
{
    if (si == ei)
    {
        if (boolReq == true)
        {
            return exp[si] == 'T';
        }
        else
        {
            return exp[si] == 'F';
        }
    }
    int count = 0;
    for (int k = si + 1; k < ei; k += 2)
    {
        int leftTrue = recursion(exp, si, k - 1, true);
        int leftFalse = recursion(exp, si, k - 1, false);
        int rightTrue = recursion(exp, k + 1, ei, true);
        int rightFalse = recursion(exp, k + 1, ei, false);
        if (exp[k] == '&')
        {
            if (boolReq == true)
            {
                count = (count + leftTrue * rightTrue);
            }
            else
            {
                count = (count + leftTrue * rightFalse) + (leftFalse * rightTrue) + (leftFalse * rightFalse);
            }
        }
        else if (exp[k] == '|')
        {
            if (boolReq == true)
            {
                count = (count + leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue);
            }
            else
            {
                count = (count + leftFalse * rightFalse);
            }
        }
        else if (exp[k] == '^')
        {
            if (boolReq == true)
            {
                count = (count + leftTrue * rightFalse) + (leftFalse * rightTrue);
            }
            else
            {
                count = (count + leftTrue * rightTrue) + (leftFalse * rightFalse);
            }
        }
    }
    return count;
}
// time complexity: O(2*n^3)
// space complexity: O(2*n^2) + O(n)stack
const int mod = 1000000007;

int memoization(string &exp, int si, int ei, int boolReq, vector<vector<vector<int>>> &dp)
{
    if (si == ei)
    {
        if (boolReq == true)
        {
            return exp[si] == 'T';
        }
        else
        {
            return exp[si] == 'F';
        }
    }
    if (dp[si][ei][boolReq] != -1)
    {
        return dp[si][ei][boolReq];
    }
    int count = 0;
    for (int k = si + 1; k < ei; k += 2)
    {
        int leftTrue = memoization(exp, si, k - 1, true, dp);
        int leftFalse = memoization(exp, si, k - 1, false, dp);
        int rightTrue = memoization(exp, k + 1, ei, true, dp);
        int rightFalse = memoization(exp, k + 1, ei, false, dp);
        if (exp[k] == '&')
        {
            if (boolReq == true)
            {
                count = (count + 1LL * leftTrue * rightTrue) % mod;
            }
            else
            {
                count = (count + 1LL * leftTrue * rightFalse + 1LL * leftFalse * rightTrue + 1LL * leftFalse * rightFalse) % mod;
            }
        }
        else if (exp[k] == '|')
        {
            if (boolReq == true)
            {
                count = (count + 1LL * leftTrue * rightTrue + 1LL * leftTrue * rightFalse + 1LL * leftFalse * rightTrue) % mod;
            }
            else
            {
                count = (count + 1LL * leftFalse * rightFalse) % mod;
            }
        }
        else if (exp[k] == '^')
        {
            if (boolReq == true)
            {
                count = (count + 1LL * leftTrue * rightFalse + 1LL * leftFalse * rightTrue) % mod;
            }
            else
            {
                count = (count + 1LL * leftTrue * rightTrue + 1LL * leftFalse * rightFalse) % mod;
            }
        }
    }
    return dp[si][ei][boolReq] = count;
}
int tabulation(string &exp)
{
    vector<vector<vector<int>>> dp(exp.length(), vector<vector<int>>(exp.length(), vector<int>(2, 0)));
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == 'T')
        {
            dp[i][i][1] = 1;
        }
        else
        {
            dp[i][i][0] = 1;
        }
    }
    for (int si = exp.length() - 1; si >= 0; si--)
    {
        for (int ei = 0; ei < exp.length(); ei++)
        {
            for (int boolReq = 0; boolReq <= 1; boolReq++)
            {

                if (si == ei)
                {
                    if (boolReq == true)
                    {
                        dp[si][ei][boolReq] = exp[si] == 'T';
                    }
                    else
                    {
                        dp[si][ei][boolReq] = exp[si] == 'F';
                    }
                }
                else
                {
                    int count = 0;
                    for (int k = si + 1; k < ei; k += 2)
                    {
                        int leftTrue = dp[si][k - 1][1];
                        int leftFalse = dp[si][k - 1][0];
                        int rightTrue = dp[k + 1][ei][1];
                        int rightFalse = dp[k + 1][ei][0];
                        if (exp[k] == '&')
                        {
                            if (boolReq == true)
                            {
                                count = (count + 1LL * leftTrue * rightTrue) % mod;
                            }
                            else
                            {
                                count = (count + 1LL * leftTrue * rightFalse + 1LL * leftFalse * rightTrue + 1LL * leftFalse * rightFalse) % mod;
                            }
                        }
                        else if (exp[k] == '|')
                        {
                            if (boolReq == true)
                            {
                                count = (count + 1LL * leftTrue * rightTrue + 1LL * leftTrue * rightFalse + 1LL * leftFalse * rightTrue) % mod;
                            }
                            else
                            {
                                count = (count + 1LL * leftFalse * rightFalse) % mod;
                            }
                        }
                        else if (exp[k] == '^')
                        {
                            if (boolReq == true)
                            {
                                count = (count + 1LL * leftTrue * rightFalse + 1LL * leftFalse * rightTrue) % mod;
                            }
                            else
                            {
                                count = (count + 1LL * leftTrue * rightTrue + 1LL * leftFalse * rightFalse) % mod;
                            }
                        }
                    }
                    dp[si][ei][boolReq] = count;
                }
            }
        }
    }

    return dp[0][exp.length() - 1][1];
}
int evaluateExp(string &exp)
{
    return tabulation(exp);
    vector<vector<vector<int>>> dp(exp.length(), vector<vector<int>>(exp.length(), vector<int>(2, -1)));
    return memoization(exp, 0, exp.length() - 1, true, dp);
    return recursion(exp, 0, exp.length() - 1, true);
}
