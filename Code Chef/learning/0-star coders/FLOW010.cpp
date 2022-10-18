/*
https://www.codechef.com/LP0TO101/problems/FLOW010

Problem
Write a program that takes in a letterclass ID of a ship and display the equivalent string class description of the given ID. Use the table below.

Class ID	Ship Class
B or b	BattleShip
C or c	Cruiser
D or d	Destroyer
F or f	Frigate
Input
The first line contains an integer T, the total number of testcases. Then T lines follow, each line contains a character.

Output
For each test case, display the Ship Class depending on ID, in a new line.

Constraints
1 ≤ T ≤ 1000
Example
Input
3
B
c
D


Output
BattleShip
Cruiser
Destroyer
*/

// sollution 

void solution()
{
  char c;cin>>c;
  if(c=='b'||c=='B')
  {
      co("BattleShip");
  }
  else if(c=='c'||c=='C')
  {
      co("Cruiser");
  }
  else if(c=='d'||c=='D')
  {
      co("Destroyer");
  }
  else 
  {
      co("Frigate");
  }
  
  
  
}
