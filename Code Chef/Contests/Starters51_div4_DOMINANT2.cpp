/*
Problem
You are given an array AA of length NN. An element XX is said to be dominant if the frequency of XX in AA is strictly greater than the frequency of any other element in the AA.

For example, if A = [2, 1, 4, 4, 4]A=[2,1,4,4,4] then 44 is a dominant element since its frequency is higher than the frequency of any other element in AA.

Find if there exists any dominant element in AA.

Input Format
The first line of input contains a single integer TT — the number of test cases. Then the test cases follow.
The first line of each test case contains an integer NN — the size of the array AA.
The second line of each test case contains NN space-separated integers A_1, A_2, \ldots, A_NA 
1
​
 ,A 
2
​
 ,…,A 
N
​
  denoting the array AA.
Output Format
For each test case, output YES if there exists any dominant element in AA. Otherwise, output NO.

You may print each character of YES and NO in uppercase or lowercase (for example, yes, yEs, Yes will be considered identical).

Constraints
1 \le T \le 5001≤T≤500
1 \le N \le 10001≤N≤1000
1 \le A_i \le N1≤A 
i
​
 ≤N
Sample 1:
Input
Output
4
5
2 2 2 2 2
4
1 2 3 4
4
3 3 2 1
6
1 1 2 2 3 4
YES
NO
YES
NO
Explanation:
Test case 11: 22 is the dominant element.

Test case 22: There does not exist any dominant element.

Test case 33: 33 is the dominant element.
*/
// solution 

void solution()
{
    unordered_map<int,int> helper;
    int n;
    cin>>n;
    int no;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i =0;i<n;i++)
    {
        
        if(helper.count(arr[i])>0)
            helper[arr[i]]++;
        else
            helper[arr[i]]=1;
    }
    bool ans=false;
    int max=1;
    unordered_map<int,int> :: iterator iter = helper.begin();
    while (iter != helper.end())
    {   
        if(iter->second>max)
        {
            max=iter->second;
            ans=true;
        }
        else if(iter->second==max)
        {
            ans=false;
        }
        iter++;
    }
    if(ans)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}
