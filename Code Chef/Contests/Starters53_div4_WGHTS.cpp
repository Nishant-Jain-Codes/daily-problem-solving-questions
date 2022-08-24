/*
Problem
Chef is playing with weights. He has an object weighing WW units. He also has three weights each of X, Y,X,Y, and ZZ units respectively. Help him determine whether he can measure the exact weight of the object with one or more of these weights.

If it is possible to measure the weight of object with one or more of these weights, print YES, otherwise print NO.

Input Format
The first line of input will contain a single integer TT, denoting the number of test cases.
Each test case consists of single line containing a four positive integers W, X, Y,W,X,Y, and ZZ.
Output Format
For each test case, output on a new line YES if it is possible to measure the weight of object with one or more of these weights, otherwise print NO.

You may print each character of the string in either uppercase or lowercase (for example, the strings yes, YES, Yes, and yeS will all be treated as identical).

Constraints
1 \leq T \leq 10^41≤T≤10 
4
 
1 \leq W, X, Y, Z \leq 10^51≤W,X,Y,Z≤10 
5
 
Sample 1:
Input
Output
4
5 2 1 6
7 9 7 2
20 8 10 12
20 10 11 12
NO
YES
YES
NO
Explanation:
Test Case 11: It is not possible to measure 55 units using any combination of given weights.

Test Case 22: Chef can use the second weight of 77 units to measure the object exactly.

Test Case 33: Chef can use combination of first and third weights to measure 8+12=208+12=20 units.

Test Case 44: Chef cannot measure 2020 units of weight using any combination of given weights.
*/
// solution 

void solution()
{
   int w;
   cin>>w;
   vector<int> arr;
   //bool ans=false;
   for(int i=0;i<3;i++)
        {
            int in ;
            cin>>in;
            arr.push_back(in);
        }
    sort(arr.begin(),arr.end());
    for(int i =0;i<3;i++)
    {
        if(arr[i]==w)
            {
                cout<<"YES";
                return ;
            }
            
    }
    int si=0;
    int ei=2;
    while(si<ei)
    {
        if(arr[si]+arr[ei]==w)
        {
            cout<<"YES";
            return ;
        }
        else if(arr[si]+arr[ei]<w)
        {
            si++;
        }
        else
        {
            ei--;
        }
    }
    int sum=0;
    for(int i =0;i<3;i++)
    {
        sum+=arr[i];
    }
    if(sum==w)
        {
            cout<<"YES";
            return ;
        }
    cout<<"NO";
}
