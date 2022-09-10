#include<string>


class TrieNode{
    public: 
    char data;
    TrieNode **children = new TrieNode* [26];
    bool isTerminal;
    TrieNode(char data)
    {
        tihs->data=data;
        children = new TrieNode*[26];
        for(auto i:children)
            children[i]=NULL;
        isTerminal = false;
    }
    
};

class Trie{
    TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode('\0');
    }
private:
    void insertWord(TrieNode *root,string word)
    {
        if(word.size()==0)
        {
            root->isTerminal=true;
            return ; 
        }
        TrieNode * child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL)
        {
            child = root ->child[index];
        }
        else 
        {
            child = new TrieNode(word[0]);
            root->children[index]=child;
        }

        insertWord(child,word.substr(1));
    }

    bool search(TrieNode* root,string word)
    {	if(root==NULL)
        	return false;
     
        if(word.size()==0)
            return root->isTerminal;
        int index = word[0]-'a';
        
        if(root->children[index]==NULL)
            return false;
        else 
        	return search(root->children[index],word.substr(1));    
    }

  void remove(TrieNode* root,string word)
    {
        if(root==NULL)
            return ;
        if(word.size()==0)
            {
              root->isTerminal=false;
              return;
            }
        int index = word[0]-'a';
        if(root->children[index]==NULL)
            return ;
        else 
        {    
            remove(root->children[index],word.substr(1));
            if((root->children[index]->isTerminal==false))
            {
                for(int i=0;i<26;i++)
                {
                    if(root->children[index]->children[i]!=NULL)
                        return ;   
                }
                delete root->children[index];
                root->children[index]=NULL;
            }
        }
    }

    public:
    void insertWord(string word)
    {
        insertWord(root,word);
    }
  
    
    bool search(string word) {
        // Write your code here
        return search(root,word);
    }
    
  
    void remove(string word)
    {
        remove(root,word);
    }
};
