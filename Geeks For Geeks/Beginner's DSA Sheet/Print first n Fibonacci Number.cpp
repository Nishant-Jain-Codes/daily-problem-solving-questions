/*
Print first n Fibonacci Numbers
BasicAccuracy: 50.31%Submissions: 40067Points: 1
Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.

Example 1:

Input:
N = 5
Output: 1 1 2 3 5
Example 2:

Input:
N = 7
Output: 1 1 2 3 5 8 13
Your Task:
Your task is to complete printFibb() which takes single argument N and returns a list of first N Fibonacci numbers.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Note: This space is used to store and return the answer for printing purpose.

Constraints:
1<= N <=84
*/
// solution 
vector<long long> printFibb(int n) 
    {
        //code here
        vector<long long> ans;
        
        long long a = 0;
        long long b = 1;
        if(n>0)
            ans.push_back(1);
        while(--n)
        {
            long long c = a+b;
            ans.push_back(c);
            a=b;
            b=c;
        }
        
        return ans;
    }
