// https://www.codechef.com/START65C/problems/PRIMEDICE


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
    int a,b;
    cin>>a>>b;
    bool p = true;
    for(int i=2;i<a+b;i++)
    {
        if((a+b)%i==0)
            p=false;
    }
    if(p)
        {co("Alice");
}
    else 
    {
        co("Bob");
    }
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------