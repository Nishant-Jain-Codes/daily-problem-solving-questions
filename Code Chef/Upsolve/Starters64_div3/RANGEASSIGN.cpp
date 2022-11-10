// https://www.codechef.com/problems/RANGEASSIGN

// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
#define int             long long int
#define in(v,n)        for(int i=0;i<n;i++) cin>>v[i];
#define co(x)         cout<<x<<endl;
const string yes = "YES";
const string no = "NO";
void solution();
void YorN(bool ans)
{
    if(ans)
        {
            co(yes);
            
        }
    else 
        {
            co(no);
        }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    // your code goes here
    int t;
    cin>>t;

    while(t--)
    {
        solution();
     
    }
    return 0;
}




// CODE STARTS HERE-------------------------------------------------------------------------------------------
// time complexity :  O(n)
// space complexity : O(n)

void solution()
{
    int n;
    cin>>n;
    int arr[n];
    in(arr,n);
    int Ai=arr[0];
    int An= arr[n-1];
    bool ans = false;
    if(n==1||Ai==An)
    {
        YorN(true);
        return;
    }
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==Ai && arr[i+1]==An)
        {
            ans=true;
            break;
        }
      
    }
    YorN(ans);
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------