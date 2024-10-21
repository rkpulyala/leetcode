/*
199. Binary Tree Right Side View

Medium
Topics
Companies
Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:


Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Example 2:

Input: root = [1,null,3]
Output: [1,3]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

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

view[] = {1, 3, 4}


 */
class Solution {
public:
    void dfs(TreeNode* node, int level, vector<int>& view) {
        if (!node) return;
        if (view.size() <= level) view.push_back(node->val);
        //else view[level] = node->val;
        dfs(node->right, level + 1, view);
        dfs(node->left, level + 1, view);
        
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        dfs(root, 0, view);
        return view;
    }
};