// https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=median-in-a-row-wise-sorted-matrix


//Initial template for C++
#include <bits/stdc++.h>
using namespace std;

//User function template for C++
class Solution{   
public:
    // Function to check if the given value could be the median of the matrix
    int canBeMid(vector<vector<int>> &matrix, int R, int C, int val) {
        int cnt = 0;
        for (int i = 0; i < R; i++) {
            // For each row of the matrix, find the number of elements less than or equal to val
            vector<int> &vec = matrix[i];
            cnt += (upper_bound(vec.begin(), vec.end(), val) - vec.begin());
        }
        // If cnt is less than or equal to half of the total number of elements in the matrix, then val can be the median
        return cnt <= ((R * C) / 2);
    }

    // Function to find the median of the matrix
    int median(vector<vector<int>> &matrix, int R, int C) {
        int lo = 1; // initialize the lower bound to 1
        int hi = 1e9; // initialize the upper bound to a large value
        while (lo <= hi) { // repeat the loop until lower bound becomes greater than upper bound
            int mid = (hi + lo) / 2; // calculate the middle value of the range
            if (canBeMid(matrix, R, C, mid)) { // check if the middle value could be the median
                lo = mid + 1; // if yes, update the lower bound to mid + 1
            } else {
                hi = mid - 1; // if no, update the upper bound to mid - 1
            }
        }
        return lo - 1 ; // return the final value of the lower bound (which is now greater than the upper bound) minus 1 to get the median value
    }
};

//Main function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
