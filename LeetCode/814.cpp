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
	pair<TreeNode*, bool> func(TreeNode* root){
        //base case
        if(root == nullptr){
        	return {nullptr, 0};
        }
        //recursive case
        auto left = func(root->left);
        auto right = func(root->right);

        if(!left.second && !right.second && root->val==0){
        	return {nullptr, 0};
        }
        root->left = left.first;
        root->right = right.first;
        return {root, 1};
	}
    TreeNode* pruneTree(TreeNode* root) {
    	root = func(root).first;
    	return root;
    }
};