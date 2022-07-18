/*

Second Largest Element In Tree
Send Feedback
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40

*/

// solution 

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
class helper{
    public:
  	TreeNode<int>* max;
  	TreeNode<int>* Smax;
    helper(TreeNode<int>*max,TreeNode<int>*Smax)
    {
        this->max = max;
        this->Smax= Smax;
    }
    
};
helper helpfunc(TreeNode<int>* root)
{
    if(root==NULL)
    {
        helper ans(NULL,NULL);
        return ans;
    }
    helper ans(root,NULL);
    for (int i = 0; i < root->children.size(); i++)
    {
        helper child = helpfunc(root->children[i]);
        if(child.max->data>ans.max->data)
        {
            if(child.Smax==NULL)
            {
                ans.Smax=ans.max;
                ans.max=child.max;
            }
            else
            {
                if(child.Smax->data>ans.max->data)
                {
                    ans.max=child.max;
                    ans.Smax=child.Smax;
                }
                else   
                {
                    ans.Smax=ans.max;
                	ans.max=child.max;
                }
            }
        }
        else
        {
            if((ans.max->data!=child.max->data)&&(ans.Smax==NULL||child.max>ans.Smax))
            {
                ans.Smax=child.max;
            }
        }
    }
    return ans;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
    {
        return root;
    }
    helper ans = helpfunc(root);
    return ans.Smax;
}
