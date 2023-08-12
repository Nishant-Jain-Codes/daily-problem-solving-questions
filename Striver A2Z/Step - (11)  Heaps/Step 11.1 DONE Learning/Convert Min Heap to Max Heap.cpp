//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void convertMinToMaxHeap(vector<int> &arr, int N)
    {
        for(int i = N-1; i >= 0; i--)
            heapify(arr, N, i);
    }
private:    
    void heapify(vector<int>& arr, int N , int idx){
        int largest = idx;
        int leftChild = 2 * idx + 1;
        int rightChild = 2 * idx + 2;
        if(leftChild < N && arr[leftChild] > arr[largest])
            largest = leftChild;
        if(rightChild < N && arr[rightChild] > arr[largest])
            largest = rightChild;
        if(largest != idx){
            swap(arr[idx], arr[largest]);
            heapify(arr, N, largest);
        }
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends