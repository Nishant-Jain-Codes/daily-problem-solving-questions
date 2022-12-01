// https://www.hackerearth.com/problem/algorithm/the-monk-and-class-marks/

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
    t=1;

    while(t--)
    {
        solution();
     
    }
    return 0;
}




// CODE STARTS HERE-------------------------------------------------------------------------------------------
// time complexity :  O(nlogn)
// space complexity : O(n)
bool comp(pair<string,int>p1,pair<string,int>p2)
{
    if(p1.second>p2.second)
        return true;
    else if(p1.second==p2.second)
    {
        if(p1.first<p2.first)
            return true;
        else 
            return false;
    }
    else 
        return false;
}
void solution()
{
     int n;
     cin>>n;
     vector<pair<string,int>> m;
     for(int i=0;i<n;i++)
     {
        string s;
        int marks;
        cin>>s>>marks;
        m.push_back({s,marks});
     }
     sort(m.begin(),m.end(),comp);
     for(auto x : m)
     {
        cout<<x.first<<" "<<x.second<<endl;
     }
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------