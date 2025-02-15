/*
437. Path Sum III

Medium
Topics
Companies
Given the root of a binary tree and an integer targetSum, return the number of paths where the sum of the values along the path equals targetSum.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

 

Example 1:


Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
Example 2:

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
 

Constraints:

The number of nodes in the tree is in the range [0, 1000].
-109 <= Node.val <= 109
-1000 <= targetSum <= 1000

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
    void pathSumHelper(TreeNode* root, int targetSum, long runningSum, unordered_map<long, int>& prefixSums, int& count) {
        if (!root) return;
        runningSum += root->val;
        count += prefixSums[runningSum - targetSum];
        prefixSums[runningSum]++;
        pathSumHelper(root->left, targetSum, runningSum, prefixSums, count);
        pathSumHelper(root->right, targetSum, runningSum, prefixSums, count);
        prefixSums[runningSum]--;
    }
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long, int> prefixSums;
        int count = 0;
        prefixSums[0] = 1;
        pathSumHelper(root, targetSum, 0, prefixSums, count);
        return count;
    }
    void pathSumHelper1(TreeNode* root, int targetSum, vector<long>& pathsums, int& count) {
        if (!root) return;
        int v = root->val;
        pathsums.push_back(0);
        for(long& n: pathsums) { 
            n += v; 
            if (n == targetSum) count++; 
        }
        pathSumHelper1(root->left, targetSum, pathsums, count);
        pathSumHelper1(root->right, targetSum, pathsums, count);
        for(long& n: pathsums) { n -= v;}
        pathsums.pop_back();
    }
    int pathSum1(TreeNode* root, int targetSum) {
        vector<long> pathsums;
        int count = 0;
        pathSumHelper1(root, targetSum, pathsums, count);
        return count;
    }
};