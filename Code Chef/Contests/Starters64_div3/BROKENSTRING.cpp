/*
https://www.codechef.com/START64C/problems/BROKENSTRING
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
// time complexity :  O(1)
// space complexity : O(n)

void solution()
{
    int n;
    cin>>n;
    string s;cin>>s;
    string s1 = s;
    string s2 = s;

    s1=s1.substr(0,n/2);
    //cout<<s1<<endl;
    s2=s2.substr((n/2));
    //cout<<s2<<endl;
    bool ans = ((s1+s2)==s) && ((s2+s1)==s);
    YorN(ans);

}
//CODE ENDS HERE----------------------------------------------------------------------------------------------