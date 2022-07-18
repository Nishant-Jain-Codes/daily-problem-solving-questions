/*

Remove leaf nodes in Tree
Send Feedback
Remove all leaf nodes from a given generic Tree. Leaf nodes are those nodes, which don't have any children.
Note : Root will also be a leaf node if it doesn't have any child. You don't need to print the tree, just remove all leaf nodes and return the updated root.
Input format :
Line 1 : Elements in level order form separated by space (as per done in class). Order is - `

Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element `
Output Format :
Elements are printed level wise, each level in new line (separated by space)
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 : (Level wise, each level in new line)
10
20

*/

// solution 

// Following is the given Tree node structure.
/**************
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
    void removeChild(int index);
 
};
***************/
TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
    // Write your code here
         if(root==NULL){
         return NULL;
     }
    if(root->numChildren()==0){
        delete root;
        return NULL;
    }
    for(int i=0;i<root->numChildren();i++){
        TreeNode<int>*child=root->getChild(i);
         if(child->numChildren()==0){
              root->removeChild(i);
             i--;
          }else{
             root->setChild(i,removeLeafNodes(child));
         }
    }
   
    return root;

}
