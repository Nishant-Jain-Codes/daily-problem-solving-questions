/*
https://www.codechef.com/LP2TO302/problems/PTMSSNG?tab=statement


Chef has NN axis-parallel rectangles in a 2D Cartesian coordinate system. These rectangles may intersect, but it is guaranteed that all their 4N4N vertices are pairwise distinct.

Unfortunately, Chef lost one vertex, and up until now, none of his fixes have worked (although putting an image of a point on a milk carton might not have been the greatest idea after all...). Therefore, he gave you the task of finding it! You are given the remaining 4N-14N−1 points and you should find the missing one.

Input
The first line of the input contains a single integer TT denoting the number of test cases. The description of TT test cases follows.
The first line of each test case contains a single integer NN.
Then, 4N-14N−1 lines follow. Each of these lines contains two space-separated integers xx and yy denoting a vertex (x, y)(x,y) of some rectangle.
Output
For each test case, print a single line containing two space-separated integers XX and YY ― the coordinates of the missing point. It can be proved that the missing point can be determined uniquely.

Constraints
T \le 100T≤100
1 \le N \le 2 \cdot 10^51≤N≤2⋅10 
5
 
|x|, |y| \le 10^9∣x∣,∣y∣≤10 
9
 
the sum of NN over all test cases does not exceed 2 \cdot 10^52⋅10 
5
 
Subtasks
Subtask #1 (20 points):

T = 5T=5
N \le 20N≤20
Subtask #2 (30 points): |x|, |y| \le 10^5∣x∣,∣y∣≤10 
5
 

Subtask #3 (50 points): original constraints

Sample 1:
Input
Output
1
2
1 1
1 2
4 6
2 1
9 6
9 3
4 3
2 2
Explanation:
The original set of points are:
![fig1](https://i.imgur.com/7oHoe86.png =333x211)

Upon adding the missing point (2, 2)(2,2), N = 2N=2 rectangles can be formed:
![fig1](https://i.imgur.com/N8ceCw0.png =333x211)
*/

// solution 


// CODE STARTS HERE-------------------------------------------------------------------------------------------
// space complexity : O(n)
// time complexity :  O(nlogn)
void solution()
{
  int n;cin>>n;
  int x[(4*n)-1],y[(4*n)-1];
  for(int i=0;i<(4*n)-1;i++)
  { int X,Y;
      cin>>X>>Y;
      x[i]=X;
      y[i]=Y;
  }
  sort(x,x+(4*n)-1);
  sort(y,y+(4*n)-1);
  int Xcor=-1;
  int Ycor=-1;
  for(int i=0;i<((4*n)-1)-1;i+=2)
  {
      if(x[i]!=x[i+1])
      {
          Xcor=x[i];
          break;
      }
  }
    if(Xcor==-1)
    Xcor=x[((4*n)-1)-1];
for(int i=0;i<((4*n)-1)-1;i+=2)
  {
      if(y[i]!=y[i+1])
      {
          Ycor=y[i];
          break;
      }
  }
    if(Ycor==-1)
    Ycor=y[((4*n)-1)-1];
  
  cout<<Xcor<<" "<<Ycor<<endl;
  
}
//CODE ENDS HERE----------------------------------------------------------------------------------------------
