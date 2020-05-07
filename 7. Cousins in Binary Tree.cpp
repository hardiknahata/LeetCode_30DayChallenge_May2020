/*

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    //n finding node ; h current depth ; d depth of finding node
    TreeNode* depth(TreeNode* root, int& n, int h, int& d )
    {
        if(root==NULL) return NULL;
        
        //left children
        if(root->left && root->left->val==n)
        {
            d=h+1;
            return root;
        }
        //right children
        if(root->right && root->right->val==n)
        {
            d=h+1;
            return root;
        }
        
        //if not found, move down the tree
        TreeNode* l = depth(root->left,n,h+1,d);
        if(l) return l;
        TreeNode* r = depth(root->right,n,h+1,d);
        if(r) return r;
        
    return NULL;
    }
    
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        int xDepth=-1, yDepth=-1;
        TreeNode* xParent = depth(root,x,0,xDepth);
        TreeNode* yParent = depth(root,y,0,yDepth);
        
        if(xParent!=yParent && xDepth==yDepth)
            return true;
        else
            return false;
    }
};
