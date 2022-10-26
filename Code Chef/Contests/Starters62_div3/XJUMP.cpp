/*

https://www.codechef.com/START62C/problems/XJUMP

*/

// linkers , defines , constants

#include <bits/stdc++.h>
using namespace std;
#define int             long long int
#define lb             lower_bound
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
    int t;
    cin>>t;
    while(t--)
    {
        solution();
     
    }
    return 0;
}
//CODE STARTS HERE-----------------------------------------------------------

// time complexity O(n)
// space complexity O(n)

void solution()
{
     int x,y;
    cin>>x>>y;
    int *ans = new int[x+1];
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=x;i++)
    {
        int a=INT_MAX;
        int b=INT_MAX;
        a=1+ans[i-1];
        if((i-y)>=0)
        b=1+ans[i-y];
        
        ans[i]=min(a,b);
    }
    co( ans[x]);
}

//CODE ENDS HERE----------------------------------------------------------------------------------------------