/*

https://www.codechef.com/START63C/problems/DELXORONE

*/


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
    int n;cin>>n;
    unordered_map<int,int>  map;
    int m=INT_MIN;
    for(int i=0;i<n;i++)
    {
        int in ; cin>>in;
        map[in]++;
        m=max(m,in);
    }
    int notdel = INT_MIN;
    for(int i=0;i<m;i++)
    {
        int f=0;
        int s=0;
        if(map.count(i)>0)
            f=map[i];
        if(map.count((i+1))>0)
            s=map[i+1];
       
        if((i^i+1)<=1)
            notdel= max(notdel,f+s);
        else 
            notdel= max(notdel,f);
       
    }
    int ans=n-notdel;
    if(map[m]>notdel)
    {
        ans=n-map[m];
    }
    co(ans);

    
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------