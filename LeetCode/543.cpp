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
	pair<int,int> func(TreeNode *root){
		//base case
		if(root == NULL){
			return {0, 0};
		}
		//recursive case
		auto left = func(root->left);
		auto right = func(root->right);
		pair<int,int> p;
		p.first = 1 + max(left.first, right.first);
		p.second = left.first + right.first;
		p.second = max(p.second, max(left.second, right.second));
		return p;
	}
    int diameterOfBinaryTree(TreeNode* root) {
        return func(root).second;
    }
};