/*
Problem
In the current semester, you have taken XX RTP courses, YY Audit courses and ZZ Non-RTP courses.

The credit distribution for the courses are:

44 credits for clearing each RTP course.
22 credits for clearing each Audit course.
No credits for clearing a Non-RTP course.
Assuming that you cleared all your courses, report the number of credits you obtain this semester.

Input Format
The first line contains a single integer TT, the number of test cases. TT test cases follow. Each test case consists of one line, containing 33 integers separated by spaces.

The first integer is XX, the number of RTP courses.
The second integer is YY, the number of Audit courses.
The third integer is ZZ, the number of non-RTP courses.
Output Format
The output must consist of TT lines. The i^{th}i 
th
  should consist of a single integer: the number of credits one gets for the i^{th}i 
th
  test case.

Constraints
1 \le T \le 101≤T≤10
1 \le X, Y, Z \le 101≤X,Y,Z≤10
Sample 1:
Input
Output
4
6 6 5
8 7 2
9 3 8
9 2 4
36
46
42
40
Explanation:
Test case 11: You obtain 44 credits for each of the RTP courses, accounting for 4 \cdot 6 = 244⋅6=24 credits. You also obtain 22 credits for each audit course, accounting for 2 \cdot 6 = 122⋅6=12 credits. Finally, you get 00 credits for each of the non-RTP courses, accounting for 0 \cdot 5 = 00⋅5=0 credits. This accounts for a total of 24 + 12 + 0 = 3624+12+0=36 credits.

Test case 22: You obtain 44 credits for each of the RTP courses, accounting for 4 \cdot 8 = 324⋅8=32 credits. You also obtain 22 credits for each audit course, accounting for 2 \cdot 7 = 142⋅7=14 credits. Finally, you get 00 credits for each of the non-RTP courses, accounting for 0 \cdot 2 = 00⋅2=0 credits. This accounts for a total of 32 + 14 + 0 = 4632+14+0=46 credits.

Test case 33: You obtain 44 credits for each of the RTP courses, accounting for 4 \cdot 9 = 364⋅9=36 credits. You also obtain 22 credits for each audit course, accounting for 2 \cdot 3 = 62⋅3=6 credits. Finally, you get 00 credits for each of the non-RTP courses, accounting for 0 \cdot 8 = 00⋅8=0 credits. This accounts for a total of 36 + 6 + 0 = 4236+6+0=42 credits.

Test case 44: You obtain 44 credits for each of the RTP courses, accounting for 4 \cdot 9 = 364⋅9=36 credits. You also obtain 22 credits for each audit course, accounting for 2 \cdot 2 = 42⋅2=4 credits. Finally, you get 00 credits for each of the non-RTP courses, accounting for 0 \cdot 4 = 00⋅4=0 credits. This accounts for a total of 36 + 4 + 0 = 4036+4+0=40 credits.
*/

// solution 

void solution()
{
    int x;cin>>x;
    
    int y;cin>>y;
    int z;cin>>z;
    co((x*4)+(y*2));
}
