/*
Problem Statement
Take two numbers as input and swap them and print the swapped values.
Input Format:
The first line of input contains a single integer 't', representing the total number of test cases.

The second line of input contains two integers 'a' and 'b', representing the second number. 
Output Format:
The first line of output prints the swapped value of 'a' and 'b'.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function.
Constraints:
1 <= 'T' <= 10^2
-10^5 <= 'a', 'b' <= 10 ^ 5

Time Limit: 1 sec
Sample Input 1:
2
1 2 
3 4
Sample Output 1:
2 1
4 3
Explanation For Sample Input 1:
The output of the above test case is 2 1 for the first test case.
The output of the 2nd test case is 4 3.
Sample Input 2:
2
5 6
7 8
Sample Output 2:
6 5
8 7
Explanation For Sample Input 2:
The output of the above test case is  6 5 for the first test case.
The output of the 2nd test case is 8 7.
*/

// solution 
#include <utility>

pair < int, int > swap(pair < int, int > swapValues) {
    // Write your code here.
    
    return {swapValues.second,swapValues.first};
}
