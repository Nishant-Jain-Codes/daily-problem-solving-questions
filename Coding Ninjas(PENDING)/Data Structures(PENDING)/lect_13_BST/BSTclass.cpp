/*

Code: BST Class
Send Feedback
Implement the BST class which includes following functions -
1. search
Given an element, find if that is present in BST or not. Return true or false.
2. insert -
Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
3. delete -
Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
4. printTree (recursive) -
Print the BST in ithe following format -
For printing a node with data N, you need to follow the exact format -
N:L:x,R:y
where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
There is no space in between.
You need to print all nodes in the recursive format in different lines.
*/

// solution 
/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/

class BST {
    // Define the data members
    BinaryTreeNode<int>* root;
   	public:
    BST() { 
        // Implement the Constructor
        root = NULL;
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        // Implement the remove() function 
        BinaryTreeNode<int>* ans = deleteData(data,root);
        this->root = ans;
    }

    void print() { 
        // Implement the print() function
       print(root);
        
    }

    void insert(int data) { 
        // Implement the insert() function 
        BinaryTreeNode<int>* ans = insert(data,root);
        this->root=ans;
    }

    bool search(int data) {
		// Implement the search() function 
        return hasData(data,root);
    }
    private:
    
   
    BinaryTreeNode<int>* deleteData(int data,BinaryTreeNode<int>* node)
    {
            if(node==NULL)
            {
                return NULL;
            }
            if(node->data>data)
            {
                node->left = deleteData(data,node->left);
                return node;
            }
            else if(node->data<data)
            {
                node->right = deleteData(data,node->right);
                return node;
            }
            else
            {
                if(node->left==NULL&&node->right==NULL)
                {
                    delete node;
                    return NULL;
                }
                else if(node->left==NULL&&node->right!=NULL)
                {
                    BinaryTreeNode<int>* tempvar = node->right;
                    node->right=NULL;
                    delete node;
                    return tempvar;
                }
                else if(node->left!=NULL&&node->right==NULL)
                {
                    BinaryTreeNode<int>* tempvar = node->left;
                    node->left=NULL;
                    delete node;
                    return tempvar;
                }
                else
                {   BinaryTreeNode<int>* minNode = node->right;
                    while(minNode->left!=NULL)
                    {
                        minNode=minNode->left;
                    }
                    
                    node->data= minNode->data;
                    node->right = deleteData(minNode->data,node->right);
                    return node;
                }
            }
    }
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* node)
    {
        if(node==NULL)
        {
            BinaryTreeNode<int>* newnode = new BinaryTreeNode<int>(data);
            return newnode;
        }
        if(node->data>=data)
        {
            node->left = insert(data,node->left);
            return node;
        }
        else
        {
            node->right = insert(data,node->right);
            return node;
        }
    }

    bool hasData(int data, BinaryTreeNode<int>* node)
    {
        if(node == NULL)
        {
            return false;
        }
        if(node->data==data)
        {
            return true;
        }
        else if(node->data>data)
        {
            return hasData(data,node->left);
        }
        else
        {
            return hasData(data,node->right);
        }
    }
    void print(BinaryTreeNode<int>* node)
    {
          if(node==NULL)
    {
        return;
    }
    cout<<node->data<<":";
    if(node->left!=NULL)
    {
        cout<<"L:"<<node->left->data<<",";
    }
    
    if(node->right!=NULL)
    {
        cout<<"R:"<<node->right->data;
    }
    cout<<endl;
    print(node->left);
    print(node->right);
        
    }
};
