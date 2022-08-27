/*
Problem
Chef is very fond of horses. He enjoys watching them race. As expected, he has a stable full of horses. He, along with his friends, goes to his stable during the weekends to watch a few of these horses race. Chef wants his friends to enjoy the race and so he wants the race to be close. This can happen only if the horses are comparable on their skill i.e. the difference in their skills is less.

There are N horses in the stable. The skill of the horse i is represented by an integer S[i]. The Chef needs to pick 2 horses for the race such that the difference in their skills is minimum. This way, he would be able to host a very interesting race. Your task is to help him do this and report the minimum difference that is possible between 2 horses in the race.

Input:
First line of the input file contains a single integer T, the number of test cases.
Every test case starts with a line containing the integer N.
The next line contains N space separated integers where the i-th integer is S[i].

Output:
For each test case, output a single line containing the minimum difference that is possible.

Constraints:
1 ≤ T ≤ 10
2 ≤ N ≤ 5000
1 ≤ S[i] ≤ 1000000000
Sample 1:
Input
Output
1
5
4 9 1 32 13
3
Explanation:
The minimum difference can be achieved if we pick horses with skills 1 and 4 for the race.
*/ 


// solution 
void solution()
{
    int n;cin>>n;
    int arr[n];
    in(arr,n);
    int N = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + N);
    int mindiff = INT_MAX;
    for(int i =0;i<n-1;i++)
    {
        int diff = arr[i+1]-arr[i];
        mindiff=min(diff,mindiff);
    }
    co(mindiff);
