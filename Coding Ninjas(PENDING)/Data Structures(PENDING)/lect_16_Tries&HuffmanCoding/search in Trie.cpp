/*


Implement the function SearchWord for the Trie class.
For a Trie, write the function for searching a word. Return true if the word is found successfully, otherwise return false.
*/

// solution

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
