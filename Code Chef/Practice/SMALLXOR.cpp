/*
Problem
Chef has an array AA of length NN and an integer XX.

In one operation, Chef does the following:

Find the smallest element in the current array. Let this be SS.
Next, pick any one index ii such that A_i = SA 
i
​
 =S
Finally, replace A_iA 
i
​
  with A_i \oplus XA 
i
​
 ⊕X
Here \oplus⊕ denotes the bitwise XOR operation.

For example, if A = [1, 1, 2]A=[1,1,2] and X = 4X=4, then in one move Chef can turn the array into either [5, 1, 2][5,1,2] or [1, 5, 2][1,5,2].

Chef performs this operation exactly YY times. Let BB be final array obtained.

Output the array BB in sorted order. Note that under this restriction, the output is unique.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of two lines of input.
The first line of each test case contains three space-separated integers NN, XX, and YY.
The second line contains NN space-separated integers denoting the array AA.
Output Format
For each test case, output array BB in sorted order.

Constraints
1 \leq T \leq 10^41≤T≤10 
4
 
1 \leq N \leq 10^51≤N≤10 
5
 
1 \leq Y \leq 10^91≤Y≤10 
9
 
1 \leq A_i , X \leq 2^{30}1≤A 
i
​
 ,X≤2 
30
 
The sum of NN over all test cases won't exceed 10^510 
5
 .
Sample 1:
Input
Output
3
1 6 99
9
3 7 44
1 2 3
5 20 6
5 10 15 20 25
15 
3 5 6 
5 20 25 27 30 
Explanation:
Test case 11: The array is initially [9][9]. Since there is only one element, it will be modified in each step. So,

After the first operation, the array is [15][15] (since 9 \oplus 6 = 159⊕6=15)
After the second operation, the array is [9][9] (since 15 \oplus 6 = 915⊕6=9)
Continuing the above, it can be verified that after 9999 steps, the array is [15][15].
Test case 33: The sequence of steps is as follows:

Initially, the array is [5, 10, 15, 20, 25][5,10,15,20,25]
After operation 11, it is [17, 10, 15, 20, 25][17,10,15,20,25]
After operation 22, it is [17, 30, 15, 20, 25][17,30,15,20,25]
After operation 33, it is [17, 30, 27, 20, 25][17,30,27,20,25]
After operation 44, it is [5, 30, 27, 20, 25][5,30,27,20,25]
After operation 55, it is [17, 30, 27, 20, 25][17,30,27,20,25]
After operation 66, it is [5, 30, 27, 20, 25][5,30,27,20,25]
Remember to print the output in sorted order.
*/

// solution

void solution()
{
    int n,x,y;
    cin>>n>>x>>y;
    // min priority_queue
    priority_queue<int,vector<int>,greater<int>> pq;
    // input
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        pq.push(in);
    }
    int prev=-1;
   while(y)
   {
       int elem = pq.top();
       int val = elem^x;
        if(val == prev)
            break;
        pq.pop();
        pq.push(val);
        prev = elem;
        y--;
   }
    
    if(y%2==1)
    {
        int s1=pq.top();
        pq.pop();
        pq.push(s1^x);
        
    }
    for(int i=0;i<n;i++)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
