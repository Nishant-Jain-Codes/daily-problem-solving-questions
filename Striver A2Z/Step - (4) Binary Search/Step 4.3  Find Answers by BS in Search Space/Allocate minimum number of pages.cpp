// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=allocate-minimum-number-of-pages

//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int pages[] ,int books , int students , int cap){
        int studentsAllocated = 1;
        int curPagesAllocated = 0;

    for (int i = 0; i < books; i++) {
        if (pages[i] > cap)
            return false;

        if (curPagesAllocated + pages[i] > cap) {
            studentsAllocated++;
            curPagesAllocated = pages[i];
        } else {
            curPagesAllocated += pages[i];
        }

        if (studentsAllocated > students)
            return false;
    }

    return true;
    }
    int findPages(int pages[], int books, int students) 
    {
    
    if(books<students)
        return -1;
        int lo = 0;
        int hi = 0;
    for (int i = 0; i < books; i++) {
        lo = max(lo, pages[i]);
        hi += pages[i];
    }

    int ans = -1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (isPossible(pages, books, students, mid)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends