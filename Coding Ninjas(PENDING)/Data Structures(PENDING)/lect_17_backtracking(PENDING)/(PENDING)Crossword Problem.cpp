/*

Coding Ninjas has provided you a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Constraints
The number of words in the word list lie in the range of: [1,6]
The length of words in the word list lie in the range: [1, 10]
Time Limit: 1 second
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA

*/


//solution 
#include <bits/stdc++.h>
using namespace std;
char crossWord[10][10];
void printCrossWord() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << crossWord[i][j];
    }
    cout << endl;
  }
}
bool possibleHorizontally(string word, int i, int j) {
  if (j - 1 >= 0 && crossWord[i][j - 1] != '+')
    return false;
  else if (j + word.length() < 10 && crossWord[i][j + word.length()] != '+')
    return false;
  for (int jj = 0; jj < word.length(); jj++) {
    if (crossWord[i][j + jj] == '-' || crossWord[i][j + jj] == word[jj])
      continue;
    else
      return false;
  }
  return true;
}
bool possibleVertically(string word, int i, int j) {
  if (i - 1 >= 0 && crossWord[i - 1][j] != '+')
    return false;
  else if (i + word.length() < 10 && crossWord[i + word.length()][j] != '+')
    return false;
  for (int ii = 0; ii < word.length(); ii++) {
    if (crossWord[i + ii][j] == '-' || crossWord[i + ii][j] == word[ii])
      continue;
    else
      return false;
  }
  return true;
}
bool *placeHorizontally(string word, int i, int j) {
  bool *placed = new bool[word.size()];
  for (int jj = 0; jj < word.size(); jj++) {
    if (crossWord[i][j + jj] == '-') {
      crossWord[i][j + jj] = word[jj];
      placed[jj] = true;
    } else
      placed[jj] = false;
  }
  return placed;
}
bool *placeVertically(string word, int i, int j) {
  bool *placed = new bool[word.size()];
  for (int ii = 0; ii < word.size(); ii++) {
    if (crossWord[i + ii][j] == '-') {
      crossWord[i + ii][j] = word[ii];
      placed[ii] = true;
    } else
      placed[ii] = false;
  }
  return placed;
}
void unPlaceHorizontally(bool *placed, string word, int i, int j) {
  for (int jj = 0; jj < word.size(); jj++) {
    if (placed[jj]) {
      crossWord[i][j + jj] = '-';
    }
  }
}
void unPlaceVertically(bool *placed, string word, int i, int j) {
  for (int ii = 0; ii < word.size(); ii++) {
    if (placed[ii]) {
      crossWord[i + ii][j] = '-';
    }
  }
}
void solver(vector<string> words, int idx) {
  if (idx == words.size()) {
    printCrossWord();
    return;
  }
  string w = words[idx];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (crossWord[i][j] == '-' || crossWord[i][j] == w[0]) {
        if (possibleHorizontally(w, i, j)) {
          bool *placed = placeHorizontally(w, i, j);
          solver(words, idx + 1);
          unPlaceHorizontally(placed, w, i, j);
          delete[] placed;
        }
        if (possibleVertically(w, i, j)) {
          bool *placed = placeVertically(w, i, j);
          solver(words, idx + 1);
          unPlaceVertically(placed, w, i, j);
          delete[] placed;
        }
      }
    }
  }
}

int main() {

  // write your code here

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> crossWord[i][j];
    }
  }
  string in;
  cin >> in;
  vector<string> words;
  string w = "";
  for (int i = 0; i < in.length(); i++) {
    if (in[i] == ';') {
      words.push_back(w);
      w = "";
    } else {
      w.push_back(in[i]);
    }
  }
  words.push_back(w);
  solver(words, 0);
  return 0;
}