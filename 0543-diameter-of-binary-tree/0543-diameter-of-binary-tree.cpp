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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
    private:
    int height(TreeNode* Node,int& diameter)
    {
        if(!Node)
        return 0;
        int lh=height(Node->left,diameter);
        int rh=height(Node->right,diameter);
        diameter = max(diameter, lh + rh);
        return 1 + max(lh, rh);
    }
};