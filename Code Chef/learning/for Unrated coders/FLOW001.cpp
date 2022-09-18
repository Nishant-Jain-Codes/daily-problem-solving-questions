/*
https://www.codechef.com/LP0TO101/problems/FLOW001?tab=statement


Problem
Problem Statement
Every problem starts with a Problem Statement. It tells you in detail about the task to be solved.
Shivam is the youngest programmer in the world, he is just 12 years old. Shivam is learning programming and today he is writing his first program.

The task is very simple: given two integers A and B, write a program to add these two numbers and output it.

Input Format
This section tells you the format in which your program should receive the input.
The first line contains an integer T, the total number of test cases. Then follow T lines, each line contains two Integers A and B.

Output Format
This section tells us the format in which your program should give the output
For each test case, add A and B and display the sum in a new line.

Everything your program prints is considered “output”, so if you output some debugging statements like “Please enter T”, this will be considered as part of your answer, and because it does not satisfy the output format, it will be marked wrong, even if your answer is otherwise correct!
Constraints
This section tells you the maximum and minimum possible values the variables in the problem statement can take. You do not need to check these constraints in your program. You can safely assume that the input given to your program will be in the given range of constraints.

1 ≤ T ≤ 1000
0 ≤ A,B ≤ 10000
*/

// solution 

// You don't need to add/edit anything to the below solution. 
// Click on the SUBMIT button to solve your first problem on CodeChef.

// bits/stdc++.h works in linux. 
// It loads most of the libraries of C++ required.
#include <bits/stdc++.h> 

using namespace std;

int main() {
	// Read the number of test cases.
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		// Read the input a, b
		int a, b;
		cin >> a >> b;

		// Compute the ans.
		int ans = a + b;
		cout << ans << "\n";
	}

	return 0;
}
