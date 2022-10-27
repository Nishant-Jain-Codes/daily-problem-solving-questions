/*

https://www.codechef.com/LP2TO304/problems/BEX?tab=statement

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
    //cin>>t;
    t=1;
    while(t--)
    {
        solution();
     
    }
    return 0;
}




// CODE STARTS HERE-------------------------------------------------------------------------------------------
// time complexity :  O(n)
// space complexity : O(n)
class book{
public:
    int ex;
    string sub;
    book(int ex,string sub)
    {
        this->ex=ex;
        this->sub=sub;
    }
};

void solution()
{
    int n;cin>>n;

    vector<pair<book,int>> stk;

    for(int i=0;i<n;i++)
    {
        int no;cin>>no;
        if(no==-1)
        {
            cout<<stk.back().second<<" "<<stk.back().first.sub<<endl;
            stk.pop_back();
        }
        else 
        {
            string s;cin>>s;
            if(no==0)
                continue;
            if(stk.empty()||stk.back().first.ex>=no)
            {
                book b(no,s);
                stk.push_back({b,0});
            }
            else 
            {
                stk.back().second++;
            }
        }
    }

}
//CODE ENDS HERE----------------------------------------------------------------------------------------------