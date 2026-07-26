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
    // Both nodes are in the left subtree.
    if (p->val < root->val && q->val < root->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    // Both nodes are in the right subtree.
    if (p->val > root->val && q->val > root->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    // Current root is the LCA.
    return root;
}

};