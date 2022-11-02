/*

https://www.codechef.com/LP2TO302/problems/JAVELIN

*/

// solution 



// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(nlogn)
bool comp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.first>p2.first)
        return true;    
    else 
        return false;
}

void solution()
{
 int n,m,x;
 cin>>n>>m>>x;
 vector<pair<int,int>> vec;//<val,pos>
 for(int i=1;i<=n;i++)
 {
     int in;
     cin>>in;
     pair<int,int> p(in,i);
     vec.push_back(p);
 }
    sort(vec.begin(),vec.end(),comp);
  int sel=0;
  int i=0;
  vector<int> selArr;
  for(;i<vec.size();i++)
  {     pair<int,int> p=vec[i];
      if(p.first>=m)
      {
        selArr.push_back(p.second);
        sel++;
      }
      else 
      break;
  }
  while(sel<x)
  {
   pair<int,int> p=vec[i]; 
   selArr.push_back(p.second);
    sel++;
    i++;
  }
  sort(selArr.begin(),selArr.end());
  cout<<sel<<" ";
  for(int i=0;i<sel;i++)
  {
      cout<<selArr[i]<<" ";
  }
  cout<<endl;
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
