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
	pair<int,int> path(TreeNode *root){
		//base case
		if(root == NULL){
			return {0, INT_MIN};
		}
		//recursive case
		pair<int,int> p;
		auto left = path(root->left);
		auto right = path(root->right);
		int d = root->val;
		int msrn = max(left.second, max(right.second, d));
		p.second = msrn;
		if(left.first + d < 0 && right.first + d < 0){
			p.first = 0;
			return p;
		}
		if(left.first + d + right.first > msrn){
			p.second = left.first + d + right.first;
		}
		p.first = d + max(left.first, right.first);
		return p;
	}
    int maxPathSum(TreeNode* root) {
        return path(root).second;
    }
};