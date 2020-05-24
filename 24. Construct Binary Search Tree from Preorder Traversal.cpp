/*

Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.  Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

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
    
    TreeNode* newNode(int x)
    {
        TreeNode *node = new TreeNode();
        node->val = x;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    
    TreeNode* bst(TreeNode* &root, int x)
    {
        if(root == NULL)
            return root = newNode(x);
        
        if(root->val > x)
            root->left = bst(root->left,x);
        else
            root->right = bst(root->right,x);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) 
    {
        TreeNode *root = NULL;
        
        for(auto &x:preorder)
            bst(root, x);
        
        return root;
    }
};
