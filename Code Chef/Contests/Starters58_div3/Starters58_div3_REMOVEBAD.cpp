/*

https://www.codechef.com/START58C/problems/REMOVEBAD

*/

 // CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(n)
void solution()
{
  int n;cin>>n;
  unordered_map<int,int> map;
  for(int i=0;i<n;i++)
  {
      int in;cin>>in;
      map[in]++;
  }
  int m=0;
  for(auto x:map)
  {
      m = max(m,x.second);
  }
    
  co(n-m);
  
  
}
