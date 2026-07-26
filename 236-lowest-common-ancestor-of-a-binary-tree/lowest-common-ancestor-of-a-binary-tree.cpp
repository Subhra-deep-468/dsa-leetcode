/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root,
                                   TreeNode* p,
                                   TreeNode* q)
    {
        // If the tree is empty, return NULL.
        if (root == NULL)
            return NULL;

        // If the current node is p or q, return it.
        if (root == p || root == q)
            return root;

        // Search in the left subtree.
        TreeNode* left = lowestCommonAncestor(root->left, p, q);

        // Search in the right subtree.
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        // If both left and right are non-NULL,
        // then p and q are in different subtrees.
        // So, the current root is the LCA.
        if (left != NULL && right != NULL)
            return root;

        // If only the left subtree contains p or q,
        // return the node found in the left subtree.
        if (left != NULL)
            return left;

        // Otherwise, return the node found in the right subtree
        // or NULL if neither node exists there.
        return right;
    }
};