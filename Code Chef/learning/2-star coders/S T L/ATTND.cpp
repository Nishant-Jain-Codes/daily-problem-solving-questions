/*

https://www.codechef.com/LP2TO304/problems/ATTND

*/

// solution 



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  int n;cin>>n;
  vector<pair<string,string>> vec;
  for(int i=0;i<n;i++)
  {
      string first,second;
      cin>>first>>second;
      pair<string,string>p({first,second});
      vec.push_back(p);
  }
    unordered_map<string,int> map;
    for(int i=0;i<n;i++)
    {
        string check=vec[i].first;
        map[check]++;
    }
  
    for(int i=0;i<n;i++)
    {
        string first=vec[i].first;
        string second=vec[i].second;
        if(map[first]>1)
        {
            cout<<first<<" "<<second<<endl;
        }
        else 
        {
            co(first);
        }
    }
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
