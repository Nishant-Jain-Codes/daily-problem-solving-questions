// https://www.codechef.com/START67C/problems/EXPSTP

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
// time complexity :  O(1)
// space complexity : O(1)

void solution()
{
    int n,x,y,X,Y;
    cin>>n>>x>>y>>X>>Y;
    n++;
    int maxDist = abs(X-x)+abs(Y-y);
    int minOutCur = min(min(x,n-x),min(y,n-y));
    int minOutDest = min(min(X,n-X),min(Y,n-Y));
    int ans = min(maxDist,minOutDest+minOutCur);
    co(ans);    
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------