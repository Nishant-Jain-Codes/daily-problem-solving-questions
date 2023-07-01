//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Node{
private:
    Node* links[2];
public:
    Node(){
        links[0] = NULL;
        links[1] = NULL;
    }
    bool containsBit(int bit){
        return links[bit]!=NULL;
    }
    void put(int bit,Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }
    void insert(int no){
        Node* curr = root;
        for(int i=31;i>=0;i--){
            int bit = (no>>i)&1;
            if(!curr->containsBit(bit)){
                curr->put(bit,new Node());
            }
            curr = curr->get(bit);
        }
    }
    int findMaxXor(int num){
        Node* curr = root;
        int maxXor = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(curr->containsBit(1-bit)){
                maxXor += (1<<i);
                curr = curr->get(1-bit);
            }
            else{
                curr = curr->get(bit);
            }
        }
        return maxXor;
    }
};
class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        //code here
        Trie trie;
        for(int i = 0;i<n;i++)
            trie.insert(arr[i]);
        int maxXor = 0;
        for(int i = 0;i<n;i++)
            maxXor = max(maxXor,trie.findMaxXor(arr[i]));
        return maxXor;
    }
    
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}



// } Driver Code Ends