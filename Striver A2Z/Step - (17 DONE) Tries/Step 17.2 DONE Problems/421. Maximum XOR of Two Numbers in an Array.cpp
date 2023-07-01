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
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(auto & num : nums)
            trie.insert(num);
        int maxXor = 0;
        for(auto & num : nums)
            maxXor = max(maxXor,trie.findMaxXor(num));
        return maxXor;
    }
};