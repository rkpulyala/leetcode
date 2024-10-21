/**
 236. Lowest Common Ancestor of a Binary Tree

Medium
Topics
Companies
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
Example 3:

Input: root = [1,2], p = 1, q = 2
Output: 1
 

Constraints:

The number of nodes in the tree is in the range [2, 105].
-109 <= Node.val <= 109
All Node.val are unique.
p != q
p and q will exist in the tree.
 */

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
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     if (!root) return nullptr;
    //     p = p == root? nullptr : p;
    //     q = q == root? nullptr : q;
    //     if (!p && !q) return root;
    //     TreeNode* l = lowestCommonAncestor(root->left, p, q);
    //     return l ? l : lowestCommonAncestor(root->right, p, q);
    // }

    struct Result {
        TreeNode* lca;
        bool foundP;
        bool foundQ;
    };

    Result lca_helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        Result r{nullptr, root == p, root == q};
        if (!root) return r;
        
        Result lr = lca_helper(root->left, p, q);
        if (lr.lca) return lr;
        
        Result rr = lca_helper(root->right, p, q);
        if (rr.lca) return rr;

        r.foundP = r.foundP || lr.foundP || rr.foundP;
        r.foundQ = r.foundQ || lr.foundQ || rr.foundQ;

        if (r.foundP && r.foundQ) r.lca = root;
        return r;
    }



    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        Result r =  lca_helper(root, p, q);
        return r.lca;
    }
};