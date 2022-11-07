/*
Running Median
Send Feedback
You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
Print only the integer part of the median.
Input Format :
The first line of input contains an integer 'N', denoting the number of integers in the stream.

The second line of input contains 'N' integers separated by a single space.
Output Format :
Print the running median for every integer added to the running list in one line (space-separated).
Input Constraints
0 <= N <= 10 ^ 5
1 <= ARR[i] <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1 :
6
6 2 1 3 7 5
Sample Output 1 :
6 4 2 2 3 4
Explanation of Sample Output 1 :
S = {6}, median = 6
S = {6, 2} -> {2, 6}, median = 4
S = {6, 2, 1} -> {1, 2, 6}, median = 2
S = {6, 2, 1, 3} -> {1, 2, 3, 6}, median = 2
S = {6, 2, 1, 3, 7} -> {1, 2, 3, 6, 7}, median = 3
S = {6, 2, 1, 3, 7, 5} -> {1, 2, 3, 5, 6, 7}, median = 4
Sample Input 2 :
5
5 4 3 2 1
Sample Output 2 :
5 4 4 3 3
*/

// solution 

#include<queue>

void findMedian(int *arr, int n)
{
    // Write your code here
    if(n==0)
        return;
    priority_queue<int,vector<int>,greater<int>> minheap;
    priority_queue<int> maxheap;
    
    maxheap.push(arr[0]);
    cout<<maxheap.top()<<" ";
    for(int i=1;i<n;i++)
    {
        int target = arr[i];
        
        // input of the target element 
        
        if(target<maxheap.top())
            maxheap.push(target);
        else 
            minheap.push(target);
        
        // if size diff is greater than one
        
        if(minheap.size()-maxheap.size()>1||maxheap.size()-minheap.size()>1)
        {
            if(minheap.size()<maxheap.size())
            {
                minheap.push(maxheap.top());
                maxheap.pop();
            }
            else
            {
                maxheap.push(minheap.top());
                minheap.pop();
            }
        }
        
        if((minheap.size()+maxheap.size())%2==0)// even
            cout<<(minheap.top()+maxheap.top())/2<<" ";
        else
        {
            if(minheap.size()<maxheap.size())
            {
                cout<<maxheap.top()<<" ";
                
            }
            else
            {
                cout<<minheap.top()<<" ";
               
            }
        }
            
    }
}
