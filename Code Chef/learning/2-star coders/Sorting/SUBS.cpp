/*

https://www.codechef.com/LP2TO302/problems/SUBS?tab=statement

*/

// solution


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(nlogn)
void solution()
{
    int n;cin>>n;
    int k;cin>>k;
    int arr[n];
    in(arr,n);
    sort(arr,arr+n);
    int ans=INT_MAX;
    int s=0;
    for(int i=k-1;i<n;i++)
    {
        ans=min(ans,arr[i]-arr[s++]);
    }
    co(ans);
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
