/*
// link 
https://codingcompetitions.withgoogle.com/kickstart/round/00000000008f49d7/0000000000bcee64#problem

*/

void solution()
{
  int n;cin>>n;
  int m;cin>>m;
  int sum=0;
  for(int i =0;i<n;i++)
  {
      int c;
      cin>>c;
      sum+=c;
  }
  cout<<sum%m<<endl;
}
