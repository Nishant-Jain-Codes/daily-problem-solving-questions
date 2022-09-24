/*

https://www.codechef.com/LP2TO302/problems/BOOKCHEF

*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(nlogn)

bool comp(pair<int,string>p1,pair<int,string>p2)
{
    if(p1.first>=p2.first)
    return true;
    else 
    return false;
}
void solution()
{
  int n;cin>>n;
  int m;cin>>m;
  unordered_map<int,bool> special;
  for(int i=0;i<n;i++)
    {
        int in; cin>>in;
        special[in]=true;
    }
    vector<pair<int,string>> sFriend;
    vector<pair<int,string>> nFriend;
    for(int i=0;i<m;i++)
    {
        int f,p;
        string s;
        cin>>f>>p>>s;
        if(special[f])
        {
            pair<int,string> p1(p,s);
            sFriend.push_back(p1);
        }
        else 
        {
            pair<int,string> p1(p,s);
            nFriend.push_back(p1);
        }
    }
    sort(sFriend.begin(),sFriend.end(),comp);
    sort(nFriend.begin(),nFriend.end(),comp);
    for(int i=0;i<sFriend.size();i++)
    {
        pair<int,string>p=sFriend[i];
        cout<<p.second<<endl;
    }
    for(int i=0;i<nFriend.size();i++)
    {
        pair<int,string>p=nFriend[i];
        cout<<p.second<<endl;
    }
  
  
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
